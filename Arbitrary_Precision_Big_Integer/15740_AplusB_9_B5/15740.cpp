// 15740.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

char comp(string a, string b) {
	if (a.length() > b.length()) {
		return 'a';
	}
	else if (a.length() < b.length()) {
		return 'b';
	}
	else {
		for (int i = 0; i < a.length(); i++) {
			if (a[i] > b[i]) {
				return 'a';
			}
			else if (a[i] < b[i]) {
				return 'b';
			}
		}
		return '0';
	}
}

class str {
public:
	string a;
	string b;

	str(string a, string b) {
		this->a = a;
		this->b = b;

	}
	void rev() {
		string temp = a;
		a = b;
		b = temp;
	}
};

str instr(string a, string b) {
	return str(a, b);
}

int main() {

	string in1, in2;
	cin >> in1 >> in2;
	str s = instr(in1, in2);

	bool c1 = false, c2 = false;

	char co;
	bool chk = true;

	//음수여부 확인
	if (s.a[0] == '-') {
		s.a = s.a.substr(1, s.a.length() - 1);
		c1 = true;
	}

	if (s.b[0] == '-') {
		s.b = s.b.substr(1, s.b.length() - 1);
		c2 = true;
	}

	if (comp(s.a, s.b) == 'b') {
		co = 'b';
		//b가 절댓값이 더 클경우 a, b 교체
		s.rev();
	}
	else if (comp(s.a, s.b) == 'a') {
		co = 'a';
	}
	else {
		co = '0';
	}

	int sgap = s.a.length() - s.b.length();

	if (c1 == true && c2 == true) {
		//둘다음수
		for (int i = s.a.length() - 1; i >= sgap; i--) {
			s.a[i] += s.b[i - sgap] - 48;
			if (s.a[i] > '9') {
				if (i == 0) {
					string t = "0";
					s.a = t + s.a;
					s.a[0]++;
					s.a[1] -= 10;
					continue;
				}
				s.a[i - 1]++;
				s.a[i] -= 10;
			}
		}
		// 0 ~ 9 벗어나는 수 있을경우 정정
		while (chk == true) {
			chk = false;
			for (int i = s.a.length() - 1; i >= 0; i--) {
				if (s.a[i] > '9') {
					chk = true;
					if (i == 0) {
						string t = "0";
						s.a = t + s.a;
						s.a[i]++;
						s.a[i + 1] -= 10;
						continue;
					}
					s.a[i - 1]++;
					s.a[i] -= 10;
				}
			}
		}
		//앞에 - 붙이기
		s.a = "-" + s.a;
	}
	else if (c1 == true || c2 == true) {
		for (int i = s.a.length() - 1; i >= sgap; i--) {
			s.a[i] -= s.b[i - sgap] - 48;
			if (s.a[i] < '0') {
				s.a[i - 1]--;
				s.a[i] += 10;
			}
		}
		for (int i = s.a.length() - 1; i >= 0; i--) {
			if (s.a[i] > '9') {
				s.a[i - 1]--;
				s.a[i] += 10;
			}
		}

		while (chk == true) {
			chk = false;
			for (int i = s.a.length() - 1; i >= 0; i--) {
				if (s.a[i] > '9') {
					chk = true;
					if (i == 0) {
						string t = "0";
						s.a = t + s.a;
						i++;
					}
					s.a[i - 1]++;
					s.a[i] -= 10;
				}

				if (s.a[i] < '0') {
					chk = true;
					s.a[i - 1]--;
					s.a[i] += 10;
				}
			}
		}

		if (co == 'b' && c2 == true) {
			s.a = "-" + s.a;
		}
		else if (co == 'a' && c1 == true) {
			s.a = "-" + s.a;
		}
	}
	else {
		for (int i = s.a.length() - 1; i >= sgap; i--) {
			s.a[i] += s.b[i - sgap] - 48;
			if (s.a[i] > '9') {
				if (i == 0) {
					s.a = "0" + s.a;
					s.a[i]++;
					s.a[i + 1] -= 10;
					continue;
				}
				s.a[i - 1]++;
				s.a[i] -= 10;
			}
		}

		while (chk == true) {
			chk = false;
			for (int i = s.a.length() - 1; i >= 0; i--) {
				if (s.a[i] > '9') {
					chk = true;
					if (i == 0) {
						string t = "0";
						s.a = t + s.a;
						i++;
					}
					s.a[i - 1]++;
					s.a[i] -= 10;
				}
				if (s.a[i] < '0') {
					chk = true;
					s.a[i - 1]--;
					s.a[i] += 10;
				}
			}
		}
	}

	// 
	int zcnt = 0;
	if (s.a[0] == '-') {
		zcnt = 1;
	}

	while (s.a[zcnt] == '0') {
		zcnt++;
	}

	if (zcnt != 0) {
		if (s.a[0] == '-') {
			s.a = "-" + s.a.substr(zcnt, s.a.length() - zcnt);
		}
		else {
			s.a = s.a.substr(zcnt, s.a.length() - zcnt);
		}
	}

	if (s.a == "") {
		s.a = "0";
	}

	cout << s.a;

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
