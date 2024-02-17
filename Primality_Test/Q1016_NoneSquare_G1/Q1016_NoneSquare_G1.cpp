/*
commented by ChatGPT
This C++ program calculates the number of integers within a given range [low, high] that are not divisible by the square of any integer greater than 1.
It employs a modified Sieve of Eratosthenes approach to identify these integers. Initially, all numbers in the range are considered valid (not divisible by any square greater than 1).
The program iterates through potential divisors, marking the numbers within the range that are divisible by the square of these divisors as invalid.
The count of valid (unmarked) numbers is then calculated and output.
The use of a boolean array 'era' serves as a marker for numbers divisible by any square, aiding in efficiently identifying the count of numbers not divisible by such squares.
이 C++ 프로그램은 주어진 범위 [low, high] 내에서 1보다 큰 어떤 정수의 제곱으로도 나눌 수 없는 정수의 수를 계산합니다.
이 프로그램은 수정된 에라토스테네스의 체 방식을 사용하여 이러한 정수를 식별합니다. 초기에 범위 내의 모든 숫자는 유효하다고 간주됩니다(1보다 큰 어떤 제곱으로도 나눌 수 없음).
프로그램은 가능한 나눗수를 반복하며, 이 나눗수의 제곱으로 나눌 수 있는 범위 내의 숫자를 유효하지 않은 것으로 표시합니다. 그런 다음 유효한(표시되지 않은) 숫자의 수를 계산하여 출력합니다.
부울 배열 'era'는 어떤 제곱으로도 나눌 수 있는 숫자를 표시하는 데 사용되어, 이러한 제곱으로 나눌 수 없는 숫자의 수를 효율적으로 식별하는 데 도움이 됩니다.
*/

#include <iostream>

using namespace std;

int main()
{
	long long low, hig;
	int res = 0; // Variable to store the result count
	bool era[1000001]; // Boolean array to mark numbers divisible by any square

	cin >> low >> hig;
	fill(era, era + 1000001, false); // Initialize all elements to false

	// Loop through potential squares
	for (long long i = 2; i * i <= hig; i++) {
		// Calculate the start point within the range for marking
		long long start = low + (i * i) - (low % (i * i));
		if (low % (i * i) == 0) start = low; // If low itself is divisible by the square, start from low
		for (long long j = start; j <= hig; j += i * i) {
			era[(int)(j - low)] = true; // Mark the numbers divisible by the square of i
		}
	}

	// Count unmarked numbers within the range
	for (int i = 0; i <= hig - low; i++) {
		if (!era[i]) res++; // Increment result for each unmarked number
	}

	cout << res; // Output the final result
}
