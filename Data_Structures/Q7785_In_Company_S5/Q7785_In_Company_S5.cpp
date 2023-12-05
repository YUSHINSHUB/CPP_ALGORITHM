#include <iostream>
#include <set>
using namespace std;

int main()
{
	int n;
	cin >> n;
	set<string> hs;
	//set은 요소가 자동으로 오름차 정렬되어 들어간다.

	string name, stat;

	for (int i = 0; i < n; i++) {
		cin >> name >> stat;
		if (stat == "enter") {
			hs.insert(name);
		}
		else {
			hs.erase(name);
		}
	}

	for (auto it = hs.rbegin(); it != hs.rend(); it++) {
		cout << *it << "\n";
	}
	//내림차순으로 출력해야 되기 때문에 begin이 아니라 rbegin (reversed begin)이다.

}