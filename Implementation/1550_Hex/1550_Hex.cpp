// 1550_Hex.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{

    char s[7];
    cin >> s;

    const char *ch = s;
    // const는 상수를 선언할 때 사용한다.
    // * (역참조 연산자)는 포인터를 선언할 때 사용된다. 포인터는 주소를 통해 값에 접근하게 해준다.
    // 지정해줄 변수의 이름 앞에 주소를 의미하는 & (ampersand)를 붙이는게 일반적이지만 배열은 그 이름 자체가 주소를 의미하기 떄문에
    // 배열 s는 &를 생략했다.
    // const와 *을 같이 사용할 경우 const는 ch에만 적용되며 *ch가 가리키는 s는 non-const이기 때문에 s의 값을 바꿔서 *ch가 가리키는 값도 변경할 수 있다. 

    cout << strtol(ch, NULL, 16);
    // strtol: 특정 진수의 수를 가지는 문자열을 10진수 long 형태로 변환한다.
    // long strtol( const char* nptr, const char** endptr, int base )
    // nptr: null로 종결되는 수식을 포함하는 문자열의 포인터
    // endptr: 변환이 멈춰진 문자열의 포인터
    // base: 변환될 문자열의 기수 (2 ~ 36진수까지 가능)

}
