/*
	commented by ChatGPT
	Summary: This program computes a list of decreasing numbers using a backtracking approach. 
	It then retrieves the nth number from the list and prints it.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// A vector to store the decreasing numbers.
vector<long long> list;

/*
The backtracking function to compute decreasing numbers.
For a given number, it tries to append digits to the end of the current number which are smaller than the number's last digit.
*/
static void bt(long long n) {
	for (int i = 0; i <= 9; i++) {
		if (i < n % 10) {
			list.push_back(n * 10 + i);
			bt(n * 10 + i);
		}
	}
}

int main() {
	// Reading the desired position (n) in the sequence.
	int n;
	cin >> n;

	// Zero is always the first decreasing number.
	list.push_back(0);

	// Initializing the list with single-digit numbers.
	// Then using backtracking to compute the multi-digit decreasing numbers.
	for (int i = 1; i <= 9; i++) {
		list.push_back((long)i);
		bt(i);
	}

	// Sorting the list to ensure it's in increasing order.
	sort(list.begin(), list.end());

	// If n is out of bounds of the list, print -1. Otherwise, print the nth decreasing number.
	if (n >= list.size()) cout << "-1";
	else cout << list[n];
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
