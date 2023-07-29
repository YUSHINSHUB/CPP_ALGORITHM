/*
Short Summary:
This program uses a priority queue to perform a specific operation m times on a set of n integers and calculates the sum of the final elements.
The operation consists of removing the smallest two elements, summing them, and adding the sum twice back to the queue.

Commented by ChatGPT
*/

#include <iostream>
#include <queue>

using namespace std;

int main()
{

	int n, m;
	cin >> n >> m;

	// Instantiate a priority queue of long integers
	priority_queue<long long, vector<long long>, greater<long long> > pq;

	long long in;

	// Populate the queue with parsed long integers from the input
	for (int i = 0; i < n; i++) {
		cin >> in;
		pq.push(in);
	}

	// If there's more than one element in the queue, perform operations
	if (n > 1) {
		// Perform m operations
		for (int i = 0; i < m; i++) {
			// For each operation, remove the smallest two elements from the queue, sum them
			long a = pq.top();
			pq.pop();
			long b = pq.top();
			pq.pop();
			a += b;

			// Add the sum back to the queue twice
			pq.push(a);
			pq.push(a);
		}
	}

	// Initialize a variable to hold the final result
	long res = 0;

	// Sum up all remaining elements in the queue
	while (!pq.empty()) {
		res += pq.top();
		pq.pop();
	}

	// Write the result to console, flush and close BufferedWriter
	cout << res;
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
