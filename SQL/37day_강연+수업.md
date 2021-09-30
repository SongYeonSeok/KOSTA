## 특강
- 강사님 : 박준성 협회장님

- 제목 : 글로벌 일류 SW 개발자가 되는 길
1. 글로벌 및 한국의 SW산업 이해
2. 글로벌 일류 SW개발자의 필수 역량
3. SW 분석과 설계
4. 테스트 주도 개발 (TDD)
5. 리팩토링
6. SW 설계의 원리

1. 글로벌 및 한국의 SW산업 이해
- SW는 미래의 최고 유망 산업이다.
	> IN SHORT, SOFTWARE IS EATING THE WORLD.
	- 일론 머스크도 한때는 소프트웨어 개발자였다. 지금은 테슬라 회장으로 여러 혁신들을 보여주며 전 세계를 놀라게 하고 있다.
	- Jeff Benzos 전 아마존 창업자도 소프트웨어 개발자였다.
- SW는 4차 산업혁명의 원동력이다.
	- "Smart, connected products substantially changes the work of virtually every function whithin the manufacturing firm. What is under way is perhaps the most substantial change in the manufacturing firm since the Second Industrial Revolution more than a century ago." - Michael Porter, Harvard University. 2015
	- "Every company has to be a software company." - Jeff Immelt, GE, 2015

- 한국은 IT강국이다. 하지만 한국의 SW은 강국이 아니다. 이는 SW 기본 역량이 갖춰지지 않았기 때문이다.
	- 현재 국내 기업의 4차 산업 혁명의 준비도는 OECD 회원국 중 하위권에 속해 있다.
	- ![image](https://user-images.githubusercontent.com/49339278/135187890-7467cd4f-015e-4e6f-b29f-f3aeabc31d0d.png)
	- 하지만 알아야 할 것이, 빅데이터, AI를 무조건 맹신할 필요는 없다. 잘 활용하면 좋은 것이긴 하지만, 유행에 의해 과대포장된 면도 있기 때문이다.

- 4차 산업혁명 준비도가 낮은 이유
	- 국가 산업 중 ICT 산업 차지 비율이 전 산업의 10% 이상으로, OECD 회원국의 1위를 차지하고 있다.
		- 그 중 ICT Manufacturing(반도체 등 제조)가 7~80%.(기형적인 산업구조)
		- 하지만 소프트웨어 산업(SI)의 비율이 다른 OECD 회원국과 비교하면 낮은 편이다. 특히 Software publishing 산업은 1%도 되지 않는다.
			- SI : Software publising, IT and other information services
		- ICT Manufacturing은 중국 등 개발도상국에서 많이 따라잡고 있어서 비중이 줄어들 수도 있다. 이를 SI로 메꿔야 할 필요성이 있다.
	- software R&D 투자 비율이 미국은 4%, 독일은 5%인데, 한국은 1%도 되지 않는다.
		- 투자가 적으니 성장이 되는 것이 쉽지 않다.

2. 글로벌 일류 SW개발자의 필수 역량
- SW 개발 프로세스와 전문가 역할
	- ![image](https://user-images.githubusercontent.com/49339278/135189206-037e0d33-e6b7-4525-9b66-583b31162257.png)
	1. 기획 : 분석자 -> SW제품 정의, Theme/Epic 정의
	2. 사전 분석/ 설계 단계 ; 분석자 -> 기능 분석 (Process 모델링, Data 모델링, UseCase 도출 및 시나리오 작성) / 아키텍트 -> 기획에 기반한 SW 아키텍처 설계 및 PoC
	3. 반복점증적 개발 단계(Construction) : 개발자
		- 반복주기 계획 : Domain 모델링 및 공수 추정
		- XP, Test-First Programming, ReFactoring, CI(Continuous Integration)
		- 제품 증분 출시

- java 개발자로 입문하려면? -> 조사에 따르면, 경험이 없고 빠르게 배워야 한다면 16개월 매일 공부해야!(일 3~4시간 공부, 주 5~7일 공부 / 4개월 : 자바 언어 + 핵심 기술등, 12 : 첫 직장을 위한 기술 테크닉)
	- 언어는 기본이고, 각종 기술 + 회사에서 필요로 하는 기술을 항상 배워야 한다.
		- Java Core : Concurrency, collections, java 8(최신 버전), IO(input, output), Tools, Framework(특히 string), DataBase, Testing, API Clients, Utility Libraries, Java Patterns 등

- 글로벌 일류 SW 개발자의 필요 역량
	- ![image](https://user-images.githubusercontent.com/49339278/135191151-dcedb9b1-1511-44db-905e-e6d3dae6b7ee.png)
	1. 분석 산출물의 정확한 이해 : 프로세스모델, 데이터모델, 유스케이스, 시나리오
	2. 테스트 코드 작성 및 TFP : 테스트 시나리오, 테스트 케이스 도출, 테스트 우선 개발 기법 (Test-First Programming)
	3. 소스 코드 작성 : **프로그래밍 언어 문법, 라이브러리/프레임워크의 클래스/메소드 활용 능력**, **클린 코드 작성 기법**
	4. 객체 설계 원칙 및 패턴 적용 능력 : Object Design Principles, GRASP / **GoF** / **DDD Design Patterns, Code Small, Refactoring**
	5. 빌드, 통합 테스트, 배포(CI/CD)
	6. 프로젝트 및 프로세스 관리 : 공수산정, 요구사항관리, 품질관리, 형상관리, 기법/툴 개선, 재사용관리
	- 중요한 것 : 소스 코드 작성법, 영어 단어, 클린 코드를 작성하는 기법을 알아야 한다! Code Smells를 제거해야 함!  (버전 관리, 기능 추가 등 업데이트와 협업을 할 때 매우 중요!)
	- Communication이 활발하게 이뤄지기 때문에, 작문 실력이 중요하다!

3. SW 분석과 설계

- SW 공학 활동 : 목적
	- SW 분석(SW 요구공학) : 사용자에게 차별화된 가치 제공
	- SW 설계(설계는 개발자의 몫, 매우 중요)
		- SW 아키텍처 설계 : SW 비기능 품질요건 (변경용이성, 재사용성 포함)충족
		- SW 프로그램 설계(객체 설계, SW 상세 설계) : 결함 유발 없이 쉽게 변경, 재사용 제고 -> 개발자가 할 줄 알아야 훌륭한 개발자가 된다.

- 분석 산출물 = 설계 투입물, 설계 모델 = 코드
	- ![image](https://user-images.githubusercontent.com/49339278/135192707-3b7b58dd-1c24-4f41-be19-a1882edc1fca.png)
	- 빨간 색 : 기획자
	- 초록 색 : 아키텍처
	- 파란 색 : 개발자
	- toy project 시행 시, 한 번은 다 같이 해보는 것도 나쁘지 않다고 생각

- 잘하는 SW 개발자와 최고 잘하는 개발자 간의 생산성 차이는 : 100배 ~ 1000배
- 사례
	> Visual Paradigm 프로그램 : 다이어그램 작성 (설명할 때 파워포인트보다 더 효율적)
	> 소프트웨어 공학을 완벽하게 이해해야 소프트웨어 설계가 원활하고 설명을 할 때 쉬워진다.
	- 도서관 정보시스템 사례 : 프로세스 모델
		- ![image](https://user-images.githubusercontent.com/49339278/135193481-9c34fafe-651e-4db2-aefd-f8a81a867855.png)
		- 객체와 기능을 구별하여 프로세스 모델을 구성 후 개발해야 할 필요!
	- 도서관 정보시스템 사례 : 데이터 모델
		- ![image](https://user-images.githubusercontent.com/49339278/135193898-9407bc92-93c9-4ad3-959e-b58e715298c5.png)
		- 이 프로세스(절차) 모델링과 데이터 모델과 병행해야 한다.
	- 도서관 정보시스템 사례 : 사용사례(Use Case) 모델
		- ![image](https://user-images.githubusercontent.com/49339278/135194356-77d0bb5e-4a67-459c-8088-12953505d1c0.png)
 	- 도서관 정보시스템 사례 : 사용사례 시나리오 
 		- ![image](https://user-images.githubusercontent.com/49339278/135194486-d48fad18-3dda-40e1-91c6-9bd316aedf0d.png)
	- 도서관 정보시스템 사례 : 도메인 모델
 		- ![image](https://user-images.githubusercontent.com/49339278/135196221-665f4216-bebe-45b1-a3fa-97bdf1432b05.png)
 		- 실리콘벨리의 SW 개발자들은 Design Patterns 등의 공부를 무조건 다 하지만, 우리나라는 부족한 경우가 있음.
	- 도서관 정보시스템 사례 : 테스트 케이스
		- ![image](https://user-images.githubusercontent.com/49339278/135197053-f96ae6e7-35bb-46eb-96bd-ed579c665370.png)
 

4. 테스트 주도 개발 (TDD)
- 이걸 알아야 애자일 프로그래밍이 가능하다.
- XP = TDD + CI, TDD = TFP + Refactoring
	- ![image](https://user-images.githubusercontent.com/49339278/135197500-b584fdc0-c6a1-42c0-ad81-ba68bc377bed.png)

- TDD : Iteration
	- ![image](https://user-images.githubusercontent.com/49339278/135198446-28685816-a780-4a7a-bcd2-910ab307ab01.png)
	- 여러 테스트를 진행하여 빈틈 없이 촘촘하게 프로그램을 구성한다.
	- 여러번 Iteration을 통해 단계별로 테스트를 진행하고, 통과될 때마다 코드가 늘어나서 프로그램의 완성도를 높인다.
	- 


5. 리팩토링
- 코드 냄새 제거하는 리펙토리 기법 -> REFACTORING, Clean Code 책 보고 실제 적용 연습해보기
- 좋은 코드 : 짧게(3줄), 기능의 이름을 알기 쉽게 작성한 메소드
	- Code Smell : Long method with many comments
	- 인텔리제이는 코드를 작성하면 Refectoring 기능을 클릭하면 해준다.
	- 실제로 많은 기능이 오픈소스 등으로 제공되니... 많은 기법을 이해하고 왜 그 기법을 사용하면 좋은지를 이해하는 것이 제일 중요하다!

6. SW 설계의 원리
- SW 설계 원칙
	- ![image](https://user-images.githubusercontent.com/49339278/135199287-896bd0ca-4a46-4344-822f-0a39c662a83a.png)
	- 이러한 설계 원칙을 이해하고 원칙을 외워서 습관처럼 행동하기

- SW 설계 패턴 (객체 설계 패턴(Object Design Patterns))
	- ![image](https://user-images.githubusercontent.com/49339278/135199447-7586d11f-f1f8-4e79-8cf2-8ddabc8c0076.png)

- Adaptor (aka Wrapper) Pattern
	- ![image](https://user-images.githubusercontent.com/49339278/135199632-84dcb5e1-e78a-4443-98eb-6110edb79015.png)

- MVC Pattern
	- ![image](https://user-images.githubusercontent.com/49339278/135200050-a6152f96-50dc-4d22-b690-e86648db9e64.png)

- 공부할 책(java 기준)
	- Head First Java
	- Effective Java
	- Design Pattern

- 연락처
	- ![image](https://user-images.githubusercontent.com/49339278/135200418-b360c75f-551e-4bf1-ab18-33e4fc64a1fe.png)


