/*
commented by ChatGPT
This C++ code generates all unique combinations of M elements from an N-element array using backtracking.
To ensure uniqueness, the code skips over consecutive duplicate elements in the sorted input array. The bt() function constructs combinations recursively.
When a combination of size M is formed, it is converted into a string and appended to sb. The visited array is used to track which elements are currently in the combination.
The input array list is sorted to group duplicate elements together, allowing the code to efficiently skip duplicates.

이 C++ 코드는 백트래킹을 사용하여 N개 요소 배열에서 M개 요소의 모든 고유 조합을 생성합니다. 고유성을 보장하기 위해 정렬된 입력 배열에서 연속적인 중복 요소를 건너뜁니다.
bt() 함수는 조합을 재귀적으로 구성합니다. 크기가 M인 조합이 형성되면 문자열로 변환되어 sb에 추가됩니다. visited 배열은 현재 조합에 포함된 요소들을 추적하는 데 사용됩니다.
입력 배열 list는 중복 요소들을 함께 그룹화하여 코드가 중복을 효율적으로 건너뛸 수 있도록 정렬됩니다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string sb = ""; // 출력을 저장할 문자열 변수
static vector<int> out; // 현재 조합을 저장하는 벡터
static int list[8]; // 입력 배열
static bool visited[8]; // 방문 여부를 추적하는 배열
static int N, M; // N: 배열의 크기, M: 조합의 크기

// 백트래킹을 사용하여 조합을 생성하는 함수
static void bt() {
	if (out.size() == M) {
		// 조합의 크기가 M과 같으면 문자열에 추가
		for (int i = 0; i < M; i++) {
			sb += to_string(out[i]) + " ";
		}
		sb += "\n";
	}
	else {
		// 재귀적으로 조합을 구성
		for (int i = 0; i < N; i++) {
			if (visited[i]) continue;
			out.push_back(list[i]);
			visited[i] = true;
			bt();
			visited[i] = false;
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
	fill(visited, visited + N, false); // 방문 배열 초기화

	bt(); // 백트래킹 시작
	cout << sb; // 결과 출력
}