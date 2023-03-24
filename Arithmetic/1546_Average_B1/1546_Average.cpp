// 1546_Average.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<vector>
#include<string>
using namespace std;

// C++에서 split() 구현
// split ( 입력받을 문자열 배열, delimiter )의 형태로 사용. delimiter을 기준으로 배열의 각 요소에 값을 담아준다.
//출처: https://bloodstrawberry.tistory.com/285
vector<string> split(string str, char delimiter)
{
	vector<string> vs;
	string temp;

	for (int i = 0; !(str[i] == 13 /* Line Feed */ || str[i] == '\n' || str[i] == 0); i++)
	{
		if (str[i] == delimiter) /* 구분자를 만나는 경우 push 후 clear */
		{
			vs.push_back(temp);
			temp.clear();

			continue;
		}

		/* temp에 문자를 하나씩 담는다. */
		temp.push_back(str[i]);
	}

	/* 마지막 string은 push되지 않았으므로 for문 밖에서 push */
	vs.push_back(temp);

	return vs;
}

int main()
{
	int n = 0;
	cin >> n;
	string nums;
	cin.ignore();
	//앞에서 n의 값을 입력받고 엔터를 눌러 줄바꿈을 하게된다. 그때 정수형의 변수는 \n을 담지 못하기 때문에 \n을 버려서 이는 입력버퍼에 남게된다.
	//입력버퍼에 남은 \n은 getline으로 전달돼서 읽어오기 때문에 cin.ignore()를 사용하여 입력버퍼를 비워주지 않으면 오류가 발생한다.

	getline(cin, nums);
	//nums에는 배열 각 점수값이 입력되며 이 값은 공백을 기준으로 배열 num에 들어간다. 그냥 cin을 사용하면 공백을 만났을 때 다음 입력항으로 넘어가게
	//되기 떄문에 nums에 한개의 점수밖에 입력할 수 없다. 그러므로 공백을 포함한 문자열을 입력해줄 필요가 있는데 이때 getline 기능을 사용할 수 있다.
	//getline은 string클래스에 포함된 메소드이며 getline ( 입력스트림 오브젝트, 입력받을 string, delimiter(구분자) ) 
	//delimiter을 만나기 전까지를 입력받으며 delimiter항을 생략할 경우 default로 \n (줄바꿈)이 사용된다.

	char delimiter = ' ';
	vector<string> num(n);
	num = split(nums, delimiter);


	float max = 0;
	float sum = 0;

	for (int i = 0; i < nums.length(); i++) {

		if (stoi(num[i]) > max) {
			max = stoi(num[i]);
		}
	}

	for (int i = 0; i < n; i++) {
		sum = sum + (stoi(num[i]) / max * 100);
	}

	float out = sum / n;

	cout << out;



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
