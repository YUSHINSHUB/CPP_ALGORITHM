#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{

	int grade = 0;
	scanf("%d", &grade);

	switch ((int)grade / 10) {
	case 10:
	case 9:
		printf("A");
		break;
	case 8:
		printf("B");
		break;
	case 7:
		printf("C");
		break;
	case 6:
		printf("D");
		break;
	default:
		printf("F");
		break;
	}

}