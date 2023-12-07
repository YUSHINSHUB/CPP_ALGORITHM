#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{

	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	map<int, string> name;
	map<string, int> no;

	for (int i = 1; i <= n; i++) {
		string temp;
		cin >> temp;
		name.insert(pair<int, string>(i, temp));
		no.insert(pair<string, int>(temp, i));
	}

	for (int i = 0; i < m; i++) {
		string in;
		cin >> in;
		if (in[0] >= '0' && in[0] <= '9') {
			int tmp = stoi(in);
			cout << name[tmp] << "\n";
		}
		else {
			cout << no[in] << "\n";
		}
	}

}
