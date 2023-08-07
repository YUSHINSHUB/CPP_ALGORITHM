/*
Commented by ChatGPT
Summary: This code reads two integer arrays and executes output based on specific conditions defined by the first array.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n; // Read the size of the arrays
	cin >> n;
	vector<int> qs; // Vector to store indices where values are 0
	vector<int> num(n); // Array to store the numbers

	int t;

	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t == 0)
			qs.push_back(i); // If the value is 0, store the index in the Vector
	}

	for (int i = 0; i < n; i++)
		cin >> num[i]; // Store the numbers in the num array

	int m; // Read the number of output elements
	cin >> m;
	vector<int> ad(m);
	for (int i = 0; i < m; i++) cin >> ad[i];

	reverse(qs.begin(), qs.end()); // Reverse the order of the Vector

	// Write the elements from the num array according to the order of the indices
	// in the ArrayList
	for (int i : qs) {
		cout << num[i] << " ";
		m--;
		if (m == 0)
			break;
	}

	// If there are still elements to output, write the elements from the last input
	// line
	if (m > 0) {
		for (int i : ad) {
			cout << i << " ";
			m--;
			if (m == 0)
				break;
		}
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
