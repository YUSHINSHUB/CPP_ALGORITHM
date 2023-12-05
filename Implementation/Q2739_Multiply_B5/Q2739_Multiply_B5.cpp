#include <iostream>

int main()
{
	int i = 0;
	scanf("%d", &i);

	int a = 1;
	while (a <= 9) {
		printf("%d * %d = %d\n", i, a, i * a);
		a++;
	}
}
