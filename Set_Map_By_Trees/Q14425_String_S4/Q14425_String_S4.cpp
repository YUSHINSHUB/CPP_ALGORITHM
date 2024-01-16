#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <map>

using namespace std;

int main() {

	int n;
	int m;
	int cnt = 0;
	string temp;
	map<string, bool> strmap;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		strmap.insert(pair<string, bool>(temp, true));
	}

	for (int i = 0; i < m; i++) {
		cin >> temp;
		if (strmap[temp] == true) {
			//입력받은 문자열을 key로 갖는 해시맵의 value가 true일 경우 결과값을 1 올려준다.
			// java에서는 위와 같은 방법으로 서치할 경우 해시맵에 해당 key가 존재하지 않을때
			// 오류가 발생하기 때문에 containsKey() 함수를 사용해야 한다.
			cnt++;
		}
	}

	cout << cnt;


}