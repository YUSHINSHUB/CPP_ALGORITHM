/*
commented by ChatGPT
This C++ code checks whether any phone number is a prefix of another phone number from a list of numbers.
If any number is a prefix of another, it outputs "NO", otherwise "YES".
이 C++ 코드는 주어진 전화번호 목록 중 하나의 전화번호가 다른 전화번호의 접두사인지 확인합니다.
어떤 번호가 다른 번호의 접두사라면 "NO"를 출력하고, 그렇지 않으면 "YES"를 출력합니다.
*/

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

// Comparator function to sort strings based on their lengths
// 문자열을 그들의 길이에 따라 정렬하기 위한 비교 함수
bool comparator(string o1, string o2) {
	return o1.length() < o2.length();
}

int main() {
	int t;
	cin >> t;  // Read the number of test cases (테스트 케이스의 수를 읽음)

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;  // Number of phone numbers for this test case (이 테스트 케이스에 대한 전화번호의 수)
		string num[10000];  // Array to store phone numbers (전화번호를 저장하는 배열)
		set<string> hs;  // Set to track already processed numbers (이미 처리된 번호를 추적하기 위한 집합)

		// Reading phone numbers
		// 전화번호 읽기
		for (int j = 0; j < n; j++) {
			cin >> num[j];
		}

		// Sorting numbers based on their lengths to ensure prefixes come before the actual numbers
		// 접두사가 실제 번호 앞에 오도록 번호의 길이에 따라 번호 정렬하기
		sort(num, num + n, comparator);

		bool out = true;

		// Iterate through the sorted list of numbers
		// 정렬된 번호 목록을 반복하여 확인
		for (int j = 0; j < n; j++) {
			string sb = "";

			// Build a prefix string step by step from the current number
			// 현재 번호로부터 접두사 문자열을 단계별로 구축하기
			for (int k = 0; k < num[j].length(); k++) {
				sb += num[j][k];

				// If the current prefix is already in the set, it means a number is a prefix of another number
				// 현재 접두사가 이미 집합에 있으면, 어떤 번호가 다른 번호의 접두사임을 의미함
				if (hs.find(sb) != hs.end()) {
					out = false;
					break;
				}
			}

			hs.insert(num[j]);  // Insert the current number into the set (현재 번호를 집합에 삽입)

			if (!out)  // If a number was found to be a prefix, break out of loop (번호가 접두사로 발견되면 루프 탈출)
				break;
		}

		// Print the result
		// 결과 출력
		if (out)
			cout << "YES\n";
		else
			cout << "NO\n";
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
