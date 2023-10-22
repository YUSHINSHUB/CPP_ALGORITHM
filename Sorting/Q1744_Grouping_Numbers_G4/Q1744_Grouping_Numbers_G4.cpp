/*
commented by ChatGPT
This C++ code calculates the optimal result by considering two primary operations on a series of integers: addition and multiplication.
It uses priority queues to maximize the result value.
이 C++ 코드는 일련의 정수에 대해 두 가지 주요 연산 (덧셈 및 곱셈)을 고려하여 최적의 결과를 계산합니다.
결과 값을 최대화하기 위해 우선 순위 큐를 사용합니다.
*/

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N;                  // Total number of integers (정수의 총 개수)
	cin >> N;
	int res = 0;            // Resultant value after operations (연산 후의 결과값)
	priority_queue<int> pq; // Priority queue to store the integers in descending order (정수를 내림차순으로 저장하는 우선 순위 큐)

	// Input each integer and add to the priority queue
	// 각 정수를 입력받아 우선 순위 큐에 추가
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		pq.push(temp);
	}

	// Process while the priority queue is not empty
	// 우선 순위 큐가 비어있지 않는 동안 처리
	while (!pq.empty()) {
		int a, b;
		a = pq.top();
		pq.pop();

		if (pq.empty()) {
			res += a;
			break;
		}

		b = pq.top();
		pq.pop();

		// Conditions to determine how to utilize the numbers
		// 숫자를 어떻게 활용할지 결정하기 위한 조건들
		if (a > 1 && b > 1) {
			res += a * b;
		}
		else {
			if (a >= 1 && b < 1) {
				res += a;
				pq.push(b);
				break;
			}
			else if (b == 1) {
				res += a;
				res += b;
			}
			else if (a < 1) {
				pq.push(a);
				pq.push(b);
				break;
			}
		}
	}

	// Handling remaining numbers that might be in the priority queue
	// 우선 순위 큐에 남아 있을 수 있는 나머지 숫자 처리
	if (!pq.empty()) {
		priority_queue<int, vector<int>, greater<int> > pq2; // Priority queue to store the integers in ascending order (정수를 오름차순으로 저장하는 우선 순위 큐)
		while (!pq.empty()) {
			pq2.push(pq.top());
			pq.pop();
		}
		while (!pq2.empty()) {
			int a, b;
			a = pq2.top();
			pq2.pop();
			if (pq2.empty()) {
				res += a;
				break;
			}

			b = pq2.top();
			pq2.pop();
			res += a * b;
		}
	}

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
