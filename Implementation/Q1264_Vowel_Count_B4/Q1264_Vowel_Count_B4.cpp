#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main()
{

	string in;
	int res;
	char c;

	while (getline(cin, in)) {
		if (in == "#") break;

		res = 0;
		for (int i = 0; i < in.length(); i++) {
			c = in[i];
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') res++;
			else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')res++;
		}

		cout << res << "\n";
	}

}