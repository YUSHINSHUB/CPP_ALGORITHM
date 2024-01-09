
/*
commented by ChatGPT
This C++ code is a classic implementation of backtracking to generate all possible combinations of M numbers from a given array of size N.
The array list stores the input numbers, and the vector out keeps track of the current combination being built.
The bt() function recursively constructs the combinations.
If the size of out equals M, it converts the current combination into a string and appends it to sb.
Otherwise, it iterates through the list, adds each element to out, and calls bt() recursively to extend the combination further.
After the recursive call, it removes the last element from out to backtrack. The list is sorted before the backtracking process to ensure combinations are generated in non-decreasing order.

이 C++ 코드는 주어진 크기 N의 배열에서 M개의 숫자의 모든 가능한 조합을 생성하기 위해 백트래킹을 사용하는 전형적인 구현입니다.
배열 list는 입력 숫자를 저장하고, 벡터 out은 현재 구축 중인 조합을 추적합니다.
bt() 함수는 조합을 재귀적으로 구성합니다.
out의 크기가 M과 같으면 현재 조합을 문자열로 변환하여 sb에 추가합니다.
그렇지 않으면 list를 반복하여 각 요소를 out에 추가하고 bt()를 재귀적으로 호출하여 조합을 더 확장합니다.
재귀 호출 후, 백트래킹을 위해 out에서 마지막 요소를 제거합니다.
백트래킹 과정 전에 list를 정렬하여 조합이 비감소 순서로 생성되도록 합니다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string sb = ""; // 문자열로 출력을 저장할 변수
static vector<int> out; // 현재 조합을 저장하는 벡터
static int list[7]; // 입력 배열
static int N, M; // N: 배열의 크기, M: 조합의 크기

// 백트래킹을 사용하여 조합을 생성하는 함수
static void bt(int idx) {
	if (out.size() == M) {
		// 조합의 크기가 M과 같으면 문자열에 추가
		for (int i = 0; i < M; i++) {
			sb += to_string(out[i]) + " ";
		}
		sb += "\n";
	}
	else {
		// 재귀적으로 조합을 구성
		for (int i = idx; i < N; i++) {
			out.push_back(list[i]);
			bt(i);
			out.pop_back(); // 백트래킹
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); // 입출력 효율성 향상
	cin.tie(0);
	cout.tie(0);

	// 입력 처리
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	sort(list, list + N); // 입력 배열 정렬

	bt(0); // 백트래킹 시작
	cout << sb; // 결과 출력
}