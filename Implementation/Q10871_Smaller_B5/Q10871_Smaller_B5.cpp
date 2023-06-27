﻿// Q10871_Smaller_B5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string str[2];
	cin >> str[0] >> str[1];
	int n = stoi(str[0]);
	int x = stoi(str[1]);

	vector<int> arr(n);
	vector<int> out(n);

	int leng = 0;

	for (int a = 0; a < n; a++) {
		cin >> arr[a];
	}

	for (int a = 0; a < n; a++) {
		if (arr[a] < x) {
			out[leng] = arr[a];
			leng++;
		}
	}

	out.resize(leng);
	//java.util 패키지에 있는 arrays클래스의 메소드 copyOf를 사용하여 출력할 값의 수에 맞게 배열의 크기를 조정한다

	for (int a = 0; a < leng; a++) {
		cout << out[a] << " ";
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