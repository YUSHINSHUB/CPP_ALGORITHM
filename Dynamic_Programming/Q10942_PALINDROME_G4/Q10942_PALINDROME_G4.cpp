/*
commented by ChatGPT
This C++ code checks whether subsegments of a given sequence of numbers form palindromes, using dynamic programming for efficient computation.
이 C++ 코드는 주어진 숫자 시퀀스의 부분 세그먼트가 회문을 형성하는지 여부를 확인합니다. 효율적인 계산을 위해 동적 프로그래밍을 사용합니다.
*/

#include <iostream>

using namespace std;

int n; // 숫자의 개수 (Number of digits in the sequence)
int pal[2001]; // 주어진 숫자 시퀀스 (The given sequence of numbers)
bool mem[2001][2001]; // 메모이제이션을 위한 배열 (Array for memoization)
bool visited[2001][2001]; // 해당 인덱스의 값이 계산되었는지 확인하는 배열 (Array to check if the value for the index has been computed)

// s부터 e까지의 숫자가 회문인지 결정하는 함수 (Function to determine if the numbers from s to e form a palindrome)
static bool dp(int s, int e) {

	if (visited[s][e])
		return mem[s][e];
	else if (s == e - 1) {
		visited[s][e] = true;
		if (pal[s] == pal[e])
			mem[s][e] = true;
		else
			mem[s][e] = false;
	}
	else if (pal[s] != pal[e]) {
		mem[s][e] = false;
		visited[s][e] = true;
	}
	else {
		mem[s][e] = dp(s + 1, e - 1);
		visited[s][e] = true;
	}

	return mem[s][e];
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n; // 첫 번째 숫자의 개수를 입력 (Input the count of first set of numbers)

	for (int i = 1; i <= n; i++) {
		cin >> pal[i];
		mem[i][i] = true;  // 같은 인덱스에서는 항상 회문 (A palindrome for the same indices)
		visited[i][i] = true;
	}

	cin >> n;  // 두 번째 숫자의 개수를 입력 (Input the count of second set of numbers)

	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;

		if (dp(s, e))
			cout << "1\n";  // 회문인 경우 (In case it's a palindrome)
		else
			cout << "0\n";  // 회문이 아닌 경우 (In case it's not a palindrome)
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
