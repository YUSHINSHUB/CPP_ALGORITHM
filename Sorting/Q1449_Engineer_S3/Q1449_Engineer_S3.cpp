/*
commented by ChatGPT
This C++ program calculates the minimum number of tapes required to cover all plant positions given on a line, using a priority queue to organize the plant positions in ascending order.
Given N plants along a line and a tape of length L, it strategically places tapes to cover the maximum number of plants with the least amount of tape.
It uses a min-heap priority queue to ensure the plants are considered from left to right, minimizing the number of tapes used.
For each selected plant, it covers up to L-1 positions ahead, then moves to the next uncovered plant, repeating this process until all plants are covered.
이 C++ 프로그램은 선상에 주어진 모든 식물 위치를 커버하기 위해 필요한 최소 테이프 수를 계산합니다. 우선순위 큐를 사용하여 식물 위치를 오름차순으로 정렬합니다.
N개의 식물과 길이 L의 테이프가 주어진 경우, 가능한 한 적은 양의 테이프로 최대한 많은 식물을 커버하기 위해 전략적으로 테이프를 배치합니다.
최소 힙 우선순위 큐를 사용하여 식물을 왼쪽에서 오른쪽으로 고려하도록 하여 사용되는 테이프의 수를 최소화합니다.
각 선택된 식물에 대해, 앞으로 L-1 위치까지 커버한 다음 다음에 커버되지 않은 식물로 이동하여 이 과정을 모든 식물이 커버될 때까지 반복합니다.
*/

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	priority_queue<int, vector<int>, greater<int>> pq; // A min-heap priority queue to store the positions of the plants in ascending order.
	int N, L, cur, res = 0; // N: Number of plants, L: Length of the tape, cur: Current position considered, res: Number of tapes required.

	cin >> N >> L; // Taking input for the number of plants and the length of the tape.

	for (int i = 0; i < N; i++) { // Loop to input the positions of all plants.
		int in;
		cin >> in; // Taking input for each plant's position.
		pq.push(in); // Adding the position to the priority queue.
	}

	while (!pq.empty()) { // Loop until all plant positions are considered.
		cur = pq.top() + L - 1; // Calculating the farthest position the current tape can cover.
		pq.pop(); // Removing the current position from the priority queue.
		res++; // Incrementing the number of tapes used.
		if (pq.empty()) // If there are no more positions left, break out of the loop.
			break;
		while (!pq.empty() && pq.top() <= cur) { // Loop to skip all positions covered by the current tape.
			pq.pop(); // Removing positions covered by the current tape.
			if (pq.empty()) // If there are no more positions left, break out of the loop.
				break;
		}
	}

	cout << res; // Printing the number of tapes required.
}
