// Q16916_Substring_B2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//KMP알고리즘을 이용해 해결
//https://bowbowbow.tistory.com/6 참고

vector<int> getlps(string pattern) {

	// LPS(Longest Prefix which is also Suffix)
		// lps의 n번 자리에는 pattern의 n+1자리의 접두사(pattern이 abc일 경우 a, ab, abc)
		// 에서 해당 접두사의 접두사와 접미사가 일치한 부분 문자열의 최대 길이가 들어간다.
		// ex) pattern이 abababc일 때, lps[5] 는 abababc의 접두사 ababab에서
		// 해당 접두사의 접두사와 접미사가 같은 가장 긴 부분 문자열은 abab이므로 4가 들어간다.

	int m = pattern.length();
	vector<int> lps(m);

	int i = 1;
	int len = 0;
	lps[0] = 0;

	while (i < m) {
		if (pattern[i] == pattern[len]) {
			len++;
			lps[i] = len;
			i++;
		}

		if (i < m && pattern[i] != pattern[len]) {
			if (len == 0) {
				lps[i] = 0;
				i++;
			}
			else {
				len = lps[len - 1];
			}
		}
	}

	return lps;
}

int main() {

	string text, pattern;
	cin >> text >> pattern;

	vector<int> lps = getlps(pattern);

	bool res = false;
	int i = 0;
	int j = 0;
	int n = text.length();
	int m = pattern.length();

	while (i < n) {
		if (text[i] == pattern[j]) {
			i++;
			j++;
		}
		else {
			if (j == 0) {
				i++;
			}
			else {
				j = lps[j - 1];
				// 부분 문자열이 부분적으로 달라서 답이 아닐 경우 lps값을 이용하여
					// 앞부분을 건너뛰고 검사할 수 있다.
			}
		}

		if (j == m) {
			res = true;
			break;
		}
	}

	if (res)
		cout << "1";
	else
		cout << "0";

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
