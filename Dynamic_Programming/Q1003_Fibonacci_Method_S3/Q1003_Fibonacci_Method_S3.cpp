#include <iostream>
#include <string>
#include <vector>


using namespace std;


class fibo {
public:
	int zindex, oindex;
	fibo(int zindex, int oindex) {
		this->zindex = zindex;
		this->oindex = oindex;
	}
};

fibo fibonacci(int n, int i) {
	int temp = 0;
	int zindex = 0;
	int oindex = 0;
	if (n == 0) {
		zindex = 1;
		return fibo(zindex, oindex);
	}
	else if (n == 1) {
		oindex = 1;
		return fibo(zindex, oindex);
	}
	else {
		oindex = 1;
		for (int i = 1; i < n; i++) {
			temp = zindex + oindex;
			zindex = oindex;
			oindex = temp;
		}
		return fibo(zindex, oindex);
	}
}



int main() {

	int t;
	cin >> t;

	vector<int> n(t);

	for (int i = 0; i < t; i++) {
		cin >> n[i];
	}

	for (int i = 0; i < t; i++) {
		fibo a = fibonacci(n[i], i);
		cout << a.zindex << " " << a.oindex << endl;
	}

}