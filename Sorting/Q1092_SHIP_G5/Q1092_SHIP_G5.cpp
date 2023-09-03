
// commented by ChatGPT
// Summary: The program calculates the minimum number of trips required for ships to transport all bags, given each ship's and bag's capacity. 
//If a bag is too heavy for the largest ship, it outputs -1.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	// Read the number of ships and initialize an array to store their capacities.
	int n;
	cin >> n;
	int ship[51];

	// Input capacities of each ship.
	for (int i = 0; i < n; i++)
		cin >> ship[i];

	// Sort ship capacities in descending order for efficient allocation.
	sort(ship, ship + n, greater<int>());

	// Read the number of bags and initialize a vector to store their weights.
	int m;
	cin >> m;
	vector<int> bag(m);

	// Input weights of each bag.
	for (int i = 0; i < m; i++)
		cin >> bag[i];

	// Sort bag weights in descending order to match them with ship capacities.
	sort(bag.begin(), bag.end(), greater<int>());

	// Check if the heaviest bag is heavier than the largest ship's capacity.
	if (bag[0] > ship[0]) {
		cout << "-1"; // If so, it's impossible to transport all bags; hence, output -1.
	}
	else {
		int res = 0;  // Initialize counter for the number of trips.

		// While there are bags left to be transported.
		while (!bag.empty()) {
			int idx = 0;  // Index to keep track of the current ship being considered.

			// Iterate through the bags to allocate them to ships.
			for (int j = 0; j < m; j++) {
				// If current ship can carry the bag.
				if (ship[idx] >= bag[j]) {
					bag.erase(bag.begin() + j); // Remove the bag as it's now allocated.
					j--;
					m--;
					idx++;  // Move to the next available ship.
					if (idx == n) {  // If all ships are used up.
						break;
					}
				}
			}

			// Update the count of available ships and increment the trip counter.
			n = idx;
			res++;
		}

		// Output the minimum number of trips required to transport all bags.
		cout << res;
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
