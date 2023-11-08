/*
commented by ChatGPT
This C++ code counts the number of ways a given number N can be expressed as a sum of consecutive prime numbers. 
It uses the Sieve of Eratosthenes to identify prime numbers and then finds combinations of consecutive primes that sum up to N.
이 C++ 코드는 주어진 숫자 N을 연속된 소수의 합으로 표현할 수 있는 방법의 수를 계산합니다. 
에라토스테네스의 체를 사용하여 소수를 식별한 다음 N과 같이 합해지는 연속된 소수의 조합을 찾습니다.
*/

#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N; // Input the number N (N 입력 받기)

    // Sieve of Eratosthenes array (에라토스테네스의 체 배열)
    int era[4000001]; // Assuming N can be as large as 4 million (N이 400만까지 가능하다고 가정)
    fill(era, era + N + 1, 0); // Initialize all entries to 0 (모든 항목을 0으로 초기화)
    era[1] = 1; // 1 is not a prime number (1은 소수가 아님)

    // Mark all non-prime numbers (모든 비소수 표시하기)
    for (int i = 2; i <= N; i++) {
        if (era[i] == 0) { // If i is prime (i가 소수라면)
            for (int j = i * 2; j <= N; j += i) {
                era[j] = 1; // Mark multiples of i as non-prime (i의 배수를 비소수로 표시)
            }
        }
    }

    int sum = 0; // Current sum of consecutive primes (연속된 소수의 현재 합)
    int les = 2; // Starting point for subtracting primes when over N (N을 초과할 때 소수를 빼기 시작하는 지점)
    int res = 0; // Count of the number of ways (방법의 수를 세는 변수)

    // Add primes and check for consecutive sums (소수를 더하고 연속 합을 확인하기)
    for (int i = 2; i <= N; i++) {
        if (era[i] == 0) { // If i is prime (i가 소수라면)
            sum += i; // Add it to the sum (합에 더하기)

            // Subtract the least prime until the sum is less than or equal to N (합이 N 이하가 될 때까지 가장 작은 소수를 빼기)
            while (sum > N) {
                sum -= les; // Subtract from sum (합에서 빼기)
                // Find the next least prime number (다음으로 작은 소수 찾기)
                for (int j = les + 1; j <= N; j++) {
                    if (era[j] == 0) { // If j is prime (j가 소수라면)
                        les = j; // Update les (les 업데이트)
                        break; // Exit the loop (루프를 빠져나가기)
                    }
                }
            }

            // If the sum is equal to N, increment the count (합이 N과 같다면 카운트 증가)
            if (sum == N) {
                res++;
            }
        }
    }

    cout << res; // Output the result (결과 출력하기)
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
