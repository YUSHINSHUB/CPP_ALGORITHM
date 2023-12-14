#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string str[2];
	cin >> str[0] >> str[1];
	int n = stoi(str[0]);
	int x = stoi(str[1]);

	vector<int> arr(n);
	vector<int> out(n);

	int leng = 0;

	for (int a = 0; a < n; a++) {
		cin >> arr[a];
	}

	for (int a = 0; a < n; a++) {
		if (arr[a] < x) {
			out[leng] = arr[a];
			leng++;
		}
	}

	out.resize(leng);
	//java.util 패키지에 있는 arrays클래스의 메소드 copyOf를 사용하여 출력할 값의 수에 맞게 배열의 크기를 조정한다

	for (int a = 0; a < leng; a++) {
		cout << out[a] << " ";
	}
}
