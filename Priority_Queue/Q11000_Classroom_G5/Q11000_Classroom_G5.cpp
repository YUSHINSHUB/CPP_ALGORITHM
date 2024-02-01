/*
	commented by ChatGPT
	Summary:
	This program calculates the minimum number of rooms required for a set of events
	based on their start and end times. Events are sorted by start times, and the
	program determines how many rooms are required without any time conflicts. The
	end time of each event in the rooms is kept in a priority queue.
*/

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	// Priority queue (min heap) to store end times of events.
	// This helps in finding the room that gets free the earliest.
	priority_queue<int, vector<int>, greater<int>> pq;

	int n;  // Number of events.
	cin >> n;

	vector<pair<int, int>> list;  // List of events represented as pairs (start time, end time).

	// Reading each event's start and end times and storing them in the list.
	for (int i = 0; i < n; i++) {
		int s, t;
		cin >> s >> t;
		list.push_back(make_pair(s, t));
	}

	// Sorting the events based on their start time.
	sort(list.begin(), list.end());

	// Adding the end time of the first event to the priority queue.
	pq.push(list[0].second);

	// For each subsequent event in the sorted list.
	for (int i = 1; i < n; i++) {
		// If the event can start after the room that gets free the earliest, we remove that room's end time.
		if (pq.top() <= list[i].first) {
			pq.pop();
		}
		// We add the end time of the current event to the priority queue.
		pq.push(list[i].second);
	}

	// Displaying the total number of rooms required.
	cout << pq.size();

	return 0;
}
