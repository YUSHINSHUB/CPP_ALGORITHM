#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class mem {
public:
	int cnt;
	int age;
	string name;
};

int main() {


	int n;
	cin >> n;
	vector<mem> m(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> m[i].age >> m[i].name;
		m[i].cnt = i;
	}

	stable_sort(m.begin(), m.end(), [](mem o1, mem o2)-> bool {
		if (o1.age != o2.age) return o1.age < o2.age;
		else return o1.cnt < o2.cnt;
		});

	for (int i = 1; i <= n; i++) cout << m[i].age << " " << m[i].name << "\n";

}