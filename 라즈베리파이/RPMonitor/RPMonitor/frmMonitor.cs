using myLibrary;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace RPMonitor
{
    public partial class frmMonitor : Form
    {
        public frmMonitor()
        {
            InitializeComponent();
        }

        /// <summary>
        /// 폼을 시작할 때...
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void frmMonitor_Load(object sender, EventArgs e)
        {
            sqldb = new SqlDB(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=C:\Users\송연석\source\repos\RPDatabase.mdf;Integrated Security=True;Connect Timeout=30");
        }

        SqlDB sqldb;
        TcpClient tcp = null;
        TcpListener listen = null;
        Socket sock = null;
        Thread serverThread = null;
        Thread readThread = null;
        Thread clientReadThread = null;
        string connectIP = "192.168.2.60";
        int port = 9000;

        delegate void CB(string s);
        /// <summary>
        /// tbMemo에 텍스트 추가
        /// </summary>
        /// <param name="str"></param>
        void AddText(string str)
        {
            // tbMemo에 대해서 InvokeRequired값이 True이면, CB를 사용한다.
            if (tbMemo.InvokeRequired)
            {
                CB cb = new CB(AddText);
                object[] obj = { str };
                Invoke(cb, obj);
            }
            else
            {
                // invoke가 required되지 않으면
                tbMemo.Text += str;
            }
        }


        /// <summary>
        /// tbPortNum에 값을 입력하였다면, port 변수에 값을 대입한다.
        /// 그리고 listen에 port값을 입력하고 listen을 시작한다. 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnStart_Click(object sender, EventArgs e)
        {
            if (tbPortNum.Text != "") port = int.Parse(tbPortNum.Text);
            listen = new TcpListener(port);
            listen.Start();
            serverThread = new Thread(ServerProcess);
            serverThread.Start();
            readThread = new Thread(ReadProcess);
            readThread.Start();

            AddText("Server Started");
            btnStart.Enabled = false;       // 연결 후에 버튼을 비활성화시킴
        }
        
        /// <summary>
        /// 외부로부터 클라이언트 요청이 있을 때까지 돌아간다.
        /// Thread가 중지될 때까지 돌아간다.
        /// </summary>
        void ServerProcess()
        {
            while (true)
            {
                if (listen.Pending())   // 외부로부터 클라이언트 요청이 있는가? (O -> True, X -> False)
                {
                    tcp = listen.AcceptTcpClient();     // tcp는 클라이언트의 요청을 수락한다.
                    tcp.Client.Send(Encoding.Default.GetBytes("Hello"));    // 그 후에 Server가 client로 hello라는 글을 전송
                }
                Thread.Sleep(1000);     // 쉬어가기
            }
        }



        /// <summary>
        /// 데이터를 가져오는 과정
        /// </summary>
        void ReadProcess()
        {
            byte[] bArr = new byte[1024];
            int Count = 0;
            Count = int.Parse(sqldb.GetString("select max(id) from RPLog")) + 1;
            while(true)
            {
                if(tcp != null)
                {
                    NetworkStream ns = tcp.GetStream();
                    if(ns.DataAvailable)        // 읽어올 데이터가 있다면?
                    {
                        try
                        {
                            int n = ns.Read(bArr, 0, 1024);      // 읽어오기
                            if (n == 1 && bArr[0] == 0x1b)       // ESC이면(27 == 0x1b)
                            {
                                tcp.Close(); tcp = null; continue;   // 계속
                            }
                            if (bArr[n - 1] == '\r') tcp.Client.Send(Encoding.Default.GetBytes("ACK"));     // ACK
                            byte[] bArr2 = Encoding.Convert(Encoding.UTF8, Encoding.Default, bArr, 0, n);
                            string str = Encoding.Default.GetString(bArr2);
                            string[] sa = str.Split(',');
                            string sql = $"insert into RPLog values ({Count++}, '00001', {sa[0]}, {sa[1]}, {sa[2]}, {sa[3]}, {sa[4]}, {sa[5]}, {sa[6]}, {DateTime.Now})";
                            sqldb.Run(sql);     // sql 구문 수행
                            AddText(str + "\r\n");
                        }
                        catch(Exception e1)
                        {
                            MessageBox.Show(e1.Message);
                        }
                    }
                }
                Thread.Sleep(1000);
            }
        }

        private void frmMonitor_FormClosing(object sender, FormClosingEventArgs e)
        {
            CloseProcess();
        }

        /// <summary>
        /// 스레드 종료 함수
        /// </summary>
        void CloseProcess()
        {
            if (serverThread != null) serverThread.Abort();
            if (readThread != null) readThread.Abort();
        }
        /// <summary>
        /// ESC 키를 눌렀을 경우, Close 세션 종료
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void frmMonitor_KeyDown(object sender, KeyEventArgs e)      // key preview => true로 변경
        {
            if (e.KeyCode == Keys.Escape)
            {
                this.Close();
            }
        }


    }
}
