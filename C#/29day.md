* C# 숫자 형식 문자열

| 형식지정자 | 종류 | 예제 코드 | 출력 결과 |
|:---:|:----:|:----|:---:|
| C/c | 통화(Currency) | ```Console.WriteLine("{0:C}", 2.5); Console.WriteLine("{0:C}", -2.5);``` | $2.50 ($2.50)|
| D/d | 10진법(Decimal)| ```Console.WriteLine("{0:D5}", 25);``` | 00025 |
| E/e | 과학적 지수(Scientific) | ```Console.WriteLine("{0:E}", 250000);``` | 2.5000000E+005 |
| F/x | 고정 소수점(Fixed-point) | ```Console.WriteLine("{0:F2}", 25); Console.WriteLine("{0:F0}", 25);``` | 25.00 / 25 |
| G/g | 일반 (General) | ```Console.WriteLine("{0:G}", 2.5);```  | 2.5|
| N/n| 숫자 (Number) | ```Console.WriteLine("{0:N}", 25000000);``` | 2,500,000.00 |
| P/p | 백분율(Percentage) | ```Console.WriteLine("{0:P}", .2468013); Console.WriteLine("{0:P1}", .2468013);``` | 24.68% /  24.7%|
| X / x | 16진법(Hexadecimal) | ```Console.WriteLine("{0:X}", 250); Console.WriteLine("{0:X}", 0xffff);``` | FA / FFFF |
