// Turn off the warning caused by the use of older functions
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

#define MAX 3000;

// Static variables to store grid size, number of chicken places and homes, picking status, and the result.
static int n;
static int m;
static vector<pair<int, int>> chp; // Stores chicken place coordinates.
static vector<pair<int, int>> hop; // Stores home coordinates.
static bool pick[13]; // Used in backtracking to mark picked chicken places.
static int res;

/*
 * commented by ChatGPT
 * Summary:
 * 1. Define a backtracking function to calculate the minimum distance.
 * 2. Use a main function to read input, call the backtracking function, and print the result.
 */

 // Backtracking function to compute minimum distance.
static void bt(int sidx, int cnt) {
	int sum = 0;
	int temp = 0;
	int minim = MAX;

	// When m chicken houses are selected
	if (cnt == m) {
		for (int z = 0; z < hop.size(); z++) {
			minim = MAX;
			// For each home, find its distance to the nearest chicken house.
			for (int i = 0; i < chp.size(); i++) {
				if (pick[i]) {
					temp = abs(hop[z].second - chp[i].second) + abs(hop[z].first - chp[i].first);
					minim = min(temp, minim);
				}
			}
			sum += minim; // Accumulate total distance for this combination.
		}
		res = min(sum, res); // Update result if this is a better solution.
		return;
	}
	else {
		// Recurse by selecting next chicken house.
		for (int i = sidx; i < chp.size(); i++) {
			if (!pick[i]) {
				pick[i] = true;
				bt(i + 1, cnt + 1);
				pick[i] = false;
			}
		}
	}
}

int main() {

	cin >> n >> m;
	res = 3000; // Initial large value for result

	// Reading input grid
	for (int i = 0; i < n; i++) {
		for (int z = 0; z < n; z++) {
			int temp;
			cin >> temp;
			if (temp == 1) { // If it's a home
				hop.push_back(pair<int, int>(z, i));
			}
			else if (temp == 2) { // If it's a chicken house
				chp.push_back(pair<int, int>(z, i));
			}
		}
	}

	// Start backtracking process
	bt(0, 0);

	// Print the result
	cout << res;
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
