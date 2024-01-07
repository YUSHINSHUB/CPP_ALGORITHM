/*
commented by ChatGPT
This C++ code uses dynamic programming to calculate the number of ways to populate a zoo with lions and tigers.
Each cage in the zoo can either be empty, have a lion, or a tiger. The program uses two arrays, mem1 and mem2, to store the number of configurations for each scenario up to the Nth cage.
mem1[i] stores the number of ways when the ith cage is empty, while mem2[i] stores the number of ways when the ith cage is not empty.
The final answer is calculated by adding the values in mem1[N] and mem2[N] and taking the modulo 9901, which is used to manage large numbers.

이 C++ 코드는 동적 프로그래밍을 사용하여 동물원에 사자와 호랑이를 배치하는 방법의 수를 계산합니다.
동물원의 각 우리는 비어 있거나, 사자가 있거나, 호랑이가 있을 수 있습니다.
프로그램은 두 개의 배열 mem1과 mem2를 사용하여 N번째 우리까지 각 시나리오에 대한 구성 수를 저장합니다.
mem1[i]는 i번째 우리가 비어 있을 때의 방법 수를 저장하고, mem2[i]는 i번째 우리가 비어 있지 않을 때의 방법 수를 저장합니다.
최종 답은 mem1[N]과 mem2[N]의 값들을 더하고 9901로 나눈 나머지를 취함으로써 계산되며, 이는 큰 수를 관리하기 위해 사용됩니다.
*/

#include <iostream>
using namespace std;

int main() {
	int N; // Number of cages in the zoo
	int mem1[100001]; // Array to store configurations with the i-th cage empty
	int mem2[100001]; // Array to store configurations with the i-th cage not empty

	cin >> N; // Reading the number of cages
	mem1[0] = 0; // Base case when no cages are present
	mem2[0] = 1; // Base case when no cages are present

	for (int i = 1; i <= N; i++) {
		// Calculating the number of configurations for i cages
		mem1[i] = (mem1[i - 1] + (mem2[i - 1] * 2)) % 9901; // Configurations when i-th cage is empty
		mem2[i] = (mem1[i - 1] + mem2[i - 1]) % 9901; // Configurations when i-th cage is not empty
	}

	// Outputting the total number of configurations for N cages modulo 9901
	cout << (mem1[N] + mem2[N]) % 9901;
}