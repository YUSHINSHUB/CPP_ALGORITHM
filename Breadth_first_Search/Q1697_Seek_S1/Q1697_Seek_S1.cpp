/*
Short Summary:
This program takes two integers n and k, and calculates a minimum distance based on various rules. If n >= k,
it outputs n - k. If n < k,
it uses dynamic programming to calculate an array of distances and outputs the kth element of the distance array.

Commented by ChatGPT
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>

using namespace std;

int main()
{
	// Reading two integers from user input
	int n, k;
	cin >> n >> k;

	// If n is greater or equal to k, write n - k to output
	if (n >= k)
		cout << n - k;

	else {
		// Initialize distance array with maximum integer value
		vector<int> dis(k + 2);
		fill(dis.begin(), dis.end(), INT_MAX - 1);

		// For each number from 0 to n, set the corresponding index in the distance
		// array to n - i
		for (int i = 0; i <= n; i++) {
			dis[i] = n - i;
		}

		// For each number from n to 1, calculate a minimum distance for each of its
		// multiples of 2 up to k + 1
		for (int i = n; i >= 1; i--) {
			if (i != 0) {
				for (int j = i * 2; j <= k + 1; j *= 2) {
					if (dis[j] > dis[j / 2] + 1)
						dis[j] = dis[j / 2] + 1;
					else
						break;
				}
			}
		}

		// For each number from n + 1 to k, calculate the minimum distance considering
		// the previous and next elements and their half
		for (int i = n + 1; i <= k; i++) {
			if (i % 2 == 0)
				dis[i] = min(min(min(dis[i], dis[i - 1] + 1), dis[i + 1] + 1), dis[i / 2] + 1);
			else
				dis[i] = min(min(dis[i], dis[i - 1] + 1), dis[i + 1] + 1);

			for (int j = i * 2; j <= k + 1; j *= 2) {
				if (dis[j] > dis[j / 2] + 1)
					dis[j] = dis[j / 2] + 1;
				else
					break;
			}
		}

		// Write the kth element of the distance array to output
		cout << dis[k];
	}

}