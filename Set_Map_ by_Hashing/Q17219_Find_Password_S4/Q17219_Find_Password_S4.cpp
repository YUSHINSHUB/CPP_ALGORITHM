//Commented by ChatGPT
//Summary: This program reads an input of key-value pairs, stores them in a HashMap, and then looks up and outputs the values for a specified set of keys.

#include <iostream>
#include <map>
using namespace std;

int main()
{
	int n; // Number of key-value pairs
	int m; // Number of keys to look up

	// Read the input for the number of key-value pairs (n) and the number of keys
		// to look up (m)
	cin >> n >> m;

	// Initialize a HashMap to store the key-value pairs
	map<string, string> hm;

	// Read the key-value pairs and store them in the HashMap
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		hm.insert(pair<string, string>(a, b)); // Store the key-value pair in the HashMap
	}

	// Look up the values for the specified keys and write them to the output
	for (int i = 0; i < m; i++) {
		string a;
		cin >> a;
		cout << hm[a] << "\n"; // Look up the value for the key and write it to the output
	}
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
