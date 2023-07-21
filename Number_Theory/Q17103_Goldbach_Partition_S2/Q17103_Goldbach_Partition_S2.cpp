﻿// 이 코드는 에라토스테네스의 체를 이용하여 주어진 수를 두 소수의 합으로 나타낼 수 있는 경우의 수를 찾는 
//코드입니다. 이는 골드바흐의 추측에 따라 모든 짝수는 두 소수의 합으로 나타낼 수 있다는 가정을 바탕으로 합니다. 
//코드는 입력받은 각 수에 대해 두 소수의 합으로 나타낼 수 있는 경우의 수를 계산하고, 이를 출력합니다.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n[1000001];

	// 0과 1은 소수가 아니므로 1로 설정
	n[0] = 1;
	n[1] = 1;

	// 에라토스테네스의 체를 이용하여 소수를 구함
	for (int i = 2; i < 1000001; i++) {
		if (n[i] != 1) {
			n[i] = 0;  // i가 소수일 경우 0으로 설정
			for (int z = i * 2; z < 1000001; z += i) {
				n[z] = 1;  // i의 배수는 소수가 아니므로 1로 설정
			}
		}
	}

	int t;  // 테스트 케이스의 수
	cin >> t;

	vector<int>num(t);  // 각 테스트 케이스에 해당하는 수를 저장할 벡터
	vector<int>gold(t);  // 각 수를 두 소수의 합으로 나타낼 수 있는 경우의 수를 저장할 벡터

	for (int i = 0; i < t; i++) {
		cin >> num[i];  // 각 테스트 케이스에 해당하는 수를 입력받음
		gold[i] = 0;  // 초기에 각 수를 두 소수의 합으로 나타낼 수 있는 경우의 수는 0으로 설정

		// 각 수를 두 소수의 합으로 나타낼 수 있는 경우의 수를 구함
		for (int z = 2; z <= num[i] / 2; z++) {
			if (n[z] == 0 && n[num[i] - z] == 0) {
				gold[i]++;  // z와 num[i]-z가 모두 소수일 경우, 경우의 수를 1 증가
			}
		}
	}

	// 각 수를 두 소수의 합으로 나타낼 수 있는 경우의 수를 출력
	for (int i = 0; i < t; i++) {
		cout << gold[i] << "\n";
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