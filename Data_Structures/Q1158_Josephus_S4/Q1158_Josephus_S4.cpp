#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{

	int a, b;
	string sb = "";
	queue<int> q;

	cin >> a >> b;

	sb.append("<");

	for (int i = 1; i <= a; i++) {
		q.push(i);
	}

	for (int i = 1; i < a; i++) {
		for (int x = 1; x < b; x++) {
			q.push(q.front());
			q.pop();
		}
		sb += to_string(q.front()) + ", ";
		q.pop();
	}
	sb += to_string(q.front()) + ">";
	q.pop();
	cout << sb;
}