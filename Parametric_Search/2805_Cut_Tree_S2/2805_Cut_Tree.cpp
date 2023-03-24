// 2805_Cut_Tree.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	long long goal;
	cin >> n >> goal;
	long long h = 0;
	long long cut = 0;
	int idx = 0;

	int temp = 0;

	map<int, int> hm;
	set<int> hset;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		hset.insert(temp);
		if (hm.find(temp) != hm.end()) hm[temp]++;
		else hm.insert(pair<int, int>(temp, 1));
	}

	vector<int> trees;
	trees.reserve(hset.size());
	copy(hset.begin(), hset.end(), back_inserter(trees));
	sort(trees.begin(), trees.end(), greater<int>());

	for (int i = 0; i < trees.size() - 1; i++) {
		idx += hm[trees[i]];
		if (cut + ((trees[i] - trees[i + 1]) * idx) <= goal) {
			cut += ((trees[i] - trees[i + 1]) * idx);
			h += trees[i] - trees[i + 1];
		}
		else {
			h += (goal - cut) / idx;
			cut += ((goal - cut) / idx) * idx;
			if (cut != goal) {
				h++;
			}
			cut = goal;
			break;
		}
	}

	if (trees.size() == 1) {
		h = (goal / n);
		if (goal % n != 0) h++;
	}
	else if (cut != goal) {
		h += (goal - cut) / n;
		cut += ((goal - cut) / n) * n;
		if (cut != goal) h++;
	}

	cout << (trees[0] - h) << "";

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
