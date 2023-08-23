// Commented by ChatGPT
// This C++ program generates and displays all possible passwords of a given length from a given set of characters.
// It ensures that every password has at least one vowel and at least two consonants.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	// Reading the number of characters to form the password (l) and total characters available (c)
	int l, c;
	cin >> l >> c;

	// Vector to store the available characters
	vector<char> alp(c);
	// Vector to store the current combination indexes for the password
	vector<int> cnt(l);

	// Reading the characters into the alp vector
	for (int i = 0; i < c; i++) {
		cin >> alp[i];
	}

	// Initializing the cnt vector with default indexes
	for (int i = 0; i < l; i++) {
		cnt[i] = i;
	}

	// Sorting the alp vector to get passwords in lexicographical order
	sort(begin(alp), end(alp));

	// Flags to check the termination condition and password validation
	bool end = false;
	bool pass = true;

	int c1 = 0, c2 = 0;

	// Main loop to generate and check each password
	while (true) {
		c1 = 0;
		c2 = 0;
		// Count the number of vowels and consonants in the current password combination
		for (int i = 0; i < l; i++) {
			if (alp[cnt[i]] == 'a' || alp[cnt[i]] == 'e' || alp[cnt[i]] == 'i' || alp[cnt[i]] == 'o' || alp[cnt[i]] == 'u') {
				c1++;
			}
			else {
				c2++;
			}
			// If current combination meets the requirement, mark as valid
			if (c1 >= 1 && c2 >= 2) {
				pass = false;
				break;
			}
		}
		// If the current password is valid, display it
		if (pass == false) {
			for (int i = 0; i < l; i++) {
				cout << alp[cnt[i]];
			}
			cout << "\n";
		}

		// Resetting the password validity flag for the next iteration
		pass = true;

		// Move to the next possible password combination
		cnt[l - 1]++;
		if (cnt[l - 1] >= c) {
			cnt[l - 1]--;
			int temp = l - 2;
			while (cnt[temp] == cnt[temp + 1] - 1) {
				temp--;
				// If all combinations have been tried, end the loop
				if (temp == -1) {
					end = true;
					break;
				}
			}
			if (end == false) {
				cnt[temp]++;
				for (int i = temp + 1; i < l; i++) cnt[i] = cnt[i - 1] + 1;
			}
			else {
				break;
			}
		}
	}
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
