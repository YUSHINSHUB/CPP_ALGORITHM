/*
commented by ChatGPT
This C++ program determines whether a musical piece is in A-minor or C-major based on the input of chord names.
It counts occurrences of chords characteristic for each key and uses them to decide the key of the piece.
이 C++ 프로그램은 코드 이름의 입력을 기반으로 음악 작품이 A단조인지 C장조인지를 결정합니다.
각 조에 특징적인 코드의 발생 횟수를 계산하고 이를 사용하여 작품의 조성을 결정합니다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
	int cnt[26] = { 0, }; // Array to count the occurrences of each chord (각 코드 발생 횟수를 계산하기 위한 배열)
	int c = 0; // Counter for C-major chords (C장조 코드를 위한 카운터)
	int a = 0; // Counter for A-minor chords (A단조 코드를 위한 카운터)
	string in; // Input string containing chords separated by '|' ('|'로 구분된 코드를 포함하는 입력 문자열)
	char Delimiter = '\\|'; // Delimiter for splitting input string (입력 문자열을 분할하기 위한 구분자)

	cin >> in; // Read input string (입력 문자열 읽기)
	istringstream iss(in); // String stream for parsing the input (입력을 파싱하기 위한 문자열 스트림)
	string buffer; // Buffer to hold each chord (각 코드를 저장하기 위한 버퍼)
	vector<string> inp; // Vector to store the chords (코드를 저장하기 위한 벡터)

	while (getline(iss, buffer, Delimiter)) {
		inp.push_back(buffer); // Store each chord in the vector (각 코드를 벡터에 저장)
	}

	for (int i = 0; i < inp.size(); i++) {
		cnt[inp[i][0] - 'A']++; // Count occurrences of each chord (각 코드의 발생 횟수 계산)
	}

	c += cnt[2]; // Count C chords (C 코드 카운트)
	c += cnt[5]; // Count F chords (F 코드 카운트)
	c += cnt[6]; // Count G chords (G 코드 카운트)
	a += cnt[0]; // Count A chords (A 코드 카운트)
	a += cnt[3]; // Count D chords (D 코드 카운트)
	a += cnt[4]; // Count E chords (E 코드 카운트)

	// Compare the counts of A-minor and C-major chords to determine the key (A단조와 C장조 코드의 수를 비교하여 조성 결정)
	if (a > c)
		cout << "A-minor";
	else if (c > a)
		cout << "C-major";
	else {
		// If counts are equal, decide based on the last chord (카운트가 같다면 마지막 코드를 기반으로 결정)
		if (inp[inp.size() - 1][inp[inp.size() - 1].length() - 1] == 'A'
			|| inp[inp.size() - 1][inp[inp.size() - 1].length() - 1] == 'D' || inp[inp.size() - 1][inp[inp.size() - 1].length() - 1] == 'E')
			cout << "A-minor";
		else
			cout << "C-major";
	}

	return 0;
}
