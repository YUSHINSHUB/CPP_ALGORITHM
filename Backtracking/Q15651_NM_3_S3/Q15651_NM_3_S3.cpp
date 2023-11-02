/*
commented by ChatGPT
This C++ code generates all possible sequences of length M from 1 to N using backtracking.
The sequences are printed with each element separated by a space.
이 C++ 코드는 백트래킹을 사용하여 1부터 N까지의 숫자로 만들 수 있는 모든 길이 M의 순열을 생성합니다.
각 요소는 공백으로 구분하여 출력됩니다.
*/

#include <iostream>
#include <deque>

using namespace std;

int N; // The range of numbers to use for sequences
int M; // The length of each sequence
deque<int> out; // A deque to store and manipulate the current sequence

// Backtracking method to generate all sequences
static void bt(int idx) {
	if (idx == M) { // Base case: if the current sequence length is M
		for (int i = 1; i <= M; i++) { // Iterate through the sequence
			int temp = out.front(); // Get the first element of the deque
			out.pop_front(); // Remove the first element
			cout << temp << " "; // Print the element followed by a space
			out.push_back(temp); // Add the element back to the end of the deque
		}
		cout << "\n"; // After printing a sequence, print a newline character
		return; // Return to explore other possibilities
	}

	for (int i = 1; i <= N; i++) { // Iterate from 1 to N
		out.push_back(i); // Add the current number to the end of the deque
		bt(idx + 1); // Recursively call bt() to add the next number
		out.pop_back(); // Remove the last element to backtrack
	}

}

// Main method
int main()
{
	cin >> N >> M; // Read N and M from the standard input
	bt(0); // Call the backtracking method starting with index 0
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
