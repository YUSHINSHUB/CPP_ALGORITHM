// Q11051_Binomial_Coefficient_2_S2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

static int fac[1001];

static int getFac(int n) {

	if (fac[n] < 0) {
		if (fac[n - 1] < 0)
			fac[n] = (getFac(n - 1) * n) % 10007;
		else
			fac[n] = (fac[n - 1] * n) % 10007;
	}

	return fac[n];
}

int main()
{
	int n, k;
	cin >> n >> k;

	fill(fac, fac + 1001, -1);
	fac[0] = 1;

	// 페르마의 소정리에 의해 P가 소수라는 전제 하에 (A/B) % P = ( (A%P) * (B^(P-2)%P) ) % P 가 성립한다.
	// nCk % 10007 = ( n! / ( n-k )! * k! ) % 10007
	// = ( (n! % 10007) * ( ( n-k )! * k! )^10005 % 10007 ) ) % 10007와 같다.
	int fa = (getFac(n));
	int fb = (getFac(n - k) * getFac(k)) % 10007;

	int idx = 10005;
	int cur = 2;
	int kfac[10006];
	fill(kfac, kfac + 10006, -1);
	kfac[1] = fb % 10007;
	int div = 1;

	// 모듈로 연산의 분배법칙을 활용하여 거듭제곱의 나머지는 빠르게 구할 수 있다.
	// https://ko.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/fast-modular-exponentiation
	// 참고

	while (idx > 0) {

		if (cur > idx) {
			cur /= 2;
			idx -= cur;
			div = (div * kfac[cur]) % 10007;
			cur = 1;
		}

		if (kfac[cur] < 0)
			kfac[cur] = (kfac[cur / 2] * kfac[cur / 2]) % 10007;

		cur *= 2;
	}

	int res = (fa * div) % 10007;

	cout << res;
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
