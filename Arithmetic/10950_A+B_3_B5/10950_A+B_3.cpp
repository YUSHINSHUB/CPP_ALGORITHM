// 10950_A+B_3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
//using namespace std;
// std는 standard를 의미한다. 표준 네임스페이스를 사용한다는 뜻으로, cin, cout 앞에 std::를 붙이지 않아도 되게 해준다.

int main()
{
	//tkfkdgkqlek tjstodsla
	int rep = 0;
	int res = 0;
	int terms[2];

	std::cin >> rep;
	std::vector<int> out(rep);
	// C++에서 배열을 선언할 때 배열의 크기는 상수로 입력해야 한다.
	// 배열의 길이를 변수로 하고 싶은 경우에는 가변 크기의 배열인 vector를 사용할 수 있다. 

	for (int a = 0; a < rep; a++) {

		std::cin >> terms[0] >> terms[1];

		for (int b = 0; b < 2 ; b++) {

			res = res + terms[b];

		}

		out[a] = res;
		res = 0;
	}

	for (int a = 0; a < rep; a++) {
		std::cout << out[a] << std::endl;
		//endl은 줄바꿈

	}

}

