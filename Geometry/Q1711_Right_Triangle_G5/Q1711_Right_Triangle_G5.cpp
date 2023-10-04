﻿/*
commented by ChatGPT
This C++ code calculates the number of right-angled triangles that can be formed using n given 2D points by examining the vector relationships between the points.
이 C++ 코드는 주어진 n개의 2D 점을 사용하여 점들 간의 벡터 관계를 검사하여 생성할 수 있는 직각삼각형의 수를 계산합니다.
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// 두 정수의 최대 공약수를 계산하는 함수 (Function to compute the Greatest Common Divisor of two integers)
int getGCD(int x, int y) {
	while (y != 0) {
		int n = x % y;
		x = y;
		y = n;
	}
	return x;
}

int main()
{
	int n;
	cin >> n;  // 사용자로부터 2D 점의 수를 입력받습니다. (Input the number of 2D points from the user)
	int res = 0;
	vector<pair<int, int>> p(n);

	// n개의 점에 대한 좌표를 입력 받습니다. (Receive the coordinates for n points)
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}

	// 모든 점에 대해 (For each point)
	for (int i = 0; i < n; i++) {
		vector<pair<int, int>> t = p;

		// 현재 점을 t의 첫 번째 원소로 설정합니다. (Set the current point as the first element of t)
		swap(t[i], t[0]);

		map<pair<int, int>, int> hm;

		// 첫 번째 점을 기준으로 다른 점까지의 벡터를 계산합니다. (Calculate vectors from the first point to all other points)
		for (int j = 1; j < n; j++) {
			int x = t[j].first - t[0].first;
			int y = t[j].second - t[0].second;

			// 벡터 (x, y)를 기본 형태로 정규화합니다. (Normalize the vector (x, y) to its basic form)
			int g = abs(getGCD(x, y));
			x /= g;
			y /= g;

			// 벡터를 맵에 저장하고, 동일한 벡터에 대한 출현 빈도를 증가시킵니다. (Store the vector in the map and increase the occurrence count for identical vectors)
			hm[pair<int, int>(x, y)]++;
		}

		// 맵의 각 벡터에 대해 (For each vector in the map)
		for (auto en : hm) {
			// 직각을 형성하는 벡터가 맵에 있는지 확인하고, 있으면 결과를 업데이트합니다. (Check if the map contains a vector that forms a right angle and update the result if so)
			if (hm.find(pair<int, int>(-en.first.second, en.first.first)) != hm.end()) {
				res += en.second * hm[pair<int, int>(-en.first.second, en.first.first)];
			}
		}
	}

	// 계산된 직각삼각형의 수를 출력합니다. (Output the calculated number of right-angled triangles)
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