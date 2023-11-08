// Q9019_DSLR_G4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <map>

using namespace std;

int A;
int B;
bool visited[10001];
string cal[10001];

string bfs9019() {

	queue<int> q;
	fill(visited, visited + 10001, false);
	fill(cal, cal + 10001, "");

	if (A == B)
		return "";

	int t = A * 2;
	t %= 10000;
	q.push(t);
	visited[t] = true;
	cal[t] = "D";
	if (t == B)
		return "D";

	t = A - 1;
	if (t == -1)
		t = 9999;
	q.push(t);
	visited[t] = true;
	cal[t] = "S";
	if (t == B)
		return "S";

	t = A / 1000 + (A % 1000 * 10);
	q.push(t);
	visited[t] = true;
	cal[t] = "L";
	if (t == B)
		return "L";

	t = A / 10 + (A % 10 * 1000);
	q.push(t);
	visited[t] = true;
	cal[t] = "R";
	if (t == B)
		return "R";

	while (true) {
		t = q.front();
		q.pop();

		int temp = t * 2;
		temp %= 10000;
		if (temp == B)
			return cal[t] + "D";
		else if (!visited[temp]) {
			visited[temp] = true;
			q.push(temp);
			cal[temp] = cal[t] + "D";
		}

		temp = t - 1;
		if (temp == -1)
			temp = 9999;

		if (temp == B)
			return cal[t] + "S";
		else if (!visited[temp]) {
			visited[temp] = true;
			q.push(temp);
			cal[temp] = cal[t] + "S";
		}

		temp = t / 1000 + (t % 1000 * 10);
		if (temp == B)
			return cal[t] + "L";
		else if (!visited[temp]) {
			visited[temp] = true;
			q.push(temp);
			cal[temp] = cal[t] + "L";
		}

		temp = t / 10 + (t % 10 * 1000);
		if (temp == B)
			return cal[t] + "R";
		else if (!visited[temp]) {
			visited[temp] = true;
			q.push(temp);
			cal[temp] = cal[t] + "R";
		}
	}

}


int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		cout << bfs9019() << "\n";
	}

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
