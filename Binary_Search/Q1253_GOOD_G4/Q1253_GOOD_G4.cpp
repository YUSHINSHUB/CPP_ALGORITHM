/*
commented by ChatGPT
This C++ code aims to determine the number of integers within an array that can be expressed as the sum of two distinct integers from the same array.
이 C++ 코드는 배열 내의 정수 중 두 개의 다른 정수의 합으로 표현될 수 있는 정수의 개수를 결정하는 것을 목적으로 합니다.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N; // Number of integers in the array (배열 내의 정수 개수)
	cin >> N;

	int nums[2001]; // Array to store integers (정수를 저장할 배열)
	int res = 0; // Result variable to count the valid numbers (유효한 숫자를 계산하기 위한 결과 변수)

	// Reading the array of integers (정수 배열 읽기)
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	// Sorting the array for efficient processing (효율적인 처리를 위해 배열 정렬)
	sort(nums, nums + N);

	// Checking each integer in the array (배열 내의 각 정수 확인)
	for (int i = 0; i < N; i++) {
		int s = 0; // Start index for searching (검색을 위한 시작 인덱스)
		int e = N - 1; // End index for searching (검색을 위한 끝 인덱스)
		while (true) {
			// Skipping the current index to avoid using the same number twice (동일한 숫자를 두 번 사용하지 않도록 현재 인덱스 건너뛰기)
			if (s == i) s++;
			if (e == i) e--;

			// Exit loop if start index exceeds or equals the end index (시작 인덱스가 끝 인덱스를 초과하거나 같으면 루프 종료)
			if (s >= e) break;

			// If a valid pair is found, increment the result and exit loop (유효한 쌍이 발견되면 결과 증가시키고 루프 종료)
			if (nums[s] + nums[e] == nums[i]) {
				res++;
				break;
			}
			// Adjusting start or end index based on the sum comparison (합 비교에 기초하여 시작 또는 끝 인덱스 조정)
			else if (nums[s] + nums[e] < nums[i])
				s++;
			else
				e--;
		}
	}

	// Outputting the result (결과 출력)
	cout << res;
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
