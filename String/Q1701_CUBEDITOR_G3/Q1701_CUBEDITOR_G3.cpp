/*
commented by ChatGPT
This C++ program finds the length of the longest repeated substring in a given string using the Knuth-Morris-Pratt (KMP) algorithm.
It does this by examining each suffix of the string and applying the KMP algorithm to find the longest prefix which is also a suffix.
The program iterates through all possible substrings, updates the longest common prefix-suffix length using the KMP algorithm, and keeps track of the maximum length found.
이 C++ 프로그램은 주어진 문자열에서 가장 긴 반복되는 부분 문자열의 길이를 찾습니다.
이는 Knuth-Morris-Pratt (KMP) 알고리즘을 사용하여 각 문자열의 접미사를 검사하고 가장 긴 접두사가 접미사인지 찾음으로써 이루어집니다.
프로그램은 가능한 모든 부분 문자열을 순회하며, KMP 알고리즘을 사용하여 가장 긴 공통 접두사-접미사 길이를 업데이트하고, 찾아낸 최대 길이를 추적합니다.
*/

#include <iostream>

using namespace std;

int kmp(string s) {
	int idx = 0;
	int out = 0;
	int pi[5001]; // 접두사와 접미사가 일치하는 최대 길이를 저장하는 배열
	fill(pi, pi + s.length(), 0); // 배열 초기화

	for (int i = 1; i < s.length(); i++) {
		// 현재 문자와 접미사의 다음 문자가 다를 경우, 이전 접미사 위치로 이동
		while (idx > 0 && s[idx] != s[i]) {
			idx = pi[idx - 1];
		}

		// 현재 문자와 접미사의 다음 문자가 같을 경우, 접미사 길이 증가
		if (s[idx] == s[i]) {
			idx++;
			pi[i] = idx; // 현재 위치에서의 접미사 길이 업데이트
			out = max(out, idx); // 가장 긴 접미사 길이 갱신
		}
	}

	return out; // 가장 긴 접미사 길이 반환
}

int main() {
	string in;
	cin >> in;
	int res = 0;

	// 문자열의 모든 부분 문자열에 대해 KMP 알고리즘 적용
	for (int i = 0; i < in.length() - 1; i++) {
		string sub = in.substr(i); // 현재 위치에서 시작하는 부분 문자열
		res = max(res, kmp(sub)); // 가장 긴 반복 부분 문자열 길이 갱신
	}

	cout << res; // 결과 출력
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
