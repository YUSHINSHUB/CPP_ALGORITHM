/*
	commented by ChatGPT
	Summary: The C++ program identifies a pair of numbers from an input array that, when summed, yield a value closest to zero.
	This is achieved through sorting the array and subsequently leveraging a two-pointer technique to find the desired pair.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	// Read the number of elements in the vector.
	int n;
	cin >> n;
	vector<int> sol(n);

	// Input the elements of the vector.
	for (int i = 0; i < n; i++) {
		cin >> sol[i];
	}

	// Sort the vector in ascending order.
	sort(sol.begin(), sol.end());

	// Define and initialize pointers for the current and best sums.
	int low = 0;
	int hig = n - 1;
	int clow = 0;
	int chig = n - 1;

	// Calculate the absolute sum of the current endpoints.
	int cur = abs(sol[0] + sol[n - 1]);

	// Iterate with two pointers, aiming to reduce the difference from zero.
	while (true) {
		// Break if pointers overlap or the current absolute sum is zero.
		if (clow >= chig || clow == chig - 1)
			break;
		if (cur == 0)
			break;

		// Decide which pointer to move based on which action gets the sum closer to zero.
		if (abs(sol[clow + 1] + sol[chig]) > abs(sol[clow] + sol[chig - 1])) {
			chig--;
		}
		else {
			clow++;
		}

		// Update the best found sum and its corresponding pointers if the new absolute sum is smaller.
		if (cur > abs(sol[clow] + sol[chig])) {
			low = clow;
			hig = chig;
			cur = abs(sol[clow] + sol[chig]);
		}
	}

	// Output the pair of numbers resulting in the smallest absolute sum.
	cout << sol[low] << " " << sol[hig];
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
