//Commented by ChatGPT
//This program reads a sequence of integers and for each query, it calculates the sum of a subsequence of the sequence and prints it. 
//The program uses an optimized approach by computing the prefix sum of the entire sequence.


#include <iostream>
using namespace std;

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// Number of elements in the sequence
	int n;
	// Number of queries
	int m;

	cin >> n >> m;

	// Create an array to store the sequence of integers
	int num[100001];
	// Create an array to store the prefix sum of the sequence
	int psum[100001];
	// Initialize the prefix sum at index 0 to be 0
	psum[0] = 0;

	// Read the sequence of integers and store it in the array num
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		// Update the prefix sum array by adding the current element to the prefix sum
		// of the previous elements
		psum[i] = psum[i - 1] + num[i];
	}

	// Process each query
	for (int i = 0; i < m; i++) {
		// Read the start and end index of the subsequence
		int a, b;
		cin >> a >> b;

		// Calculate the sum of the subsequence using the prefix sum array
		cout << psum[b] - psum[a - 1] << "\n";
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
