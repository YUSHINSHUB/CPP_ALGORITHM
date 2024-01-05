/*
commented by ChatGPT
이 C++ 코드는 문자열 s 내에서 bm 문자열을 모두 제거한 후의 결과를 출력하는 코드입니다.
This C++ code outputs the result of string s after removing all occurrences of string bm.
*/

#include <iostream>
#include <deque>

using namespace std;

int main()
{
	// 사용자로부터 문자열 s와 bm을 입력받습니다. (Read strings s and bm from the user)
	string s, bm;
	cin >> s >> bm;

	bool pass = false;  // bm 문자열의 존재를 확인하기 위한 플래그 (Flag to check the existence of string bm)

	deque<char> stk;  // 문자열 처리를 위한 덱 (Deque for string processing)
	string res = "";

	// s의 각 문자에 대하여 (For each character in s)
	for (int i = 0; i < s.length(); i++) {
		stk.push_back(s[i]);  // 현재 문자를 덱에 추가합니다. (Push the current character to the deque)

		// 덱의 크기가 bm 문자열의 길이보다 크거나 같을 경우 bm 문자열의 존재를 확인합니다. (Check for the existence of string bm if the deque size is greater than or equal to the length of bm)
		if (stk.size() >= bm.length()) {
			pass = false;
			// bm의 각 문자를 덱과 비교하여 bm 문자열이 덱의 끝에 있는지 확인합니다. (Check if the string bm is at the end of the deque by comparing each character of bm with the deque)
			for (int j = 0; j < bm.length(); j++) {
				if (stk[stk.size() - bm.length() + j] != bm[j]) {
					pass = true;
					break;
				}
			}
			// 덱의 끝에 bm 문자열이 있으면 bm 문자열의 길이만큼 덱에서 문자를 제거합니다. (If the string bm is at the end of the deque, pop characters from the deque equal to the length of bm)
			if (!pass) {
				for (int j = 0; j < bm.length(); j++)
					stk.pop_back();
			}
		}
	}

	// 덱이 비어있으면 "FRULA"를 출력하고, 그렇지 않으면 덱의 내용을 결과 문자열로 출력합니다. (If the deque is empty, output "FRULA". Otherwise, output the contents of the deque as the result string)
	if (stk.empty())
		cout << "FRULA";
	else {
		for (char c : stk) {
			res += c;
		}
		cout << res;
	}
}