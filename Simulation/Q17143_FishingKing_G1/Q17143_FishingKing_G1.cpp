/*
commented by ChatGPT
This C++ code simulates a scenario where sharks of different sizes, speeds, and directions are moving in a grid representing the ocean.
A fisherman moves along the columns of the grid, capturing the first shark he encounters in each column. After each movement, sharks update their positions based on their speed and direction.
When reaching the boundary of the grid, a shark reverses its direction. If two sharks occupy the same cell after moving, the smaller shark is removed from the simulation.
The simulation keeps track of the total size of all captured sharks.
This scenario showcases object-oriented programming by defining a shark class with methods for moving and reversing direction, and utilizes a map to keep track of sharks' positions and attributes efficiently.
이 C++ 코드는 다양한 크기, 속도, 방향을 가진 상어들이 바다를 나타내는 격자에서 움직이는 시나리오를 시뮬레이션합니다. 어부는 격자의 열을 따라 이동하며, 각 열에서 처음 만나는 상어를 포획합니다.
각 움직임 후, 상어들은 그들의 속도와 방향에 따라 위치를 업데이트합니다. 격자의 경계에 도달하면 상어는 방향을 반전합니다.
움직인 후 두 상어가 동일한 셀을 점유하면 더 작은 상어가 시뮬레이션에서 제거됩니다. 시뮬레이션은 포획된 모든 상어의 총 크기를 추적합니다.
이 시나리오는 상어 클래스를 정의하여 움직임과 방향 반전에 대한 메소드를 가지고 있으며, 상어들의 위치와 속성을 효율적으로 추적하기 위해 맵을 사용하는 객체 지향 프로그래밍을 보여줍니다.
*/

#include <iostream>
#include <queue>
#include <map>

using namespace std;

class shark {
public:
	int r, c; // Current position in the grid.
	int idx; // Unique identifier for the shark.
	int speed; // Number of cells the shark moves per turn.
	int dir; // Direction of movement (1: up, 2: down, 3: right, 4: left).
	int size; // Size of the shark, used to determine outcomes when encountering other sharks.

	shark() {} // Default constructor.
	shark(int idx, int r, int c, int speed, int dir, int size) : idx(idx), r(r), c(c), speed(speed), dir(dir), size(size) {}

	void move() { // Updates shark's position based on its direction and speed.
		switch (dir) {
		case 1: r--; break; // Move up.
		case 2: r++; break; // Move down.
		case 3: c++; break; // Move right.
		case 4: c--; break; // Move left.
		}
	}

	void revdir() { // Reverses shark's direction when it hits the boundary.
		switch (dir) {
		case 1: dir = 2; break; // Up to down.
		case 2: dir = 1; break; // Down to up.
		case 3: dir = 4; break; // Right to left.
		case 4: dir = 3; break; // Left to right.
		}
	}
};

int R, C, M; // Grid dimensions (R: rows, C: columns) and number of sharks (M).
int res = 0; // Total size of sharks captured by the fisherman.
int grid[101][101]; // Represents the ocean grid with shark indices.
bool visited[101][101]; // Tracks cells visited in the current move to handle collisions.
map<int, shark> hm; // Maps shark indices to shark objects.

void sim() { // Simulates the movement of sharks and fisherman's actions.
	queue<int> rem; // Queue to hold sharks that need to be removed.

	for (int i = 1; i <= C; i++) { // Fisherman moves from column 1 to C.
		for (int j = 1; j <= R; j++)
			fill(visited[j], visited[j] + C + 1, false); // Reset visited flags.

		for (int j = 1; j <= R; j++) { // Capture the first shark in column i.
			if (grid[j][i] > 0) {
				res += hm[grid[j][i]].size; // Add shark's size to total.
				hm.erase(grid[j][i]); // Remove shark from map.
				grid[j][i] = 0; // Clear the cell.
				break; // Only one shark can be captured per column.
			}
		}

		for (auto en : hm) { // Move each shark.
			shark s = en.second;
			if (!visited[s.r][s.c])
				grid[s.r][s.c] = 0; // Clear previous position.
			for (int j = 0; j < s.speed; j++) { // Move shark according to its speed.
				if ((s.dir == 1 && s.r == 1) || (s.dir == 2 && s.r == R) || (s.dir == 3 && s.c == C) || (s.dir == 4 && s.c == 1))
					s.revdir(); // Reverse direction at grid boundaries.
				s.move(); // Move shark.
			}
			if (visited[s.r][s.c]) { // Handle collision with another shark.
				shark s2 = hm[grid[s.r][s.c]];
				if (s2.size < s.size) { // Current shark is larger.
					rem.push(s2.idx); // Mark smaller shark for removal.
					hm[s.idx] = s; // Update map with current shark.
					grid[s.r][s.c] = s.idx; // Update grid position.
				}
				else {
					rem.push(s.idx); // Mark current shark for removal if smaller.
				}
			}
			else { // No collision.
				visited[s.r][s.c] = true; // Mark cell as visited.
				hm[s.idx] = s; // Update shark's position in map.
				grid[s.r][s.c] = s.idx; // Update grid with shark's new position.
			}
		}
		while (!rem.empty()) { // Remove sharks marked for removal.
			hm.erase(rem.front());
			rem.pop();
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int r, c, s, d, z; // Temporary variables for shark attributes.

	cin >> R >> C >> M; // Input grid dimensions and number of sharks.

	for (int i = 1; i <= R; i++)
		fill(grid[i], grid[i] + C + 1, 0); // Initialize grid.

	for (int i = 1; i <= M; i++) { // Input each shark's attributes.
		cin >> r >> c >> s >> d >> z; // Row, column, speed, direction, size.
		if (d <= 2) {
			s %= (R - 1) * 2;
		}
		else {
			s %= (C - 1) * 2;
		}
		hm.insert(make_pair(i, shark(i, r, c, s, d, z))); // Create and insert shark.
		grid[r][c] = i; // Mark shark's initial position on the grid.
	}

	sim(); // Run simulation.

	cout << res; // Output total size of captured sharks.
}
