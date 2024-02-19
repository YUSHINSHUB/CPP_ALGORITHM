/*
commented by ChatGPT
This C++ program calculates the nth Fibonacci number modulo 1,000,000, optimized for very large values of n. 
Utilizing the Pisano period, which for modulo 10^6 is 1,500,000, the program reduces n modulo 1,500,000 to leverage the repetitive nature of Fibonacci numbers under modulo arithmetic. 
This approach ensures efficiency by preventing the need to calculate the entire sequence up to n, which can be prohibitively large. 
The program initializes a static array of size 1,500,000 to store Fibonacci numbers modulo 1,000,000, computes Fibonacci numbers up to the reduced n, and outputs the nth Fibonacci number modulo 1,000,000. 
This method is particularly effective for handling inputs that exceed the computational limits of direct Fibonacci sequence generation.
이 C++ 프로그램은 매우 큰 값의 n에 대해 최적화된 1,000,000으로 나눈 nth 피보나치 수를 계산합니다. 
10^6 모듈로에 대한 피사노 주기는 1,500,000이며, 프로그램은 n을 1,500,000으로 나누어 모듈로 연산 하에 피보나치 수의 반복적인 특성을 활용합니다. 
이 접근 방식은 n까지의 전체 시퀀스를 계산할 필요를 방지함으로써 효율성을 보장합니다. 
프로그램은 1,000,000 모듈로 피보나치 수를 저장하기 위해 크기가 1,500,000인 정적 배열을 초기화하고, 감소된 n까지 피보나치 수를 계산한 후, 1,000,000으로 나눈 nth 피보나치 수를 출력합니다. 
이 방법은 직접 피보나치 시퀀스 생성의 계산 한계를 초과하는 입력을 처리하는 데 특히 효과적입니다.
*/

#include <iostream>

using namespace std;

int main()
{
    int fib[1500000]; // Static array to store Fibonacci numbers modulo 1,000,000
    int n; // Variable to store the reduced n
    long long inp; // Variable to read the input

    cin >> inp; // Read input
    n = (int)(inp % 1500000); // Reduce input n modulo 1,500,000 due to Pisano Period
    fill(fib, fib + n + 1, 0); // Initialize the Fibonacci array with 0
    fib[1] = 1; // Base case for Fibonacci sequence
    for (int i = 2; i <= n; i++) // Calculate Fibonacci numbers up to reduced n
        fib[i] = (fib[i - 1] + fib[i - 2]) % 1000000; // Ensure each number is modulo 1,000,000

    cout << fib[n]; // Output the nth Fibonacci number modulo 1,000,000
}
