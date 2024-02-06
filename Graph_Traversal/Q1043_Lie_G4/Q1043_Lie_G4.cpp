/*
commented by ChatGPT
This C++ code implements an algorithm to determine the number of parties where secrets can be safely shared without involving anyone who already knows a secret.
The program takes the number of people, the number of parties, and a list of people who initially know the secret.
It then reads the composition of each party and updates the knowledge state based on the interactions.
If a person who knows the secret is part of a party, everyone in that party also learns the secret. The goal is to count the number of parties where the secret has not spread.
이 C++ 코드는 비밀을 이미 아는 사람을 포함하지 않고 안전하게 공유할 수 있는 파티의 수를 결정하는 알고리즘을 구현합니다. 프로그램은 사람 수, 파티 수, 처음에 비밀을 아는 사람들의 목록을 입력 받습니다.
그런 다음 각 파티의 구성을 읽고 상호 작용을 바탕으로 지식 상태를 업데이트합니다. 비밀을 아는 사람이 파티의 일원인 경우, 그 파티의 모든 사람도 비밀을 알게 됩니다.
목표는 비밀이 퍼지지 않은 파티의 수를 세는 것입니다.
*/

#include <iostream>
#include <vector>

using namespace std;

class party {
public:
	vector<int> mem; // 파티에 속한 사람들의 목록을 저장하는 벡터

	party() { // 기본 생성자
	}
};

int main()
{

	int N, M, knowing, temp; // N: 사람 수, M: 파티 수, knowing: 비밀을 아는 사람 수, temp: 임시 저장 변수
	bool know[51]; // 각 사람이 비밀을 알고 있는지 여부를 저장하는 배열
	vector<party> plist; // 파티 목록을 저장하는 벡터

	fill(know, know + 51, false); // know 배열을 false로 초기화
	cin >> N >> M;

	cin >> knowing; // 비밀을 아는 사람의 수를 입력 받음
	for (int i = 1; i <= knowing; i++) {
		cin >> temp;
		know[temp] = true; // 비밀을 아는 사람을 true로 설정
	}

	for (int i = 0; i < M; i++) { // 각 파티에 대해 반복
		party p; // 파티 객체 생성
		bool b = false; // 파티에 비밀을 아는 사람이 있는지 여부를 저장하는 변수
		cin >> knowing; // 파티에 속한 사람의 수를 입력 받음
		for (int j = 1; j <= knowing; j++) { // 파티에 속한 사람에 대해 반복
			cin >> temp;
			p.mem.push_back(temp); // 파티 멤버 추가
			if (know[temp]) // 만약 이 사람이 비밀을 안다면
				b = true; // b를 true로 설정
		}
		if (b) { // 파티에 비밀을 아는 사람이 있다면
			for (int j = 0; j < knowing; j++) {
				know[p.mem[j]] = true; // 파티의 모든 멤버를 비밀을 아는 것으로 설정
			}
			M--; // 전체 파티 수에서 제외
			i--; // 수정된 파티 목록을 반복하기 위해 인덱스 감소
		}
		else {
			plist.push_back(p); // 파티 목록에 파티 추가
		}
	}

	for (int i = 0; i < M; i++) { // 수정된 파티 목록에 대해 반복
		party p = plist[i]; // 현재 파티
		bool b = false; // 파티에 비밀을 아는 사람이 있는지 여부를 저장하는 변수
		for (int j = 0; j < p.mem.size(); j++) { // 파티 멤버에 대해 반복
			if (know[p.mem[j]]) { // 만약 멤버가 비밀을 안다면
				b = true; // b를 true로 설정
				break; // 반복 중단
			}
		}
		if (b) { // 파티에 비밀을 아는 사람이 있다면
			for (int j = 0; j < p.mem.size(); j++) {
				know[p.mem[j]] = true; // 파티의 모든 멤버를 비밀을 아는 것으로 설정
			}
			plist.erase(plist.begin() + i); // 파티 목록에서 현재 파티 제거
			M--; // 전체 파티 수 감소
			i = -1; // 수정된 파티 목록을 처음부터 다시 반복하기 위해 인덱스 초기화
		}
	}

	cout << M; // 비밀이 퍼지지 않은 파티의 수 출력
}