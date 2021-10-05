# Introduction to SQL Statement
1. Selete 기본구문
  ```SQL
  SELECT 컬럼이름, 컬럼이름, , 
  [INTO 새 테이블]
  FROM 테이블 이름 
  [WHERE 찾는 조건] 
  [GROUP BY 그룹에 의한 표현] 
  [HAVING 찾는 조건] 
  [ORDER BY 정렬 표현]
  ```
  - SELECT col1, col2 FROM table WHERE coln = option ORDER BY col1

2. 데이터 조회
  - 기초 테이블 없이 데이터 가져오기
  ```SELECT GETDATE(), 'TEST', 'Custom Table'```
  - 컬럼 이름 변경하기
    - AS를 이용한 컬럼명 변경 : SELECT GETDATE() AS '등록날짜'
    - '='을 이용한 컬럼명 변경 : SELECT 'STR' = 'Custom Table'
  - 데이터 전체 검색
    - TITLES 테이블의 모든 데이터를 가져와라
    ```sql
    USE PUBS  -- PUBS 데이터베이스를 이용하라
    GO
      SELECT *  -- 모든 컬럼들을 대표한다.
      FROM TITLES -- TITLES 테이블
    ```
    
    - 데이터 등록 구문
      ```sql
      Select 컬럼명  -- 여러 개의 컬럼을 선택하려면 콤마(,)로 구분한다.
      FROM 선택할 테이블명
      WHERE 선택할 컬럼의 로우(튜플)을 제한할 조건
      ```
    - 중복 데이터 한번만 출력 - **DISTINCT**
      ```sql
      -- 가게 코드가 중복되지 않고 한번만 출력
      SELECT DISTINCT Stor_id
      FROM Sales
      ```
      
    - Where를 이용한 조건문 검색
      ```sql
      -- titles 테이블에서 type='mod_cook'을 검색
      SELECT title_id, title, type
      FROM titles
      WHERE type='mod_cook' -- type이 'mod_cook'으로 row를 제한한다.
      ```
      
    - Where를 이용한 조건문 검색 - 비교 연산자
    ```
    -- titles 테이블에서 price가 20달러 이상인 책 제목을 가져와보자.
    SELECT title FROM titles WHERE price >= 20
    ```
    
    | 비교 연산 | 설명 |
    |:--|:--|
    |=|A와 B가 같다.|
    |>|A가 B보다 크다.|
    |<|A가 B보다 작다.|
    |>=|A가 B보다 크거나 같다.|
    |<=|A가 B보다 작거나 같다.|
    |<>(!=)|A와 B가 같지 않다.|
    |!<|A가 B보다 작지 않다.|
    |!>|A가 B보다 크지 않다.|
    
    - Where를 이용한 조건문 검색 - 논리 연산자
    ```
    SELECT title FROM titles WHERE title >'T' AND price>10
    ```
    
      - ![image](https://user-images.githubusercontent.com/49339278/135974148-de5352f5-d51b-4554-a535-0ebeb9e68b6b.png)
      - Like 형태를 사용하기 위해서는 패턴 형식을 사용해야 한다.
        - Like 형태
        - Not like 형태
      | 패턴 | 설명 | 표현 | 출력 예시 |
      |:---:|:--|:---:|:---|
      |```_``` | 어떤 단어든지 한문자 표현 | book_ | books, book|
      |%| 여러 문자 | book% | books, book, **bookstore** |
      | [ ] | [ ] 안에 있는 글자들 | [st]ring | sing, ting |
      |[^] | ^다음에 있는 글자 제외 | [m^c] | mike, many |
      
    - 위에서 몇 개만 가져오기 (top 가져올 개수)
    ```sql
    SELECT TOP 3 title_id.price
    FROM titles
    ```
    
    ```sql
    -- 같은 순위의 것을 모두 가져오고 싶다면, WITH TIES를 사용
    SELECT TOP 3 WITH TIES title_id.price
    FROM titles
    ```
    
    
    ```sql
    -- 일정 비율만 가져오려면, PERCENT 사용하면 된다.
    SELECT TOP 3 PERCENT title_id.price
    FROM titles
    ```
    
1. 데이터 정렬 (ORDER BY)
  - 오름차순 : ASC
  - 내림차순 : DESC

2. 연산 함수 이용 - 간단한 통계 활용
  - 참고 : ```*```는 모든 레코드를 나타낸다.
  
  | 함수 | 내용 |
  |:--|:--|
  |SUM|전체 또는 일부 합|
  |AVG|전체 또는 일부 평균|
  |COUNT|전체 또는 일부 개수|
  |MAX|표현식 중 가장 큰 수|
  |MIN|표현식 중 가장 작은 수 |
  
  - ISNULL 함수 : null값을 다른 값으로 바꿀 때 사용
    ```sql
    SELECT price, ISNULL(price, 0)  -- 가격이 NULL일 때 0으로 출력
    FROM titles
    ```
    
  - GROUP BY : GROUP BY에 의해 선택된 컬럼에 중복된 데이터가 존재한다면, 연산 함수에 의해 처리되고 ...
  - GROUP BY ~ HAVING : 연산함수에 집계된 범위를 제한할 때는 
  - GROUP BY ALL : WHERE절에서 제외된 것이라도

1. 조인(Join) : 결합
  - inner join = left join 
  - outer join = right join (적용되는 부분이 적다.)
2. 서브 쿼리(Sub Query)
