/*
commented by ChatGPT
This C++ code finds the number of circle groups that do not overlap with each other.
입력받은 원들 중 서로 겹치지 않는 원 그룹의 개수를 찾는 C++ 코드입니다.
*/

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

class circle {
public:
	int x, y, r;

	circle() {} // Default constructor (기본 생성자)

	circle(int x, int y, int r) : x(x), y(y), r(r) {} // Parameterized constructor (파라미터가 있는 생성자)

	// Function to change values of the circle object (원 객체의 값을 변경하는 함수)
	void vchange(int x, int y, int r) {
		this->x = x;
		this->y = y;
		this->r = r;
	}
};

int group[3001];          // Array to store the group status of circles (원들의 그룹 상태를 저장하는 배열)
queue<int> q[3001];       // Array of queues to store overlapping circles (겹치는 원을 저장하는 큐의 배열)
int N;                   // Number of circles (원의 개수)
int res = 0;              // Resultant number of circle groups (원 그룹의 결과 개수)

// Depth-first search to find connected circles (연결된 원을 찾기 위한 깊이 우선 탐색)
static void dfs(int idx) {
	while (!q[idx].empty()) {
		int t = q[idx].front();
		q[idx].pop();

		if (group[t] == 0) {
			group[t] = 1;
			dfs(t);
		}
	}
}

// Function to identify distinct circle groups (별개의 원 그룹을 식별하는 함수)
static void search() {
	for (int i = 0; i < N; i++) {
		if (group[i] == 0) {
			group[i] = 1;
			dfs(i);
			res++;
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		res = 0;
		circle p[3001];
		fill(group, group + N, 0); // Initialize group array for new test case (새 테스트 케이스에 대한 그룹 배열 초기화)

		for (int j = 0; j < N; j++) {
			int x, y, R;
			cin >> x >> y >> R;
			p[j].vchange(x, y, R);

			// Clear the queue for the current circle (현재 원에 대한 큐 지우기)
			while (!q[j].empty()) q[j].pop();
		}

		// Identify overlapping circles and store their indices in the queues (겹치는 원을 식별하고 그들의 인덱스를 큐에 저장)
		for (int j = 0; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				// Check if distance between circle centers is less than sum of their radii (원 중심 간의 거리가 두 원의 반지름의 합보다 작은지 확인)
				if (pow(abs(p[j].x - p[k].x), 2) + pow(abs(p[j].y - p[k].y), 2) <= pow(p[j].r + p[k].r, 2)) {
					q[j].push(k);
					q[k].push(j);
				}
			}
		}

		search(); // Identify and count distinct circle groups (별개의 원 그룹 식별 및 카운트)

		cout << res << "\n";
	}

	return 0;
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
