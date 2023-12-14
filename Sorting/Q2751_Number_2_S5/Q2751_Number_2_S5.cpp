#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int inp;

	priority_queue<int, vector<int>, greater<int>> q;

	for (int i = 0; i < n; i++) {
		cin >> inp;
		q.push(inp);
	}

	for (int i = 0; i < n; i++) {
		inp = q.top();
		cout << inp << "\n";
		q.pop();
	}
}