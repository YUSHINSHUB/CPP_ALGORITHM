/*
commented by ChatGPT
이 C++ 코드는 주어진 배열에서 가장 긴 바이토닉 부분 수열의 길이를 찾습니다. 
바이토닉 수열은 먼저 증가하다가 이후에 감소하는 수열을 의미합니다.
This C++ code finds the length of the longest bitonic subsequence in a given array. 
A bitonic sequence first increases and then decreases.
*/

#include <iostream>

using namespace std;

int main()
{
	int n;  // 배열의 크기 (Size of the array)
	cin >> n;
	int res = 0;  // 최장 바이토닉 부분 수열의 길이를 저장할 변수 (Variable to store the length of the longest bitonic subsequence)
	int bi[1000];  // 입력 배열 (Input array)
	int mem[1000][2];  // 메모이제이션을 위한 배열 (Array for memoization)
	int chk[1001];  // 연속된 숫자의 길이를 저장하기 위한 배열 (Array to store the length of consecutive numbers)
	fill(chk, chk + 1001, 0);

	// 숫자들을 입력받아 배열에 저장 (Store numbers in the array after taking input)
	for (int i = 0; i < n; i++) {
		cin >> bi[i];

		// 앞에서부터 현재 숫자까지의 증가하는 부분 수열의 길이 계산 (Calculate the length of increasing subsequence from the beginning to the current number)
		chk[bi[i]] = chk[bi[i] - 1] + 1;
		mem[i][0] = chk[bi[i]];

		// 증가하는 부분 수열의 길이를 업데이트 (Update the length of increasing subsequence)
		for (int j = bi[i] + 1; j <= 1000; j++) {
			if (chk[j] < chk[bi[i]])
				chk[j] = chk[bi[i]];
			else
				break;
		}
	}

	fill(chk, chk + 1001, 0);

	// 배열의 마지막 원소부터 첫 원소까지 반복 (Iterate from the last element of the array to the first)
	for (int i = n - 1; i >= 0; i--) {

		// 뒤에서부터 현재 숫자까지의 증가하는 부분 수열의 길이 계산 (Calculate the length of increasing subsequence from the end to the current number)
		chk[bi[i]] = chk[bi[i] - 1] + 1;
		mem[i][1] = chk[bi[i]];

		// 증가하는 부분 수열의 길이를 업데이트 (Update the length of increasing subsequence)
		for (int j = bi[i] + 1; j <= 1000; j++) {
			if (chk[j] < chk[bi[i]])
				chk[j] = chk[bi[i]];
			else
				break;
		}

		// 바이토닉 부분 수열의 최대 길이를 찾는다. (Find the maximum length of the bitonic subsequence)
		if (mem[i][0] + mem[i][1] > res)
			res = mem[i][0] + mem[i][1] - 1;
	}

	// 결과 출력 (Output the result)
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
