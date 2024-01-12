#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];

	sort(arr, arr + 3);

	if (arr[0] + arr[1] <= arr[2])
		arr[2] = arr[0] + arr[1] - 1;
	// 삼각형의 가장 긴 변은 나머지 두 변의 길이의 합 보다 길이가 작다.

	cout << arr[0] + arr[1] + arr[2];
}