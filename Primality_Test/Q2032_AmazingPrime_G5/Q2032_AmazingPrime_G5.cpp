/*
commented by ChatGPT
This C++ code implements a backtracking algorithm to find and print all prime numbers with 'n' digits.
The program starts with single-digit prime numbers and appends digits from 0 to 9 to build up prime numbers with more digits.
If a prime number with 'n' digits is found, it is printed to the console.
이 C++ 코드는 'n' 자리의 모든 소수를 찾아 출력하는 백트래킹 알고리즘을 구현합니다.
프로그램은 한 자리 소수에서 시작하여 0부터 9까지의 숫자를 추가하여 더 많은 자리의 소수를 만듭니다.
'n' 자리 소수가 발견되면 콘솔에 출력됩니다.
*/

#include <iostream> // Header for input/output stream
#include <string>   // Header for string operations
#include <vector>   // Header for vector container
#include <algorithm> // Header for algorithms like sort
#include <set>      // Header for set container
#include <queue>    // Header for queue container

using namespace std;

static int n; // Global variable to store the number of digits for the prime numbers to find

// Backtracking function to generate and print 'n' digit prime numbers
static void bt(int cnt, int x) {
	bool isPrime = true; // Flag to check if a number is prime
	if (cnt == n) {
		// If the current number has 'n' digits and is prime, print it
		cout << x << "\n";
	}
	else {
		// Increase the digit count
		cnt++;
		// Loop through each possible next digit
		for (int i = x * 10; i <= (x * 10) + 9; i++) {
			isPrime = true; // Reset the flag for each new number
			// Check if 'i' is a prime number
			for (int z = 2; z <= i / 2; z++) {
				if (i % z == 0) {
					// 'i' is not prime if it is divisible by 'z'
					isPrime = false;
					break;
				}
			}
			// If 'i' is prime, continue backtracking with the new number 'i'
			if (isPrime) bt(cnt, i);
		}
	}
}

int main() {
	// Improve I/O efficiency
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// Read in the number of digits 'n'
	cin >> n;

	// Start backtracking with single-digit prime numbers
	bt(1, 2);
	bt(1, 3);
	bt(1, 5);
	bt(1, 7);

	// No explicit return is required for main in C++
}
