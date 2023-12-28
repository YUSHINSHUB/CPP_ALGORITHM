/*
commented by ChatGPT
This C++ code is designed to sort a list of candidates based on their scores and names.
It first takes inputs for each candidate's name and three scores, then sorts them.
If scores are identical, it sorts by name length and then lexicographically.
이 C++ 코드는 후보자들의 점수와 이름을 기준으로 목록을 정렬하기 위해 작성되었습니다.
각 후보자의 이름과 세 가지 점수를 입력받은 다음, 이를 정렬합니다.
점수가 동일한 경우 이름의 길이와 사전순으로 정렬합니다.
*/

#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

string name[100000]; // Array to store names of candidates (후보자의 이름을 저장하는 배열)
int scr[100000][3]; // 2D array to store three scores of each candidate (각 후보자의 세 점수를 저장하는 2차원 배열)

// Function to compare two candidates
bool compare(int o1, int o2) {
	// First level of comparison based on the first score
	if (scr[o1][0] == scr[o2][0]) {
		// Second level of comparison based on the second score
		if (scr[o1][1] == scr[o2][1]) {
			// Third level of comparison based on the third score
			if (scr[o1][2] == scr[o2][2]) {
				// Finding minimum length of names for comparison
				int len = min(name[o1].length(), name[o2].length());
				for (int i = 0; i < len; i++) {
					// Comparing each character of the names
					if ((int)name[o1][i] == (int)name[o2][i])
						continue; // If characters are equal, continue to next character
					// If character of first name is less, then first name is smaller
					if ((int)name[o1][i] < (int)name[o2][i])
						return true;
					else
						return false; // Otherwise, second name is smaller
				}
				// If names are identical in the compared range, compare by length
				if (name[o1].length() > name[o2].length())
					return false; // Longer name is considered greater
				else
					return true; // Shorter name or equal length name is considered smaller
			}
			else {
				// If third scores are different, candidate with less score is considered smaller
				if (scr[o2][2] > scr[o1][2]) return false;
				else return true;
			}
		}
		else {
			// If second scores are different, candidate with more score is considered greater
			if (scr[o1][1] > scr[o2][1]) return false;
			else return true;
		}
	}
	else {
		// If first scores are different, candidate with more score is considered greater
		if (scr[o1][0] > scr[o2][0]) return true;
		else return false;
	}
};

int main() {
	ios_base::sync_with_stdio(false); // Fast IO optimization
	cin.tie(NULL); // Fast IO optimization
	cout.tie(NULL); // Fast IO optimization

	int N; // Number of candidates
	vector<int> res; // Vector to store indices of candidates for sorting

	cin >> N; // Reading the number of candidates

	// Reading names and scores of each candidate
	for (int i = 0; i < N; i++) {
		cin >> name[i] >> scr[i][0] >> scr[i][1] >> scr[i][2];
		res.push_back(i); // Storing index of each candidate
	}

	// Sorting the candidates using the compare function
	sort(res.begin(), res.end(), compare);

	// Outputting the sorted names
	for (int i = 0; i < N; i++) {
		cout << name[res[i]] << "\n"; // Printing names in sorted order
	}
}