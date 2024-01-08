/*
commented by ChatGPT
This C++ code implements a BFS algorithm to find the shortest path to convert a number A to a number B by using four types of operations (D, S, L, R). It utilizes a queue for the BFS process and an array to check if a number has been visited. Additionally, it uses an array to keep track of the operations performed to reach each number. The function bfs9019() encapsulates this process and is called for each test case to output the shortest sequence of operations.
이 C++ 코드는 네 가지 유형의 연산(D, S, L, R)을 사용하여 숫자 A를 숫자 B로 변환하는 최단 경로를 찾기 위해 BFS 알고리즘을 구현합니다. BFS 과정에 대한 큐와 숫자의 방문 여부를 확인하기 위한 배열을 사용합니다. 또한 각 숫자에 도달하기 위해 수행된 연산을 추적하기 위한 배열을 사용합니다. bfs9019() 함수는 이 과정을 캡슐화하며 각 테스트 케이스에 대해 연산의 최단 시퀀스를 출력하기 위해 호출됩니다.
*/

#include <iostream>
#include <queue>

using namespace std;

int A; // Starting number (시작 숫자)
int B; // Target number (목표 숫자)
bool visited[10001]; // Array to check if a number has been visited (방문한 숫자를 체크하는 배열)
string cal[10001]; // Array to store the sequence of operations (연산의 시퀀스를 저장하는 배열)

// The BFS function that returns the shortest sequence of operations (연산의 최단 시퀀스를 반환하는 BFS 함수)
string bfs9019() {
	queue<int> q; // Queue for BFS (BFS를 위한 큐)
	fill(visited, visited + 10001, false); // Initialize all visited to false (모든 visited를 false로 초기화)
	fill(cal, cal + 10001, ""); // Initialize all cal to empty string (모든 cal을 빈 문자열로 초기화)

	// If the starting number is the same as the target, return an empty string (시작 숫자가 목표와 같으면 빈 문자열 반환)
	if (A == B)
		return "";

	// Perform initial operations and push to queue (초기 연산을 수행하고 큐에 넣기)
	int t = A * 2 % 10000; // "D" operation (D 연산)
	q.push(t);
	visited[t] = true;
	cal[t] = "D";
	if (t == B)
		return "D";

	t = A - 1; // "S" operation (S 연산)
	if (t == -1)
		t = 9999;
	q.push(t);
	visited[t] = true;
	cal[t] = "S";
	if (t == B)
		return "S";

	t = A / 1000 + (A % 1000 * 10); // "L" operation (L 연산)
	q.push(t);
	visited[t] = true;
	cal[t] = "L";
	if (t == B)
		return "L";

	t = A / 10 + (A % 10 * 1000); // "R" operation (R 연산)
	q.push(t);
	visited[t] = true;
	cal[t] = "R";
	if (t == B)
		return "R";

	// Continue BFS until the queue is empty (큐가 비어있을 때까지 BFS 계속하기)
	while (!q.empty()) {
		t = q.front();
		q.pop();

		// Perform operations and check if we reached the target number (연산 수행 및 목표 숫자 도달 확인)
		int temp = t * 2 % 10000; // "D" operation (D 연산)
		if (temp == B)
			return cal[t] + "D";
		else if (!visited[temp]) {
			visited[temp] = true;
			q.push(temp);
			cal[temp] = cal[t] + "D";
		}

		temp = t - 1; // "S" operation (S 연산)
		if (temp == -1)
			temp = 9999;
		if (temp == B)
			return cal[t] + "S";
		else if (!visited[temp]) {
			visited[temp] = true;
			q.push(temp);
			cal[temp] = cal[t] + "S";
		}

		temp = t / 1000 + (t % 1000 * 10); // "L" operation (L 연산)
		if (temp == B)
			return cal[t] + "L";
		else if (!visited[temp]) {
			visited[temp] = true;
			q.push(temp);
			cal[temp] = cal[t] + "L";
		}

		temp = t / 10 + (t % 10 * 1000); // "R" operation (R 연산)
		if (temp == B)
			return cal[t] + "R";
		else if (!visited[temp]) {
			visited[temp] = true;
			q.push(temp);
			cal[temp] = cal[t] + "R";
		}
	}
	return ""; // If we didn't reach the target, return an empty string (목표에 도달하지 못했다면 빈 문자열 반환)
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T; // Number of test cases (테스트 케이스의 수)
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> A >> B; // Read the starting and target numbers (시작 숫자와 목표 숫자를 읽기)
		cout << bfs9019() << "\n"; // Print the shortest sequence of operations (최단 연산 시퀀스 출력)
	}
}
