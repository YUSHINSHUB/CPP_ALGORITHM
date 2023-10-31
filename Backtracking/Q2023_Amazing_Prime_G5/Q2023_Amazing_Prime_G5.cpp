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


// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
