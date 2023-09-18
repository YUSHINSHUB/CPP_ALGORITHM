/*
   Commented by ChatGPT
   Summary: C++ program that reads a set of coordinates (dx, dy, dz) and calculates the number
   of points that lie inside multiple spheres with given coordinates and radii.
*/

#include <iostream>
using namespace std;

int main()
{
	// Improve the I/O speed for large number of operations
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// Read the number of points to consider
	int n;
	cin >> n;

	// Declare arrays to store the coordinates for each point
	int dx[100001];
	int dy[100001];
	int dz[100001];

	// Populate the dx, dy, dz arrays with input coordinates
	for (int i = 0; i < n; i++) {
		cin >> dx[i] >> dy[i] >> dz[i];
	}

	// Read the number of spheres to consider
	int m;
	cin >> m;

	// Iterate through each sphere and calculate how many points lie within it
	for (int i = 0; i < m; i++) {
		int x, y, z;
		long long r;  // Use long long data type as the squared radius might exceed the limit of int
		cin >> x >> y >> z >> r;
		r *= r;  // Square the radius for distance comparisons
		int res = 0;

		// Check each point's distance to the sphere's center and determine if it's inside the sphere
		for (int j = 0; j < n; j++) {
			long long a = x - dx[j];
			long long b = y - dy[j];
			long long c = z - dz[j];
			if ((a * a + b * b + c * c) <= r)
				res++;
		}
		cout << res << "\n";  // Print the result for the current sphere
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
