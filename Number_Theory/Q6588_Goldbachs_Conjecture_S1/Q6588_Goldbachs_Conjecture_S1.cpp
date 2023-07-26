// This C++ code is designed to check and output pairs of prime numbers that sum to a given number n, 
//as described by Goldbach's Conjecture. 
//To do this efficiently, 
//the program uses an Eratosthenes Sieve technique to pre-compute and mark prime numbers up to 1,000,000.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false); // Speed up I/O operations by not syncing C and C++ I/O streams
	cin.tie(NULL); // Untie cin from cout to speed up input operations
	cout.tie(NULL); // Untie cout from cin to speed up output operations

	// Boolean array to check if a number is prime
	int chk[1000001];
	chk[0] = 1; // 0 is not prime
	chk[1] = 1; // 1 is not prime
	for (int i = 2; i <= 1000000; i++) {
		if (chk[i] != 1) { // If i is a prime number
			chk[i] = 0; // Mark i as prime
			for (int z = i * 2; z <= 1000000; z += i) {
				chk[z] = 1; // Mark multiples of i as non-prime
			}
		}
	}

	while (true) {

		int n;
		cin >> n; // Read number from input

		if (n == 0) { // If n is 0, break the loop
			break;
		}
		bool check = true;

		for (int i = 3; i <= n; i += 2) { // Start from 3 and only consider odd numbers
			if (chk[i] == 0 && chk[n - i] == 0) { // If both i and n - i are primes
				cout << n << " = " << i << " + " << n - i << "\n"; // Print result
				check = false; // Mark that we have found a pair
				break;
			}
		}

		if (check == true) { // If no pair has been found
			cout << "Goldbach's conjecture is wrong.\n"; // Print error message
		}

	}

	return 0;
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
