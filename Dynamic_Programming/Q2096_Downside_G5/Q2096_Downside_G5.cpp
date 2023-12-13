
/*
commented by ChatGPT
This C++ code calculates the maximum and minimum possible sums of values read from a sequence of inputs.
The values are arranged in a sequence, and for each step, the code computes the highest and lowest possible sums considering the current and previous values.
It's a dynamic programming approach that maintains and updates the highest and lowest sums at each step based on the current input values.
이 C++ 코드는 일련의 입력에서 읽은 값의 최대 및 최소 가능한 합계를 계산합니다.
값은 순서대로 배열되며, 각 단계마다 현재 및 이전 값들을 고려하여 가능한 가장 높고 낮은 합계를 계산합니다.
현재 입력 값에 기초하여 각 단계에서 가장 높고 낮은 합계를 유지하고 업데이트하는 동적 프로그래밍 접근 방식입니다.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int N; // Number of iterations (반복 횟수)
	int in1, in2, in3; // Input values for each iteration (각 반복에 대한 입력 값)
	int hig1 = 0, hig2 = 0, hig3 = 0; // Variables to keep track of the highest sums (가장 높은 합계를 추적하는 변수)
	int low1 = 0, low2 = 0, low3 = 0; // Variables to keep track of the lowest sums (가장 낮은 합계를 추적하는 변수)

	cin >> N; // Read the number of iterations (반복 횟수 읽기)

	for (int i = 0; i < N; i++) {
		int t1, t2, t3; // Temporary variables to store intermediate sums (중간 합계를 저장하는 임시 변수)
		cin >> in1 >> in2 >> in3; // Read the input values (입력 값 읽기)
		// Calculate the highest sums (가장 높은 합계 계산)
		t1 = max(hig1, hig2) + in1;
		t2 = max(hig1, max(hig2, hig3)) + in2;
		t3 = max(hig2, hig3) + in3;
		hig1 = t1;
		hig2 = t2;
		hig3 = t3;
		// Calculate the lowest sums (가장 낮은 합계 계산)
		t1 = min(low1, low2) + in1;
		t2 = min(low1, min(low2, low3)) + in2;
		t3 = min(low2, low3) + in3;
		low1 = t1;
		low2 = t2;
		low3 = t3;
	}

	// Output the maximum and minimum sums (최대 및 최소 합계 출력)
	cout << max(hig1, max(hig2, hig3)) << " " << min(low1, min(low2, low3));
}