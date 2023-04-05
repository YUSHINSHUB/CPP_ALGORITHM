// Q23814_Order_Fried_Rice_S3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>
using namespace std;


int main() {
	//군만두를 받는데 필요한 단위량은 세 메뉴가 모두 같기 때문에 해당 문제에서 볶음밥의 수가 
	// 최소가 되는 경우는 짬뽕, 짜장을 군만두 하나 더받을 만큼만 더 시키는 경우이다.
	long d, n, m, k;
	cin >> d >> n >> m >> k;

	long np = d - (n % d);
	long mp = d - (m % d);

	if (k >= np + mp) {
		k -= np + mp; //짬뽕과 짜장으로 각각 군만두를 하나씩 더 받기 위해 필요한 양을 합한 값이 안시킨 사람보다 적을 경우 
					//일단 필요한만큼을 더 시켰다 가정하고 k에서 합을 뺴준다.
		long kp = d - (k % d);
		if (d + kp <= np + mp) k += np + mp; //볶음밥으로 군만두를 두개 더 받을 수 있는 필요량이 짜장과 짬뽕의 추가량보다 적거나 같을 경우
										  // 짜장, 짬뽕의 추가 주문량을 모두 볶음밥으로 전환해도 군만두의 개수는 유지된다.
		else if (kp <= np || kp <= mp) k += max(np, mp); //짜장의 주문량 혹은 짬뽕의 주문량 둘중 하나라도 볶음밥의 군만두 1개 추가를
															   // 위한 필요 주문량보다 많을 경우 더 큰쪽을 볶음밥 주문으로 전환하면 군만두의
															   // 개수가 유지된다.
	}
	else if (k >= np && k >= mp) {
		long ktempn = k;
		long ktempm = k;
		ktempn -= np;
		long nkp = d - (ktempn % d);
		if (nkp <= np) ktempn += np;

		ktempm -= mp;
		long mkp = d - (ktempm % d);
		if (mkp <= mp) ktempm += mp;

		k = max(ktempn, ktempm);
	}
	else if (k >= np) {
		k -= np;
		long kp = d - (k % d);
		if (kp <= np) k += np;
	}
	else if (k >= mp) {
		k -= mp;
		long kp = d - (k % d);
		if (kp <= mp) k += mp;
	}

	cout << k;

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
