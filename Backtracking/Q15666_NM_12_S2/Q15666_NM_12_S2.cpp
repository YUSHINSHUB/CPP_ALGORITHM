/*
commented by ChatGPT
This C++ code implements a solution to generate all combinations of M elements from a sorted array of N integers, allowing repetitions but ensuring that each combination is in non-decreasing order.
The bt() function performs backtracking to build combinations. It recursively adds elements to the out vector to form combinations.
Once a combination reaches the desired size (M), it is converted into a string and appended to sb.
The function also skips over duplicate elements in the sorted input array to avoid generating the same combination more than once.

이 C++ 코드는 N개의 정수 배열에서 M개의 요소를 선택하여 조합을 생성하는 솔루션을 구현합니다.
이때 반복을 허용하지만 각 조합이 비감소 순서로 되어 있는 것을 보장합니다. bt() 함수는 백트래킹을 사용하여 조합을 구성합니다. 재귀적으로 out 벡터에 요소를 추가하여 조합을 형성합니다.
조합이 원하는 크기(M)에 도달하면 문자열로 변환되어 sb에 추가됩니다. 또한 함수는 정렬된 입력 배열에서 중복 요소를 건너뛰어 동일한 조합을 여러 번 생성하지 않도록 합니다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string sb = ""; // 출력을 저장할 문자열 변수
static vector<int> out; // 현재 조합을 저장하는 벡터
static int list[8]; // 입력 배열
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
			if (i == N - 1)
				break;
			while (list[i + 1] == list[i]) { // 중복 건너뛰기
				i++;
				if (i == N - 1)
					break;
			}
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