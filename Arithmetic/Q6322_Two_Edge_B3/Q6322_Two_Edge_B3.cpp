
/*
commented by ChatGPT
This C++ code calculates missing sides of right-angled triangles using the Pythagorean theorem.
It reads multiple sets of inputs representing the sides of a triangle (a, b, c, where c is the hypotenuse), where -1 indicates a missing side.
For each set, the program checks for possible scenarios: impossible triangle, missing hypotenuse, or missing one of the other sides.
It prints the result for each triangle or declares it impossible if the conditions are not met (e.g., non-positive side lengths, a or b greater than or equal to c).
The program terminates when an input set of 0 0 0 is received.

이 C++ 코드는 피타고라스 정리를 사용하여 직각삼각형의 누락된 변을 계산합니다.
삼각형의 변을 나타내는 여러 세트의 입력(변 a, b, c, 여기서 c는 빗변)을 읽으며, -1은 누락된 변을 나타냅니다.
각 세트에 대해, 프로그램은 불가능한 삼각형, 누락된 빗변, 또는 다른 한 변의 누락 여부를 확인합니다.
각 삼각형에 대한 결과를 출력하거나 조건이 충족되지 않으면 불가능하다고 선언합니다(예: 양수가 아닌 변 길이, a 또는 b가 c보다 크거나 같은 경우).
0 0 0의 입력 세트가 수신되면 프로그램이 종료됩니다.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int a, b, c;
	int idx = 0;

	while (true) {
		cin >> a >> b >> c;
		idx++;

		// 프로그램 종료 조건 확인
		if (a == 0 && b == 0 && c == 0)
			break;

		// 불가능한 삼각형 조건 확인
		else if (a == 0 || b == 0 || c == 0)
			cout << "Triangle #" << idx << "\n" << "Impossible.\n\n";

		// 빗변 c가 누락된 경우
		else if (c == -1) {
			cout << "Triangle #" << idx << "\n";
			cout.precision(3);
			cout << "c = " << fixed << sqrt(pow(a, 2) + pow(b, 2)) << "\n\n";
		}
		else if (a >= c || b >= c)
			cout << "Triangle #" << idx << "\n" << "Impossible.\n\n";


		// 변 a가 누락된 경우
		else if (a == -1) {
			cout << "Triangle #" << idx << "\n";
			cout.precision(3);
			cout << "a = " << fixed << sqrt(pow(c, 2) - pow(b, 2)) << "\n\n";
		}

		// 변 b가 누락된 경우
		else if (b == -1) {
			cout << "Triangle #" << idx << "\n";
			cout.precision(3);
			cout << "b = " << fixed << sqrt(pow(c, 2) - pow(a, 2)) << "\n\n";
		}
	}
}