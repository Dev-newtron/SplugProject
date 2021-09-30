## 9장 비트 수준 접근

1. 비트 수준 접근

   모든 내용은 메모리에 0과 1의 이진값으로 저장

   *비트*: 이진 값의 각 자리

   *바이트*: 8비트

   *워드*: 메모리에서 읽혀지는 단위

2. 비트 단위 연산자

   `int, short, long, long long, char` 등과 같은 정수형 수식에 사용됨

   *시스템 종속적*

   **논리 연산자**

   `~` : 비트단위 보수

   `&`: 비트단위 논리곱

   `^` : 비트단위 배타적 논리합
   `|` : 비트단위 논리합

   **이동 연산자**

   `<<` : 왼쪽 이동

   `>>` : 오른쪽 이동

3. ~ 연산자

   1의 보수 연산자. 비트단위 보수 연산자

   0 -> 1

   1 -> 0

   

   **!a = 0**

4. 비트 단위 이진 논리 연산자

   이진 논리 연산자

   a b a&b a^b a|b

   0 0   0     0     0

   1 0   0     1     1

   0 1   0     1     1

   1 1   1     0     1

   

5. 마스킹 연산

   주어진 비트열의 특정 비트를 0으로 만드는 것

   ```c
   int i, mask = 1;
   //mask = 0000 0000 0000 0000 0000 0000 0000 0001
   for (i = 0; i < 10; ++i)
     printf("%d", i&mask);
   ```

   i == 0)

   i: 00000000000000000000000000000000

   mask: 00000000000000000000000000000001

   i & mask

   ​     00000000000000000000000000000000

   ​     00000000000000000000000000000001

   => 00000000000000000000000000000000

   i ==1)

   i & mask

   ​     00000000000000000000000000000001

   ​     00000000000000000000000000000001

   => 00000000000000000000000000000001

   **result**

   i가 홀수면 1, 짝수면 0을 출력

6. 마스크

7. 이동 연산자

   지정된 값의 비트열을 이동시키는 연산자

   두 피연산자는 **정수** 수식이어야 함

8. 왼쪽 이동 연산자

   `수식1 << 수식2`

   수식1의 비트 표현을 수식2가 지정하는 수만큼 왼쪽으로 이동

   **2의 거듭제곱 효과**

   

9. 오른쪽 이동 연산자

   `수식1 >> 수식2`

   수식1의 비트 표현을 수식2가 지정하는 수만큼 오른쪽으로 이동

   *수식1이 `unsigned` 형이면 상위비트로 0이 들어옴*

   -> **2의 거듭제곱으로 나누기 연산**

   

   *수식1이 `signed` 형이면 상위비트로 0이 들어올 수도 있고, 1이 들어올 수도 있음*

   -> **시스템 종속적**

   
10. 복합 배정 연산자

    문제로 내기 쉬운 부분으로 잘 분석해서 답을 내야함

11. 패킹과 언패킹

    패킹: 여러 정보를 비트 단위 연산자를 사용하여 적은 바이트로 압축하는 것

    - 메모리 절약
    - 전송시간 줄임

    언패킹: 패킹된 정보를 사용하기 전에 정보를 추출하는 것

    *패킹과 언패킹은 문제를 내기 매우 쉬움. 강의 교안의 예제만 잘 숙지해도 맞을 수 있음*

12. 패킹

13. 언패킹

14. 비트 필드

    구조체나 공용체에서 `int`, `unsigned` 형의 멤버에 비트 수를 지정하는 것

## 10장 전처리기

1. 전처리기

   - 프로그램 개발과 유지보수를 쉽게하고, 가독성을 높이고, 프로그램 포팅을 쉽게 함

   - #으로 시작하는 행을 전처리 지시자라고 함
   - c언어의 나머지 부분과 독립적임
   - 전처리 지시자가 영향을 미치는 범위는 그 파일에서 전처리 지시자가 있는 위치에서 그 파일의 끝이거나, 다른 지시자에 의해서 그 지시자의 효력이 없어질 때까지
   - 전처리기는 C를 알지 못함

2. 매크로

   - 기호 상수

   - 문자열 대치

   - 인자가 있는 매크로

     **정의가 길어질 경우에 현재 행의 끝에  `\`를 삽입하면 다음 행에 연결해서 계속 쓸 수 있음**

3. 기호 상수

   `#define` [식별자] [상수]

   *모든 식별자는 상수로 대치됨*

4. 문자열 대치

   `#define` [식별자] [문자열]

   *모든 식별자는 문자열로 대치됨*

5. 매개 변수를 갖는 매크로

   `#define func(x) ((x) * (x) * PI)`

   `x`: 매개변수

   전처리기는 매개변수를 실인자로 *대치함*

   `inline` 함수와 유사하지만 몇 가지 차이가 있음

   - 매크로는 인자의 형을 검사하지 않음

   - 매크로는 인자들을 여러 번 평가함

     `define func(x) ((x) * (x) * PI)`

     : `func(r++)`

     => `((r++) * (r++) + PI)`

     *대치하기 때문에 여러 번 평가됨*

   - 유의 사항 꼭 읽어보기

6. #연산자

   문자열화 연산자

   `#define string(a) #a`

    : `string(주라기 공원 I)`

   => "주라기 공원 I"

   *디버깅을 위한 #연산자 사용*

7. 인자 생략

8. 헤더 파일

9. #include

10. 조건부 컴파일

    - 프로그램의 특정 부분을 선택적으로 컴파일 할 수 있게 하는 기능

    - 이식성이 높은 프로그램을 만들 수 있게 함

11. #undef

    이 문장 이후로 표현된 매크로는 사용할 수 없음

    -> 매크로를 다시 정의할 때 주로 사용됨

12. #ifdef, #ifndef, #else, #endif

13. #if, #elif, #else, #endif

14. defined

15. 디버깅 코드