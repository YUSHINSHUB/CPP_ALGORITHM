/*
commented by ChatGPT
This C++ code is designed to generate a fractal pattern similar to the Sierpinski carpet. Based on user input, the code constructs and prints the fractal pattern using recursive function calls.
이 C++ 코드는 Sierpinski 카펫과 유사한 프랙탈 패턴을 생성하기 위해 설계되었습니다. 사용자 입력을 기반으로 코드는 재귀 함수 호출을 사용하여 프랙탈 패턴을 구성하고 출력합니다.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string res = "*";  // Initialize the basic pattern
// 기본 패턴 초기화
int n;

static void recur(int idx) {
	vector<string> temp;

	// Parse the current pattern into lines and store in the 'temp' vector
	// 현재 패턴을 줄로 파싱하고 'temp' 벡터에 저장합니다.
	istringstream iss(res);
	string res_buf;
	while (getline(iss, res_buf, '\n')) {
		temp.push_back(res_buf);
	}
	string t = "";

	// Add the current pattern to the top and bottom of a 3x3 grid
	// 3x3 그리드의 상단과 하단에 현재 패턴 추가
	for (int i = 0; i < temp.size(); i++) {
		for (int j = 0; j < 3; j++) {
			t.append(temp[i]);
		}
		t.append("\n");
	}

	// Add the current pattern to the sides and space in the center
	// 양쪽에 현재 패턴을 추가하고 중앙에 공간 추가
	for (int i = 0; i < temp.size(); i++) {
		t.append(temp[i]);
		for (int j = 0; j < idx / 3; j++)
			t.append(" ");
		t.append(temp[i]);
		t.append("\n");
	}

	// Again, add the current pattern to the top and bottom of a 3x3 grid
	// 다시, 3x3 그리드의 상단과 하단에 현재 패턴 추가
	for (int i = 0; i < temp.size(); i++) {
		for (int j = 0; j < 3; j++) {
			t.append(temp[i]);
		}
		t.append("\n");
	}

	res = t;  // Update the final pattern
	// 최종 패턴 업데이트
	if (n == idx)
		return;
	else
		recur(idx * 3);  // Make a recursive call, increasing the size of the pattern threefold
	// 재귀 호출을 수행하며 패턴의 크기를 세 배로 늘립니다.
}

int main()
{
	// Main execution part of the program
	// 프로그램의 주 실행 부분

	cin >> n;

	recur(3);

	cout << res;
}
