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