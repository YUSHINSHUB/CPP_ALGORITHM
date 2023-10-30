/*
commented by ChatGPT
This C++ program calculates the maximum number of buildings visible from any building, based on their heights.
이 C++ 프로그램은 건물들의 높이를 기반으로, 어떤 건물에서 볼 수 있는 건물의 최대 수를 계산합니다.
*/

#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int main()
{
	int N; // Number of buildings (건물의 수)
	cin >> N;

	double bld[52]; // Heights of the buildings (건물의 높이)
	double s = 0; // Current maximum slope (현재 최대 경사도)
	int cnt = 0; // Count of buildings seen from current building (현재 건물에서 볼 수 있는 건물의 수)
	int res = 0; // Maximum count of buildings seen from any building (어떤 건물에서도 볼 수 있는 건물의 최대 수)

	for (int i = 1; i <= N; i++)
		cin >> bld[i];

	for (int i = 1; i <= N; i++) {
		cnt = 0;
		s = INT_MIN;

		// Checking the buildings to the left of current building (현재 건물의 왼쪽에 있는 건물 확인)
		for (int j = i - 1; j >= 1; j--) {
			// If the slope to a building on the left is greater than the previous slope, it blocks the view (왼쪽의 건물로의 경사도가 이전 경사도보다 크면 시야를 가림)
			if (((bld[j] - bld[i]) / abs(j - i)) > s) {
				cnt++;
				s = ((bld[j] - bld[i]) / abs(j - i));
			}
		}

		s = INT_MIN;

		// Checking the buildings to the right of current building (현재 건물의 오른쪽에 있는 건물 확인)
		for (int j = i + 1; j <= N; j++) {
			// If the slope to a building on the right is greater than the previous slope, it blocks the view (오른쪽의 건물로의 경사도가 이전 경사도보다 크면 시야를 가림)
			if (((bld[j] - bld[i]) / abs(j - i)) > s) {
				cnt++;
				s = ((bld[j] - bld[i]) / abs(j - i));
			}
		}

		// Update the result if the current building can see more buildings than the previous maximum (현재 건물이 이전 최대값보다 더 많은 건물을 볼 수 있으면 결과 업데이트)
		if (cnt > res)
			res = cnt;

	}

	cout << res; // Output the result (결과 출력)
}
