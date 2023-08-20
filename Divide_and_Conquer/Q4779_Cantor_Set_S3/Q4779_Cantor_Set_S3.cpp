﻿/*
Commented by ChatGPT
Summary: This program generates the Cantor set pattern (fractal) up to iteration 12, and prints the pattern corresponding to the iteration number entered by the user.
The Cantor set pattern is generated by iteratively splitting each segment into three equal parts and removing the middle part.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string cnt[13]; // Initialize an array of string to hold the patterns for
	// each iteration

	fill(cnt, cnt + 13, "");

	cnt[0].append("-"); // The base pattern

	for (int i = 1; i <= 12; i++) { // Generate the pattern for iterations 1 to 12
		int bl = cnt[i - 1].length(); // Get the length of the previous iteration's pattern
		for (int j = 0; j < bl; j++) {
			cnt[i] += (cnt[i - 1][j]); // Copy the previous pattern
		}
		for (int j = 0; j < bl; j++) {
			cnt[i].append(" "); // Add a space for the removed middle part
		}
		for (int j = 0; j < bl; j++) {
			cnt[i] += (cnt[i - 1][j]); // Copy the previous pattern again
		}
	}

	string inp = "";
	while (getline(cin, inp)) { // Read the iteration number from the user
		cout << cnt[stoi(inp)] << "\n"; // Print the pattern corresponding to the entered iteration
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