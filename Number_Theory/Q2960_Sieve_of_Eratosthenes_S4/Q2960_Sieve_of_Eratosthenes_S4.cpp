/*
commented by ChatGPT
This C++ program finds the k-th non-prime number within the range of 2 to n using a variant of the Sieve of Eratosthenes algorithm.
Initially, it assumes all numbers are prime and then marks multiples of each number as non-prime.
The program increments a counter each time a non-prime is marked, and once the k-th non-prime is marked, it captures its value and terminates.
이 C++ 프로그램은 에라토스테네스의 체 알고리즘 변형을 사용하여 2부터 n 범위 내에서 k번째 비소수를 찾습니다.
처음에는 모든 숫자를 소수로 가정한 다음 각 숫자의 배수를 비소수로 표시합니다.
비소수가 표시될 때마다 카운터를 증가시키며, k번째 비소수가 표시되면 그 값을 캡처하고 종료합니다.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {

	int n, k;
	cin >> n >> k; // Taking input for range and k-th non-prime to find
	int cnt = 0; // Counter for the number of non-prime numbers marked
	int res = 0; // The result to store the k-th non-prime number

	vector<bool> chk(n + 1, false); // Boolean vector to mark non-prime numbers, initialized to false

	// Marking even numbers as non-prime and counting them
	for (int i = 2; i <= n; i += 2) {
		if (!chk[i]) {
			chk[i] = true;
			cnt++;
			if (cnt == k) {
				res = i;
				break;
			}
		}
	}

	// Checking odd numbers if k-th non-prime hasn't been found
	if (cnt != k) {
		for (int i = 3; i <= n; i += 2) {
			if (!chk[i]) {
				for (int z = i; z <= n; z += i) {
					if (!chk[z]) {
						chk[z] = true;
						cnt++;
						if (cnt == k) {
							res = z;
							break;
						}
					}
				}
				if (cnt == k) break; // Breaking out of the loop if k-th non-prime is found
			}
		}
	}

	cout << res; // Outputting the result

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
