// Q20920_MEMORIZE_S3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{

	int n, m;
	cin >> n >> m;// 단어의 개수, 외울 단어의 최소 길이
	int idx = n;

	vector<pair<string, int>> word; // 단어들을 저장할 vector
	//c++에서 comparator 람다함수에서 map을 참조하여 등장횟수를 검색할 경우 해당 문제는 시간 초과가 나기 떄문에
	//vector를 pair형으로 선언한다.
	map<string, int> hm; // 단어와 해당 단어의 등장 횟수를 저장할 HashMap

	// n번 반복하면서 단어를 입력 받고 처리
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp; // 단어를 입력 받음
		if (temp.length() >= m) { // 단어의 길이가 m 이상일 때
			if (hm.find(temp) == hm.end()) hm.insert(pair<string, int>(temp, 1));
			else hm[temp]++; // HashMap에 단어를 키로 등장 횟수를 값으로 저장
			if (hm[temp] != 1)
				idx--; // 단어가 중복되면 idx 값을 감소
		}
		else
			idx--; // 단어의 길이가 m 미만일 경우 idx 값을 감소
	}

	for (auto it : hm) {
		word.push_back(it);
	}

	// 단어를 특정한 기준에 따라 정렬
	sort(word.begin(), word.end(), [](pair<string, int> o1, pair<string, int> o2) -> int {
		if (o1.second != o2.second) return o1.second > o2.second;
		else if (o1.first.length() != o2.first.length())
			return o1.first.length() > o2.first.length();
		else
			return o1.first < o2.first;
		// 두 단어의 길이와 등장 횟수가 동일하면 사전 순으로 비교
		});

	// 정렬된 단어를 출력
	for (int i = 0; i < idx; i++) {
		cout << word[i].first << "\n";
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
