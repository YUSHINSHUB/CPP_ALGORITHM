#include <iostream>
#include <deque>
using namespace std;

int main()
{
	// Read the number of people in the line
	int n;
	cin >> n;
	int idx = 1; // Index variable to track the desired order

	// Create the main queue (line) and an alternate queue (alt) to temporarily
	// store people
	deque<int> line;
	deque<int> alt;

	// Populate the main queue 'line' with the given input
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		line.push_back(temp);
	}

	// Dequeue from the main queue as long as the order is correct
	while (!line.empty() && line.front() == idx) {
		line.pop_front();
		idx++;
	}

	// This string will store our final result - "Nice" if the intended order is
	// achievable, "Sad" otherwise
	string res = "Nice";

	// Try to achieve the correct order by rearranging between the main and
	// alternate queues
	while (idx <= n) {

		if (!line.empty()) {
			if (alt.empty()) {
				// Move people from main queue to alternate queue until we find the person we're
				// looking for
				while (!line.empty() && line.front() != idx) {
					alt.push_front(line.front());
					line.pop_front();
				}
			}
			else {
				// If alt is not empty, move people around while searching for the right order
				while (!line.empty() && line.front() != idx && alt.front() != idx) {
					alt.push_front(line.front());
					line.pop_front();
				}
			}
		}

		// If the desired person is not in the front of either queues, then the order
		// isn't achievable
		if (line.empty() && (alt.empty() || alt.front() != idx)) {
			res = "Sad";
			break;
		}
		else if (!alt.empty() && alt.front() == idx) {
			// If the desired person is in front of the alternate queue, dequeue from there
			alt.pop_front();
			idx++;
		}
		else {
			// If the desired person is in front of the main queue, dequeue from there
			line.pop_front();
			idx++;
		}
	}

	// Write the result to the output
	cout << res;
}
