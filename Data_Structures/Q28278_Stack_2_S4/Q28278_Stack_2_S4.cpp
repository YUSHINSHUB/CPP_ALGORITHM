/*
Commented by ChatGPT
Summary: This program simulates basic stack operations based on user input.
The user specifies the desired operations on the stack and the program executes and outputs the
results of these operations.
*/

#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; // Number of operations to be performed
	cin >> n;
	stack<int> stk; // Stack declaration
	int c, num;

	for (int i = 0; i < n; i++) {
		cin >> c;

		switch (c) {
		case 1: // Push an element onto the stack
			cin >> num;
			stk.push(num);
			break;
		case 2: // Pop an element from the stack
			if (stk.empty())
				cout << "-1\n"; // If stack is empty, print -1
			else {
				cout << stk.top() << "\n";
				stk.pop();
			}
			break;
		case 3: // Print the size of the stack
			cout << stk.size() << "\n";
			break;
		case 4: // Check if stack is empty
			if (stk.empty())
				cout << "1\n"; // If empty, print 1
			else
				cout << "0\n"; // If not empty, print 0
			break;
		case 5: // Peek the top element of the stack
			if (stk.empty())
				cout << "-1\n"; // If stack is empty, print -1
			else
				cout << stk.top() << "\n";
			break;
		}
	}
}
