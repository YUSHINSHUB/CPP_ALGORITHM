#include <iostream>
#include <string>
using namespace std;

int cnt[10001];
int main() {
	int n;
	scanf("%d", &n);

	int temp = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		cnt[temp] += 1;
	}

	for (int i = 1; i <= 10000; i++) {
		if (cnt[i] > 0) {
			for (int h = 0; h < cnt[i]; h++) {
				printf("%d\n", i);
			}
		}
	}
	return 0;
}