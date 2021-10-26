- 라즈비안OS는 리눅스 OS의 한 종류이다.
- CLI환경이다. GUI환경이 아니고.
- C 컴파일러는 gcc이다.
- Linux는 Windows와는 다르게 불편하다. 그리고 불친절하다.
- IDE = Integrated Development Environment(통합개발환경)
  - Edit(편집) -> Tool / 전용 Editor / 메모장이 필요
  - Complier(번역기) ; sudo code -> binary code
  - link(연결) : binary + library => out 파일 => 실행파일
- IDE는 Edit, Complier, Link을 모두 묶은 패키지이다.
- 하지만 리눅스에서는 제대로 된 IDE는 없다. 물론 있긴 하지만 무료는 아니다.
  - Visual Studio Code
  - 편집기에서 gcc를 사용해야 한다는 것이다
- cd : 디렉토리 이동
- ls -al : 목록 자세히 보기
- cd에 아무것도 붙이지 않는다면 처음 디렉토리로 들어간다.
- usr 디렉토리에 프로그래밍할 때 사용할 수 있는 라이브러리와 헤더파일들이 들어가 있다.

- Geany 에디터 
- 리눅스 명령어로 파일을 삭제하는 방법 : ```rm 파일명.확장자```
  - 주의 : 대소문자 구별
  - 완료해도 끝났다는 등의 반응이 없다. == 잘 된것
  - 말이 많은 경우 == 오류가 발생했다는 뜻

- 파일명.c : c 파일
- 파일명.o : c 파일을 gcc 컴파일러로 컴파일된 파일
- 파일명 : c 파일을 빌드한 파일

- 리눅스 명령어로 디렉토리 만드는 방법 : ```mkdir 디렉토리명```
- . : 현재 디렉토리(Current Directory)
- .. : 상위 디렉토리(Parent Directory)

- cd .. : 상위 디렉토리로 변경
- ```gcc -o 빌드_파일명 C파일명.c``` (빌드 파일명 지정하지 않으면, ```a.out```을 사용 - 기본값(default)
