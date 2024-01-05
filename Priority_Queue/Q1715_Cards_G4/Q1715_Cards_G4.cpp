/*
commented by ChatGPT
This C++ code finds the minimum sum of consecutive combinations when sorting cards.
이 C++ 코드는 카드를 정렬할 때 연속 조합의 최소 합을 찾습니다.
*/

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N; // Number of card bundles to be combined (조합할 카드 묶음의 수)
	cin >> N;

	int res = 0; // Result variable to store the total minimum combination sum (총 최소 조합 합을 저장하기 위한 결과 변수)
	// Priority queue with ascending order (오름차순 우선순위 큐)
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; i++) {
		int temp; // Temporary variable to store each card bundle number (각 카드 묶음 번호를 저장하기 위한 임시 변수)
		cin >> temp;
		pq.push(temp); // Pushing the card bundle number into the priority queue (우선순위 큐에 카드 묶음 번호 푸시)
	}

	// Continue until only one card bundle remains (하나의 카드 묶음만 남을 때까지 계속)
	while (pq.size() > 1) {
		int a = pq.top(); // Get the smallest card bundle (가장 작은 카드 묶음 가져오기)
		pq.pop();
		int b = pq.top(); // Get the second smallest card bundle (두 번째로 작은 카드 묶음 가져오기)
		pq.pop();

		a += b; // Combine the two smallest card bundles (두 개의 가장 작은 카드 묶음 조합)
		res += a; // Add the combined value to the result (결과에 조합된 값을 더하기)
		pq.push(a); // Push the combined card bundle back into the priority queue (조합된 카드 묶음을 다시 우선순위 큐에 푸시)
	}

	cout << res; // Print the total minimum combination sum (총 최소 조합 합 출력)
}