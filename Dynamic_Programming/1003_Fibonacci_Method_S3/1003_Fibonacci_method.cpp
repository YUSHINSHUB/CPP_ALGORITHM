// 1003_Fibonacci_method.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>


using namespace std;


class fibo {
public:
    //C++에서 클래스의 각 항목별로 접근자를 지정 할 수 있다.
    int zindex, oindex;
    //멤버선언
    fibo(int zindex, int oindex) {
        //생성자
        this->zindex = zindex;
        this->oindex = oindex;
    }
};

fibo fibonacci(int n, int i) {
    //C++에서는 JAVA와 다르게 매개변수로 객체의 멤버를 사용해도 call by reference가 적용되지는 않는다.
    //그러므로 fibo클래스의 객체 자체를 리턴받는 방법을 채택.
    int temp = 0;
    int zindex = 0;
    int oindex = 0;
    if (n == 0) {
        zindex = 1;
        return fibo(zindex, oindex);
    }
    else if (n == 1) {
        oindex = 1;
        return fibo(zindex, oindex);
    }
    else {
        oindex = 1;
        for (int i = 1; i < n; i++) {
            temp = zindex + oindex;
            zindex = oindex;
            oindex = temp;
        }
        return fibo(zindex, oindex);
    }
}



int main() {

    int t;
    cin >> t;

    vector<int> n(t);
    // 배열의 크기를 변수로 지정하고 싶을 때에는 vector<타입> 배열명(크기) 의 형태로 사용.

    for (int i = 0; i < t; i++) {
        cin >> n[i];
    }

    for (int i = 0; i < t; i++) {
        fibo a = fibonacci(n[i], i);
        cout << a.zindex << " " << a.oindex << endl;
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
