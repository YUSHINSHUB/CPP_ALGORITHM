
/*
commented by ChatGPT
This C++ code is designed for solving a problem of maximizing the total value of jewels that can be carried in bags with various capacities.
The code uses arrays and a priority queue to efficiently handle jewels and bags. The jpq array stores jewels as pairs of mass (m) and value (v), and bpq stores the capacities of bags.
After reading inputs for the number of jewels (N) and bags (K), and their respective data, the jewels and bags are sorted based on mass and capacity.
For each bag, the program selects jewels that fit in the bag and adds their values to a priority queue (tq), which stores the values in descending order.
The top value from tq, representing the highest value fitting the current bag, is added to the total result (res). This process is repeated for all bags, and the total value is outputted at the end.
이 C++ 코드는 다양한 용량의 가방에 최대한 많은 가치의 보석을 실을 수 있도록 하는 문제를 해결하기 위해 설계되었습니다. 이 코드는 배열과 우선순위 큐를 사용하여 보석과 가방을 효율적으로 처리합니다.
jpq 배열은 질량(m)과 가치(v) 쌍으로 보석을 저장하고, bpq는 가방의 용량을 저장합니다. 보석(N)과 가방(K)의 수와 각각의 데이터에 대한 입력을 읽은 후, 보석과 가방을 질량과 용량에 따라 정렬합니다.
각 가방에 대해, 프로그램은 가방에 맞는 보석을 선택하고 그들의 가치를 우선순위 큐(tq)에 추가합니다. 이 큐는 가치를 내림차순으로 저장합니다.
tq의 최상위 값, 즉 현재 가방에 맞는 가장 높은 가치의 보석이 총 결과(res)에 추가됩니다. 이 과정은 모든 가방에 대해 반복되며, 최종적으로 총 가치가 출력됩니다.
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K; // N: 보석의 수, K: 가방의 수
	pair<int, int> jpq[300000]; // 보석 정보 저장 (질량, 가치)
	int bpq[300000]; // 가방 용량 저장
	priority_queue<int> tq; // 보석의 가치 저장
	long long res = 0; // 총 결과 값 저장

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> jpq[i].first >> jpq[i].second;
	}
	for (int i = 0; i < K; i++) {
		cin >> bpq[i];
	}

	sort(jpq, jpq + N); // 보석을 질량 기준으로 정렬
	sort(bpq, bpq + K); // 가방을 용량 기준으로 정렬

	int jidx = 0; // 보석 배열 인덱스
	for (int i = 0; i < K; i++) {
		while (jidx < N && jpq[jidx].first <= bpq[i]) {
			tq.push(jpq[jidx].second); // 해당 가방에 들어갈 수 있는 보석의 가치를 큐에 추가
			jidx++;
		}
		if (!tq.empty()) {
			res += tq.top(); // 큐에서 가장 가치가 높은 보석을 결과에 추가
			tq.pop();
		}
	}

	cout << res; // 총 결과 출력
}