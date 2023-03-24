// 1271_VeryRich2_renewal2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <cstring>

using namespace std;


char* comp(char* a, char* b) {
	// 문자열 a와 b의 각 자리수 크기를 비교하여 true or false로 리턴해주는 메소드이다.

	for (int i = 0; i < strlen(b); i++) {
		if (a[i] > b[i]) {
			return a;
		}
		else if (a[i] < b[i]) {
			return b;
		}
	}

	return a;
	// if or else if가 한번도 걸리지 않았다는 것은 a의 각 자리수와 b의 각 자리수가 같다는 뜻이기 떄문에
	// 빼기연산이 가능한 것으로 판단하여 true를 리턴한다.
}

void subt(char* a, char* b) {

	for (int i = 0; i < strlen(b); i++) {
		a[i] = (a[i] - b[i]) + '0';
		if (a[i] < '0') {
			--a[i - 1];
			a[i] += 10;
		}
	}

	for (int i = strlen(b) - 1; i >= 0; i--) {
		if (a[i] < '0') {
			a[i] += 10;
			--a[i - 1];
		}
	}

}

void div(char* a, char* b, char* res, int num) {

	res[num] = '0';
	//while의 조건에 해당하지 않을경우 몫의 num번째 자리 수는 0이 된다.

	while (a[num - 1] > '0' || comp(a + num, b) == a + num) {
		subt(a + num, b);
		++res[num];
		//빼는 회수를 이용하여 몫의 각 자리의 값을 구하는 로직이다.
		//예를 들어 a가 998, b가 9일 경우 num = 0일 때 a는 '098', 몫은 '1'이 되며
		// num = 1일 떄 a는 '008', 몫은 '11'이 되며 num = 2일 때 a[2]보다 b[0]이 크기때문에
		// while문이 돌지 않고 res[2]는 0으로 유지되기 떄문에 a는 '008' b는 '110'이 된다.
	}

}


int main() {

	char a[1001];
	// 돈 
	char b[1001];
	//생명체의 수
	char res[1001] = "0";
	//몫

	int rn = 0;
	int an = 0;
	int num = 0;

	cin >> a >> b;

	if (strlen(a) > strlen(b) || ((strlen(a) == strlen(b)) && comp(a, b) == a + num)) {
		// a가 b보다 큰 경우에만 나누기 로직을 시행한다.
		while (num <= strlen(a) - strlen(b)) {
			//a와 b를 나누었을 떄 몫은 최대 'a의 길이 - b의 길이 + 1' 만큼의 자릿수를 갖게되므로
			//이를 활용하여 각 반복마다 몫의 각 자리의 수를 구하는 로직을 구성하였다.
			div(a, b, res, num++);
		}

		res[num] = '\0';

	}

	while (res[rn] == '0') {
		rn++;
	}

	while (a[an] == '0') {
		an++;
	}

	if (res[rn] == '\0') rn--;
	if (a[an] == '\0') an--;

	cout << res + rn << endl;
	cout << a + an;
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
