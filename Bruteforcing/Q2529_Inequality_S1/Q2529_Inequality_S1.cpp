/*
commented by ChatGPT
This C++ code uses backtracking to solve a problem involving finding the largest and smallest numbers that satisfy a series of inequality conditions ('<' or '>') between consecutive digits.
It explores all possible combinations of digits that meet the given inequalities and identifies the maximum and minimum valid numbers that can be formed.
이 C++ 코드는 연속된 숫자 사이의 부등호('<' 또는 '>') 조건을 만족하는 가장 크고 작은 숫자를 찾는 문제를 백트래킹을 사용하여 해결합니다.
주어진 부등식을 충족하는 모든 가능한 숫자 조합을 탐색하고 형성될 수 있는 최대 및 최소 유효 숫자를 식별합니다.
*/

#include <iostream>
#include <vector>
#include <climits>
#include <string>

using namespace std;

static vector<char> sym(9); // Vector to store inequality symbols
static int K; // Number of inequality symbols
static long long low = LLONG_MAX, hig = 0; // Variables to store smallest and largest numbers
static string lout, hout; // Strings to store smallest and largest numbers as string
static bool visited[10] = { false, }; // Array to keep track of visited digits

// Backtracking function to generate numbers according to the inequalities
static void bt(int idx, string res, int cur) {

	// Base case: if all inequalities are processed
	if (idx == K) {
		long long temp = stoll(res); // Convert the current result string to a number
		// Update lowest and highest numbers if necessary
		if (low > temp) {
			lout = res;
			low = temp;
		}

		if (hig < temp) {
			hout = res;
			hig = temp;
		}
		return;
	}

	// If the current symbol is '>', find a smaller digit than the current one
	if (sym[idx] == '>') {
		for (int i = cur - 1; i >= 0; i--) {
			if (visited[i]) // Skip if the digit is already used
				continue;
			visited[i] = true;
			bt(idx + 1, res + to_string(i), i); // Call backtracking for the next symbol
			visited[i] = false; // Backtrack
		}
	}
	// If the current symbol is '<', find a larger digit than the current one
	else {
		for (int i = cur + 1; i <= 9; i++) {
			if (visited[i]) // Skip if the digit is already used
				continue;
			visited[i] = true;
			bt(idx + 1, res + to_string(i), i); // Call backtracking for the next symbol
			visited[i] = false; // Backtrack
		}
	}
}

int main()
{
	cin >> K; // Read the number of symbols
	for (int i = 0; i < K; i++) {
		cin >> sym[i]; // Read the inequality symbols
	}

	// Start backtracking from each digit
	for (int i = 0; i <= 9; i++) {
		visited[i] = true;
		bt(0, to_string(i), i); // Start backtracking with each digit as the starting point
		visited[i] = false;
	}

	cout << hout << "\n" << lout; // Output the largest and smallest numbers
}