#include <iostream>
#include <map>

using namespace std;

int main()
{
	// 사용자로부터 쌍의 개수 n을 입력받음
	int n;
	cin >> n;

	// 최종 결과를 저장하는 변수
	int res = 0;

	// 이름과 연결 여부를 저장하는 해쉬맵 (연결되어 있으면 1, 아니면 0)
	map<string, int> hm;
	string a, b;

	// ChongChong은 항상 연결된 그룹에 포함되므로 1로 설정
	hm.insert(pair<string, int>("ChongChong", 1));

	// n 개의 쌍을 입력받음
	for (int i = 0; i < n; i++) {
		cin >> a >> b;

		// a 또는 b가 해쉬맵에 없으면 추가하고 초기값을 0으로 설정
		if (hm.find(a) != hm.end()) {
			hm.insert(pair<string, int>(a, 0));
		}
		if (hm.find(b) != hm.end()) {
			hm.insert(pair<string, int>(b, 0));
		}

		// a가 연결된 그룹에 속하면, b도 그룹에 추가
		if (hm[a] == 1)
			hm[b] = 1;
		// 반대의 경우도 마찬가지
		else if (hm[b] == 1)
			hm[a] = 1;

	}

	// 모든 엔트리를 돌며 연결된 항목의 수를 카운트
	for (auto en : hm) {
		if (en.second == 1)
			res++;
	}

	// 결과를 출력
	cout << res;
}