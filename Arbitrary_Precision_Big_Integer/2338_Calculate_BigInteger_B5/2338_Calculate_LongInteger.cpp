// 2338_Calculate_LongInteger.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
//리뉴얼버전

#include <iostream>
#include <cstring>

using namespace std;


bool compare(char* a, char* b) {
	//a가 b보다 크거나 같을경우 true, b가 클경우 false 반환

	if (strlen(a) > strlen(b)) {
		return true;
	}
	else if (strlen(a) < strlen(b)) {
		return false;
	}
	else {
		for (int i = 0; i < strlen(a); i++) {
			if (a[i] > b[i]) {
				return true;
			}
			else if (a[i] < b[i]) {
				return false;
			}
		}
	}

	return true;
}

void add(char* a, char* b, char* res, bool pm) {
	//더하기 메소드

	int gap = strlen(a) - strlen(b);

	for (int i = 0; i <= strlen(a); i++) {
		res[i] = '0';
	}
	// 더하기 연산을 활용할 것이므로 디폴트로 0을 대입해준다.

	for (int i = strlen(a) - 1; i >= gap; i--) {
		int z = i + 1;
		// 더하기는 자릿수가 더 커질 수 있기 때문에 한칸 뒤에 결과값을 넣어준다.
		int r = (a[i] - '0') + (b[i - gap] - '0');
		if (r < 10) {
			res[z] += r;
		}
		else {
			res[z] += r - 10;
			res[z - 1]++;
		}
		for (int x = strlen(a); x >= i; x--) {
			if (res[x] > '9') {
				res[x] -= 10;
				res[x - 1]++;
			}
		}

	}

	for (int i = gap - 1; i >= 0; i--) {
		int z = i + 1;
		int r = (a[i] - '0') + (res[z] - '0');
		if (r < 10) {
			res[z] = r + '0';
		}
		else {
			res[z] = r - 10 + '0';
			res[z - 1]++;
		}
	}

	bool zrchk = false;

	for (int i = 0; i < strlen(a) + 1; i++) {
		if (res[i] > '9') {
			res[i] -= 10;
			res[i - 1]++;
		}
		if (res[i] != '0') {
			zrchk = true;
		}
	}

	if (zrchk == false) {
		res[0] = '0';
		res[1] = '\0';
		return;
	}

	if (pm == true) {
		if (res[0] == '0') {
			for (int i = 0; i < strlen(a); i++) {
				res[i] = res[i + 1];
			}
			res[strlen(a)] = '\0';
		}
		else {
			res[strlen(a) + 1] = '\0';
		}
	}
	else {
		if (res[0] == '0') {
			res[0] = '-';
			res[strlen(a) + 1] = '\0';

		}
		else {
			for (int i = strlen(a) + 1; i > 0; i--) {
				res[i] = res[i - 1];
			}
			res[0] = '-';
			res[strlen(a) + 2] = '\0';
		}
	}

}

void subtract(char* a, char* b, char* res, bool pm) {

	int gap = strlen(a) - strlen(b);

	for (int i = 0; strlen(a) >= i; i++) {
		res[i] = '0';
	}

	for (int i = strlen(a) - 1; i >= gap; i--) {
		int r = (a[i] - '0') - (b[i - gap] - '0');
		if (r >= 0) {
			res[i + 1] += r;
		}
		else {
			res[i + 1] += r + 10;
			res[i]--;
		}

		for (int x = strlen(a); x >= i; x--) {
			if (res[x] < '0') {
				res[x] += 10;
				res[x - 1]--;
			}
		}
	}

	for (int i = gap - 1; i >= 0; i--) {
		res[i + 1] += a[i] - '0';
	}


	int range = 1;
	bool zrchk = false;

	while (range == 1) {

		range = 0;
		zrchk = false;

		for (int i = 0; i <= strlen(a); i++) {
			if (res[i] > '9') {
				res[i] -= 10;
				res[i - 1]++;
				range = 1;
			}
			else if (res[i] < '0') {
				res[i] += 10;
				res[i - 1]--;
				range = 1;
			}

			if (res[i] != '0') {
				zrchk = true;
			}
		}
	}

	if (zrchk == false) {
		res[0] = '0';
		res[1] = '\0';
		return;
	}

	int chk = 0;
	while (res[chk] == '0') {
		chk++;
	}

	if (pm == true) {
		if (chk == 0) {
			res[strlen(a) + 1] = '\0';
		}
		else {
			for (int i = 0; i <= strlen(a) - chk; i++) {
				res[i] = res[i + chk];
			}
			res[strlen(a) + 1 - chk] = '\0';
		}
	}
	else {
		if (chk == 0) {
			for (int i = strlen(a); i >= 0; i--) {
				res[i + 1] = res[i];
			}
			res[0] = '-';
			res[strlen(a) + 2] = '\0';
		}
		else {
			for (int i = 1; i <= strlen(a) + 1 - chk; i++) {
				res[i] = res[i + chk - 1];
			}
			res[0] = '-';
			res[strlen(a) + 2 - chk] = '\0';
		}
	}

}

void multiply(char* a, char* b, char* res, bool pm) {

	if (a[0] == '0' || b[0] == '0') {
		res[0] = '0';
		res[1] = '\0';
		return;
	}

	int strsum = strlen(a) + strlen(b) + 1;

	for (int i = 0; i <= strsum; i++) {
		res[i] = '0';
	}

	for (int i = 0; i < strlen(a); i++) {

		for (int z = 0; z < strlen(b); z++) {

			int x = strsum - i - z;
			int r = (a[strlen(a) - 1 - i] - '0') * (b[strlen(b) - 1 - z] - '0');
			res[x] += r % 10;
			res[x - 1] += r / 10;

			while (res[x] > '9') {
				res[x] -= 10;
				res[x - 1]++;
			}

			while (res[x - 1] > '9') {
				res[x - 1] -= 10;
				res[x - 2]++;
			}

		}
	}
	int chk = 0;

	while (chk != strlen(a) + strlen(b) + 1) {
		if (res[chk + 1] > '9') {
			res[chk + 1] -= 10;
			res[chk]++;
			chk = 0;
		}
		else {
			chk++;
		}

	}

	chk = 0;

	while (res[chk] == '0') {
		chk++;
	}

	if (pm == true) {
		for (int i = 0; i <= strsum - chk; i++) {
			res[i] = res[i + chk];
		}
		res[strsum + 1 - chk] = '\0';
	}
	else {
		for (int i = 1; i <= strsum - chk + 1; i++) {
			res[i] = res[i + chk - 1];
		}
		res[0] = '-';
		res[strsum - chk + 2] = '\0';
	}

}





int main()
{
//	while (1) {
		char a[1002];
		char b[1002];

		cin >> a;
		cin >> b;

		bool ax = true;
		bool bx = true;


		int zc = 0;
		if (strlen(a) != 1 && a[0] == '0') {
			while (a[zc] == '0') {
				zc++;
			}
			for (int i = 0; i < strlen(a) - zc; i++) {
				a[i] = a[i + zc];
			}
			a[strlen(a) - zc] = '\0';
		}

		zc = 0;
		if (strlen(b) != 1 && b[0] == '0') {
			while (b[zc] == '0') {
				zc++;
			}
			for (int i = 0; i < strlen(b) - zc; i++) {
				b[i] = b[i + zc];
			}
			b[strlen(b) - zc] = '\0';
		}

		if (a[0] == '-') {
			ax = false;
			for (int i = 1; i < strlen(a); i++) {
				a[i - 1] = a[i];
			}
			a[strlen(a) - 1] = '\0';
		}

		if (b[0] == '-') {
			bx = false;
			for (int i = 1; i < strlen(b); i++) {
				b[i - 1] = b[i];
			}
			b[strlen(b) - 1] = '\0';
		}

		char addc[1005];
		char subc[1005];
		char mulc[2005];



		bool pm = compare(a, b);

		switch (pm) {
		case true:
			if (ax == true && bx == true) {
				//둘다 양수고 a가 더 큼
				add(a, b, addc, true);
				subtract(a, b, subc, true);
				multiply(a, b, mulc, true);
				break;
			}
			else if (ax == true && bx == false) {
				//a만 양수고 a가 더 큼
				subtract(a, b, addc, true);
				add(a, b, subc, true);
				multiply(a, b, mulc, false);
				break;
			}
			else if (ax == false && bx == true) {
				//b만 양수고 a가 더 큼
				subtract(a, b, addc, false);
				add(a, b, subc, false);
				multiply(a, b, mulc, false);
				break;
			}
			else {
				//둘다 음수고 a가 더 큼
				add(a, b, addc, false);
				subtract(a, b, subc, false);
				multiply(a, b, mulc, true);
				break;
			}
		case false:
			if (ax == true && bx == true) {
				//둘다 양수고 b가 더 큼
				add(b, a, addc, true);
				subtract(b, a, subc, false);
				multiply(a, b, mulc, true);
				break;
			}
			else if (ax == true && bx == false) {
				//a만 양수고 b가 더 큼
				subtract(b, a, addc, false);
				add(b, a, subc, true);
				multiply(a, b, mulc, false);
				break;
			}
			else if (ax == false && bx == true) {
				//b만 양수고 b가 더 큼
				subtract(b, a, addc, true);
				add(b, a, subc, false);
				multiply(a, b, mulc, false);
				break;
			}
			else {
				//둘다 음수고 b가 더 큼
				add(b, a, addc, false);
				subtract(b, a, subc, true);
				multiply(a, b, mulc, true);
				break;
			}

		}



		cout << addc << endl << subc << endl << mulc;

//	}
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
