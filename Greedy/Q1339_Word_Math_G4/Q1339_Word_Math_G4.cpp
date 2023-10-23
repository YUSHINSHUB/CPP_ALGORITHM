/*
commented by ChatGPT
This C++ code is designed to determine the maximum sum possible by assigning unique decimal values to the alphabets of a set of input words. The alphabets are assigned values based on their positional importance in the given words.
이 C++ 코드는 입력된 단어들의 알파벳에 고유한 십진수 값을 할당함으로써 가능한 최대 합계를 결정하기 위해 설계되었습니다. 알파벳에는 주어진 단어에서의 위치에 따른 중요성을 기반으로 값이 할당됩니다.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int N; // The number of words to be input (입력될 단어의 수)
	cin >> N;
	string inp[10]; // Array to store the input words (입력 단어를 저장할 배열)
	int res = 0; // The result, which is the maximum sum possible (결과, 가능한 최대 합계)
	int cnt[26]; // Array to store the importance of each alphabet (각 알파벳의 중요도를 저장하는 배열)
	int conv[26]; // Array to store the converted value of each alphabet (각 알파벳의 변환된 값을 저장하는 배열)
	int idx = 9; // Initial value to assign to the most important alphabet (가장 중요한 알파벳에 할당할 초기 값)
	fill(cnt, cnt + 26, 0); // Initialize the importance array with zeros (중요도 배열을 0으로 초기화)
	fill(conv, conv + 26, 0); // Initialize the conversion array with zeros (변환 배열을 0으로 초기화)

	// Read input words and calculate the importance of each alphabet (입력 단어 읽기 및 각 알파벳의 중요도 계산)
	for (int i = 0; i < N; i++) {
		cin >> inp[i];
		for (int j = 0; j < inp[i].length(); j++) {
			// The importance is calculated based on the position of the alphabet in the word (중요도는 단어 내의 알파벳 위치를 기반으로 계산됩니다)
			cnt[inp[i][j] - 'A'] += pow(10, inp[i].length() - j);
		}
	}

	// Assign values to alphabets based on their importance (중요도를 기반으로 알파벳에 값을 할당)
	while (true) {
		int hig = 0; // Variable to store the highest importance in each iteration (각 반복에서 가장 높은 중요도를 저장하는 변수)
		int hidx = -1; // Index of the alphabet with the highest importance (가장 높은 중요도를 갖는 알파벳의 인덱스)
		for (int i = 0; i < 26; i++) {
			// Find the alphabet with the highest importance (가장 높은 중요도를 가진 알파벳 찾기)
			if (cnt[i] > hig) {
				hig = cnt[i];
				hidx = i;
			}
		}
		if (hig == 0) // If all alphabets have been assigned values, break (모든 알파벳에 값이 할당되면 중단)
			break;
		conv[hidx] = idx; // Assign the value to the alphabet (알파벳에 값을 할당)
		cnt[hidx] = 0; // Reset the importance of the assigned alphabet (할당된 알파벳의 중요도 재설정)
		idx--; // Decrease the value for the next iteration (다음 반복을 위해 값을 감소)
	}

	// Calculate the maximum sum based on the assigned values (할당된 값에 기반하여 최대 합계 계산)
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < inp[i].length(); j++) {
			res += pow(10, inp[i].length() - j - 1) * conv[inp[i][j] - 'A'];
		}
	}

	cout << res; // Output the result (결과 출력)
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
