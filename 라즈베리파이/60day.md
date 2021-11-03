- 자이로스코프 센서(MPU 6050)
  - <img src= "https://user-images.githubusercontent.com/49339278/139969084-3f337132-6963-4332-aa1f-1e3200e3d8d5.png" width="400" height="400"/>
  - ![image](https://user-images.githubusercontent.com/49339278/139969134-ddacfb88-52a7-438d-8333-60bc47377e9c.png)
  - 자이로스코프 혹은 자이로 : 운동을 측정하는 장치 혹은 유지하는 장비이다. 각속도를 측정하는 용도로 사용한다. (단위는 ˚/s 혹은 RPS)
  - 중력 : 물체에 대해서 수직으로 영향을 미친다. => 고정되어 있는 물체라고 한다면, x와 y는 0이 된다.
  - 중력가속도 = 9.80665m/s^2
  - 센서의 정밀도는 보장할 수 없지만, 가속도를 활용하여 이동거리를 측정할 수 있다.
  - Vcc : 1번(3.3v)
  - GND : 6번
  - SCL : 5번(전용)
  - SDA : 3번(전용)
  - ```$ i2cdetect -y 1``` 입력해서 68번으로 연결된 것을 확인했다면 센서 연결 완료!
  - MPU 6050으로 들어올 수 있는 데이터는 총 7가지이다.
    - 각속도 : x, y, z
    - 가속도 : x', y', z'(중력가속도 이용)
    - 온도

-------
- 이미지 사이즈 조절 없이 올리는 경우 : ```![image](이미지주소.png)```
- 이미지 사이즈 조절해서 올리는 경우 : ```<img src="이미지주소.png" width = 200" height = "400"/>```
-------
- Register Address
```c
#define PWR_MGMT_1    0x6B
#define SMPLRT_DIV    0x19
#define CONFIG        0x1A
#define GYRO_CONFIG   0x1B
#define INT_ENABLE    0x38
#define ACCEL_XOUT_H  0x3B
#define ACCEL_YOUT_H  0x3D
#define ACCEL_ZOUT_H  0x3F
#define GYRO_XOUT_H   0x43
#define GYRO_YOUT_H   0x45
#define GYRO_ZOUT_H   0x47
```
- XOUT, YOUT, ZOUT 끝에 H가 붙여져 있다.
- 그리고 주소가 2칸씩 떨어져 있다.
