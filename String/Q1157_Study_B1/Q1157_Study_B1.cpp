#include <iostream>

using namespace std;
int main()
{
	string in;
	cin >> in;

	int arr[26];
	fill_n(arr, 26, 0);
	int m = 0;
	int mpos = -1;

	for (int i = 0; i < in.length(); i++) {
		if (in[i] >= 65 && in[i] <= 90) {
			arr[in[i] - 65]++;
			if (m < arr[in[i] - 65]) {
				mpos = in[i] - 65;
				m = arr[in[i] - 65];
			}
			else if (m == arr[in[i] - 65]) mpos = -1;
		}
		else {
			arr[in[i] - 97]++;
			if (m < arr[in[i] - 97]) {
				mpos = in[i] - 97;
				m = arr[in[i] - 97];
			}
			else if (m == arr[in[i] - 97]) mpos = -1;
		}

	}

	if (mpos == -1) cout << "?";
	else cout << (char)(mpos + 65);
}