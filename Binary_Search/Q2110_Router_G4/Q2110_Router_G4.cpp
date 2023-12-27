#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


static int get(int dist, vector<int>& home, int n) {

	int cur = 0;
	int temp = 1;

	for (int i = 1; i < n; i++) {
		if (home[i] - home[cur] >= dist) {
			cur = i;
			temp++;
		}
	}

	return temp;
}

int main()
{
	int n, c;
	cin >> n >> c;

	vector<int> home(n);

	for (int i = 0; i < n; i++) {
		cin >> home[i];
	}

	sort(home.begin(), home.end());

	int lo = 1; // 공유기 사이 최소거리의 최소값은 1로 잡는다.
	int hi = home[n - 1] - home[0] + 1; // 공유기 사이 최소거리의 최댓값 
	int md = (lo + hi) / 2; // 공유기 사이 최소거리의 중간값

	while (true) {

		if (get(md, home, n) < c) {
			//md만큼 거리를 최소거리로 두었을 때 공유기를 설치할 수 있는 집의 수가 c보다 적을 경우 거리를 줄여서 설치 가능한 집의 수를 늘려야 한다.
			hi = md;
			md = (hi + lo) / 2;
		}
		else {
			lo = md + 1;
			md = (hi + lo) / 2;
		}

		if (lo == hi) break;

	}

	cout << lo - 1;

}