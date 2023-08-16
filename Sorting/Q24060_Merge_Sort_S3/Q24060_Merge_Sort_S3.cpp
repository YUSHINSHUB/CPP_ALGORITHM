// Q24060_Merge_Sort_S3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> A;
vector<int> tmp;
int res = -1;
int k = 0;

// A[p..q]와 A[q+1..r]을 병합하여 A[p..r]을 오름차순 정렬된 상태로 만든다.
// A[p..q]와 A[q+1..r]은 이미 오름차순으로 정렬되어 있다.
void merge(int p, int q, int r) {
	int i = p;
	int j = q + 1;
	int t = 1;

	while (i <= q && j <= r) {
		if (A[i] <= A[j])
			tmp[t++] = A[i++]; // tmp[t] <- A[i]; t++; i++;
		else
			tmp[t++] = A[j++]; // tmp[t] <- A[j]; t++; j++;
	}
	while (i <= q) // 왼쪽 배열 부분이 남은 경우
		tmp[t++] = A[i++];
	while (j <= r) // 오른쪽 배열 부분이 남은 경우
		tmp[t++] = A[j++];

	i = p;
	t = 1;

	while (i <= r) {// 결과를 A[p..r]에 저장
		k--;
		A[i++] = tmp[t++];
		if (k == 0) {
			res = A[i - 1];
			break;
		}
	}
}

void merge_sort(int p, int r) { // A[p..r]을 오름차순 정렬한다.
	if (k == 0)
		return;
	if (p < r) {
		int q = (p + r) / 2; // q는 p, r의 중간 지점
		merge_sort(p, q); // 전반부 정렬
		merge_sort(q + 1, r); // 후반부 정렬
		merge(p, q, r); // 병합
	}
}

int main()
{
	int n;
	cin >> n >> k;

	A = vector<int>(n + 1);
	tmp = vector<int>(n + 1);

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	merge_sort(0, n - 1);

	cout << res;
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
