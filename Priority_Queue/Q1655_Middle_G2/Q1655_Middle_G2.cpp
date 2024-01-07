/*
commented by ChatGPT
This C++ code implements a real-time median finding algorithm using two priority queues: a max-heap (max) and a min-heap (min).
The code reads a stream of integers, maintaining the heaps such that the max-heap contains the smaller half of the numbers and the min-heap contains the larger half.
After reading each number, it adjusts the heaps to maintain balance and calculates the current median.
If the heaps are of equal size, the top of the max-heap is the median.
If not, the median is the top of the heap with more elements.
This approach ensures that the median of the current set of numbers is efficiently found and printed after each input.

이 C++ 코드는 두 개의 우선순위 큐(최대 힙 'max'와 최소 힙 'min')를 사용하여 실시간 중앙값 찾기 알고리즘을 구현합니다.
코드는 정수 스트림을 읽으면서, 최대 힙이 숫자들의 작은 절반을, 최소 힙이 큰 절반을 포함하도록 유지합니다.
각 숫자를 읽은 후에는 힙을 조정하여 균형을 유지하고 현재의 중앙값을 계산합니다.
만약 두 힙의 크기가 같다면, 최대 힙의 top이 중앙값입니다.
그렇지 않다면, 더 많은 요소를 가진 힙의 top이 중앙값입니다.
이 방법은 각 입력 후 현재 숫자 세트의 중앙값을 효율적으로 찾아서 출력하도록 보장합니다.
*/

#include <iostream>
#include <queue>
using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int> max; // Max-heap to store the smaller half of numbers
	priority_queue<int, vector<int>, greater<int>> min; // Min-heap for the larger half
	int N, in;

	cin >> N >> in; // Reading the number of elements and the first element
	max.push(in); // Adding the first element to the max-heap
	cout << in << "\n"; // Outputting the first median

	for (int i = 1; i < N; i++) {
		cin >> in; // Reading a new number
		// Balancing the heaps
		if (max.size() == min.size()) {
			if (min.top() < in) {
				max.push(min.top()); // Moving the smallest element of the larger half to the smaller half
				min.pop();
				min.push(in); // Adding new element to the larger half
			}
			else {
				max.push(in); // Adding new element to the smaller half
			}
			cout << max.top() << "\n"; // Outputting the median
		}
		else {
			if (in < max.top()) {
				min.push(max.top()); // Moving the largest element of the smaller half to the larger half
				max.pop();
				max.push(in); // Adding new element to the smaller half
			}
			else {
				min.push(in); // Adding new element to the larger half
			}
			// Outputting the median based on the top elements of the heaps
			if (max.top() > min.top()) {
				cout << min.top() << "\n";
			}
			else {
				cout << max.top() << "\n";
			}
		}
	}
}