// 2739_gugudan_while.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	int i = 0;
	scanf_s("%d", &i);

	int a = 1;
	while( a <= 9 ) {
		printf("%d * %d = %d\n", i, a, i * a);
		a++;
	}
}

//반복문 while 사용
