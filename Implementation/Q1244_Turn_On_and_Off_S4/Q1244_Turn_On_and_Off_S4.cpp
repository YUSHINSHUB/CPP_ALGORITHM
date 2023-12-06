/*
commented by ChatGPT
This C++ program reads an array of switches and a series of operations to toggle them.
It supports two types of operations: toggling every k-th switch and toggling a symmetrical range of switches centered at a given index.
The final state of the switches is printed, with a line break after every 20 switches.
이 C++ 프로그램은 스위치 배열과 그것들을 토글하는 일련의 연산을 읽습니다.
두 가지 유형의 연산을 지원합니다: k번째 스위치를 토글하는 것과 주어진 인덱스를 중심으로 대칭 범위의 스위치를 토글하는 것.
최종 스위치 상태는 매 20개 스위치마다 줄 바꿈과 함께 출력됩니다.
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, T; // N: Number of switches, T: Number of operations (N: 스위치 수, T: 연산 수)

	cin >> N;
	vector<int> sch(N + 1); // Vector to store the state of switches (스위치 상태를 저장할 벡터)
	for (int i = 1; i <= N; i++) {
		cin >> sch[i]; // Read initial state of switches (스위치의 초기 상태 읽기)
	}
	cin >> T; // Read number of operations (연산 수 읽기)

	for (int i = 0; i < T; i++) {
		int gen, num; // gen: gender (1 or 2), num: switch number (gen: 성별 (1 또는 2), num: 스위치 번호)
		cin >> gen >> num;
		if (gen == 1) { // Operation type 1: Toggle every k-th switch (연산 유형 1: k번째 스위치 토글)
			for (int j = num; j <= N; j += num) {
				sch[j] = sch[j] == 1 ? 0 : 1; // Toggle the switch (스위치 토글)
			}
		}
		else { // Operation type 2: Toggle a symmetrical range of switches (연산 유형 2: 대칭 범위의 스위치 토글)
			int low = num;
			int hig = num;
			// Expand the symmetrical range (대칭 범위 확장)
			while (low > 1 && hig < N && sch[low - 1] == sch[hig + 1]) {
				low--;
				hig++;
			}
			// Toggle switches in the range (범위 내의 스위치 토글)
			for (int j = low; j <= hig; j++) {
				sch[j] = sch[j] == 1 ? 0 : 1;
			}
		}
	}

	// Output the final state of switches (스위치의 최종 상태 출력)
	for (int i = 1; i <= N; i++) {
		cout << sch[i] << " ";
		if (i % 20 == 0) // Line break after every 20 switches (20개 스위치마다 줄 바꿈)
			cout << "\n";
	}
}
