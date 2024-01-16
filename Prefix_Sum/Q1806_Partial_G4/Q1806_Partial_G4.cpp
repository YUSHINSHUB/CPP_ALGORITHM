/*
commented by ChatGPT
This C++ code implements an efficient algorithm to find the minimum length of a contiguous subarray whose sum is greater than or equal to a given number S.
The algorithm uses a sliding window technique to iterate through an array of N integers. It continuously adds elements to a cumulative sum and expands the window size (idx).
When the sum becomes greater than or equal to S, the code contracts the window from the left side (st) to determine the smallest subarray length that meets the condition.
The smallest length found is stored in res. If no such subarray is found that satisfies the condition, the code outputs 0.

이 C++ 코드는 주어진 숫자 S 이상의 합을 가진 연속된 부분 배열의 최소 길이를 효율적으로 찾는 알고리즘을 구현합니다. 알고리즘은 N개의 정수 배열을 순회하면서 슬라이딩 윈도우 기법을 사용합니다.
요소들을 누적 합계에 지속적으로 더하고 윈도우 크기(idx)를 확장합니다. 합계가 S 이상이 되면 코드는 왼쪽에서부터 윈도우를 축소(st)하여 조건을 만족하는 가장 작은 부분 배열 길이를 결정합니다.
찾아진 가장 작은 길이는 res에 저장됩니다. 조건을 만족하는 부분 배열이 없는 경우 코드는 0을 출력합니다.
*/

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int N, S;
	int sum = 0;
	int idx = 0;
	int st = 0;
	int res = 100001; // 초기 결과 값을 큰 수로 설정
	int list[100000];

	cin >> N >> S; // 배열의 크기와 목표 합 입력

	for (int i = 0; i < N; i++) {
		cin >> list[i];
		sum += list[i];
		idx++;
		if (sum >= S) {
			while (sum >= S) {
				sum -= list[st];
				st++;
				idx--;
			}
			st--;
			sum += list[st];
			idx++;
			if (res > idx) // 최소 길이 갱신
				res = idx;
		}
	}

	if (res > 100000) // 조건을 만족하는 부분 배열이 없는 경우
		cout << "0";
	else
		cout << res;
}