// Q6502_PIZZA_B2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

/*
    commented by ChatGPT
    Summary: The program determines whether various pizzas can fit on a table based on the given radius of the table and the dimensions of the pizzas.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>

using namespace std;

int main() {

    int r;           // Table's radius.
    double x, y;     // Dimensions of the pizza.
    int index = 0;   // Counter for the number of pizzas.

    while (true) {
        cin >> r;    // Read the table's radius.

        // If input radius is '0', break the loop.
        if (r == 0) {
            break;
        }

        // Read the dimensions of the pizza.
        cin >> x >> y;

        index++;     // Increase the pizza counter.

        // If the diagonal of the pizza is smaller than or equal to the table's diameter, the pizza fits.
        if (sqrt(pow(x / 2, 2) + pow(y / 2, 2)) <= r) {
            cout << "Pizza " << index << " fits on the table.\n";
        }
        else {
            cout << "Pizza " << index << " does not fit on the table.\n";
        }
    }
    return 0; // Added return statement for main function.
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
