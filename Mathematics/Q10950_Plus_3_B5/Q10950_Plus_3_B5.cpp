#include <iostream>
#include <vector>

int main()
{


	int rep = 0;
	int res = 0;
	int terms[2];

	std::cin >> rep;
	std::vector<int> out(rep);

	for (int a = 0; a < rep; a++) {

		std::cin >> terms[0] >> terms[1];

		for (int b = 0; b < 2; b++) {

			res = res + terms[b];

		}

		out[a] = res;
		res = 0;
	}

	for (int a = 0; a < rep; a++) {
		std::cout << out[a] << "\n";
	}

}