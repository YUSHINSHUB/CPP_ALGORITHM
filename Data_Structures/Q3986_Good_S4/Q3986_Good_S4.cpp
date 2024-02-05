/*
commented by ChatGPT
This C++ code evaluates strings to determine if they are "good" based on specific conditions. 
A string is considered "good" if it can be entirely reduced by removing adjacent pairs of the same character. 
The code reads a set number of strings, utilizes a stack to track character pairs, and increments a counter for each string that can be completely reduced. 
Strings with an odd number of characters are immediately deemed not "good" since they cannot be fully reduced. The result is the total count of "good" strings.
이 C++ 코드는 특정 조건에 기반하여 문자열이 "좋은" 문자열인지 평가합니다. 문자열이 같은 문자의 인접한 쌍을 제거함으로써 완전히 축소될 수 있다면 그 문자열은 "좋은" 것으로 간주됩니다. 
코드는 일련의 문자열을 읽고, 스택을 사용하여 문자 쌍을 추적하며, 완전히 축소될 수 있는 각 문자열에 대해 카운터를 증가시킵니다. 
문자가 홀수 개인 문자열은 완전히 축소될 수 없기 때문에 즉시 "좋지 않은" 것으로 간주됩니다. 결과는 "좋은" 문자열의 총 수입니다.
*/

#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<char> stk; // Stack to hold characters for processing
	string in; // Input string
	int N; // Number of input strings
	int res = 0; // Counter for "good" strings

	cin >> N; // Reading the number of strings

	for (int i = 0; i < N; i++) {
		while (!stk.empty()) stk.pop(); // Clearing the stack for the new string
		cin >> in; // Reading the input string
		if (in.length() % 2 == 1) // If string length is odd, it cannot be "good"
			continue;

		for (int j = 0; j < in.length(); j++) {
			if (!stk.empty() && stk.top() == in[j]) // If the top of the stack matches the current character
				stk.pop(); // Remove the pair from the stack
			else {
				stk.push(in[j]); // Add the character to the stack
			}
		}

		if (stk.empty()) // If the stack is empty, all pairs were removed
			res++; // Increment the count of "good" strings
	}

	cout << res; // Output the result
}
