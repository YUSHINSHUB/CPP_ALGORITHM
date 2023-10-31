/*
commented by ChatGPT
This C++ program calculates the sum of the greatest common divisors (GCDs) of all pairs in a list of integers for multiple test cases.
For each test case, it reads a list of integers and computes the sum of GCDs for each unique pair in the list.
The output is the sum of GCDs for each test case, printed on a new line.
이 C++ 프로그램은 여러 테스트 케이스에 대해 정수 리스트의 모든 쌍의 최대공약수(GCD)의 합을 계산합니다.
각 테스트 케이스에 대해 정수 리스트를 읽고 리스트 안의 각 고유한 쌍에 대한 GCD의 합을 계산합니다.
출력은 각 테스트 케이스에 대한 GCD의 합으로, 새로운 줄에 출력됩니다.
*/

#include <iostream>
#include <vector>
#include <algorithm> // Include the algorithm header for the min function

using namespace std;

struct vec {
	int n[100]; // Array to store up to 100 integers
};

int main() {

	int t; // Variable to store the number of test cases
	cin >> t;

	vector<vec> s(t); // Vector of 'vec' structures to hold all test case data

	// Input phase for all test cases
	for (int i = 0; i < t; i++) {
		int cnt; // Number of integers in the current test case
		cin >> cnt;
		s[i].n[0] = cnt; // Store the count in the first element of the array
		for (int z = 1; z <= cnt; z++) {
			cin >> s[i].n[z]; // Read integers for the current test case
		}
	}

	// Processing phase for all test cases
	for (int i = 0; i < t; i++) {
		int cnt = s[i].n[0]; // Retrieve the count for the current test case
		long long res = 0; // Variable to store the sum of GCDs for the current test case
		// Calculate GCD for each pair of integers in the current test case
		for (int z = 1; z < cnt; z++) {
			for (int x = z + 1; x <= cnt; x++) {
				// Find the GCD for the pair (s[i].n[z], s[i].n[x])
				for (int c = min(s[i].n[z], s[i].n[x]); c >= 1; c--) {
					if (s[i].n[z] % c == 0 && s[i].n[x] % c == 0) {
						res += c; // Add the GCD to the result
						break; // Break out of the loop once the GCD is found
					}
				}
			}
		}
		cout << res << "\n"; // Output the sum of GCDs for the current test case
	}

	return 0; // Return 0 to indicate successful completion
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
