
/*
commented by ChatGPT
This C++ code is designed to find the number of students who cannot be part of any team based on their choices.
Each student can choose another student they wish to be teamed with, and the teams are formed if there is a loop in choices.

dfs(int idx) function: A depth-first search function to explore the choices of students.

If the student has already been visited, the function returns immediately to avoid redundancy.
Marks the current student as visited.
Recursively calls itself for the student chosen by the current student.
If the chosen student has been visited and is not part of a loop, increment out for every student in the chain forming the loop.
Marks the current student as part of a loop to avoid revisiting.
search() function: Executes dfs for every student and returns the total number of students who can't be in any team.

main method: Handles multiple test cases (T).

For each test case, reads the number of students (n) and their choices.
Initializes loop and visited arrays for each test case.
Calls search() to find the number of students not in any team and prints the result.
The algorithm's primary goal is to identify students who are not part of any loop (i.e., not in any team) by traversing through their choices.
*/

#include <iostream>
using namespace std;

static int n; // Number of students
static int out; // Number of students not in any team
static int choice[100001]; // Choices of each student
static bool visited[100001]; // Visited status of each student
static bool loop[100001]; // Loop status of each student

// Depth-first search function
static void dfs(int idx) {
	if (visited[idx]) return; // Return if already visited

	visited[idx] = true;
	int nidx = choice[idx]; // Next student chosen by current student

	if (!visited[nidx]) dfs(nidx); // Recursive DFS call

	// Increment 'out' for each student in the loop
	if (visited[nidx] && !loop[nidx]) {
		out++;
		for (int i = nidx; i != idx; i = choice[i]) out++;
	}

	loop[idx] = true; // Mark current student as part of a loop
}

// Function to calculate students not in any team
static int search() {
	for (int i = 1; i <= n; i++) {
		dfs(i); // Apply DFS on each student
	}
	return out;
}

int main() {
	int T; // Number of test cases
	cin >> T;

	for (int cs = 0; cs < T; cs++) {
		cin >> n; // Read number of students
		out = 0; // Reset counter for each test case
		fill(loop, loop + n + 1, false); // Reset loop array
		fill(visited, visited + n + 1, false); // Reset visited array
		for (int i = 1; i <= n; i++) {
			cin >> choice[i]; // Read choices
		}
		cout << n - search() << "\n"; // Output number of students not in any team
	}
}