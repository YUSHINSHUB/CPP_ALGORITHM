#include <iostream>

int main()
{
	int star = 0;
	std::cin >> star;

	for (int a = 1; a <= star; a++) {
		for (int b = 0; b < star - a; b++) {
			std::cout << " ";
		}
		for (int c = 0; c < a; c++) {
			std::cout << "*";
		}
		std::cout << "\n";
	}
}