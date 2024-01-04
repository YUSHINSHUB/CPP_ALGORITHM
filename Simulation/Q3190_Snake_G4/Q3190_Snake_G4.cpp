#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int b[101][101];
	int cy = 1;
	int cx = 1;
	int vec = 1;
	int res = 0;
	bool pass = true;
	queue<int> yq;
	queue<int> xq;

	yq.push(1);
	xq.push(1);

	for (int i = 1; i <= n; i++)
		fill(b[i], b[i] + n, 0);

	int k;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int y, x;
		cin >> y >> x;
		b[y][x] = 1;
	}

	b[1][1] = 2;

	int l;
	cin >> l;

	for (int i = 0; i < l; i++) {
		int x;
		string c;
		cin >> x >> c;
		switch (vec) {
		case 1:
			for (int j = res; j < x; j++) {
				cx++;
				res++;
				if (cx > n) {
					pass = false;
					break;
				}
				else if (b[cy][cx] == 2) {
					pass = false;
					break;
				}

				if (b[cy][cx] == 1) {
					b[cy][cx] = 2;
				}
				else {
					b[cy][cx] = 2;
					b[yq.front()][xq.front()] = 0;
					yq.pop();
					xq.pop();
				}
				yq.push(cy);
				xq.push(cx);
			}
			break;
		case 2:
			for (int j = res; j < x; j++) {
				cy++;
				res++;
				if (cy > n) {
					pass = false;
					break;
				}
				else if (b[cy][cx] == 2) {
					pass = false;
					break;
				}

				if (b[cy][cx] == 1) {
					b[cy][cx] = 2;
				}
				else {
					b[cy][cx] = 2;
					b[yq.front()][xq.front()] = 0;
					yq.pop();
					xq.pop();
				}
				yq.push(cy);
				xq.push(cx);
			}
			break;
		case 3:
			for (int j = res; j < x; j++) {
				cx--;
				res++;
				if (cx < 1) {
					pass = false;
					break;
				}
				else if (b[cy][cx] == 2) {
					pass = false;
					break;
				}

				if (b[cy][cx] == 1) {
					b[cy][cx] = 2;
				}
				else {
					b[cy][cx] = 2;
					b[yq.front()][xq.front()] = 0;
					yq.pop();
					xq.pop();
				}
				yq.push(cy);
				xq.push(cx);
			}
			break;
		case 4:
			for (int j = res; j < x; j++) {
				cy--;
				res++;
				if (cy < 1) {
					pass = false;
					break;
				}
				else if (b[cy][cx] == 2) {
					pass = false;
					break;
				}

				if (b[cy][cx] == 1) {
					b[cy][cx] = 2;
				}
				else {
					b[cy][cx] = 2;
					b[yq.front()][xq.front()] = 0;
					yq.pop();
					xq.pop();
				}
				yq.push(cy);
				xq.push(cx);
			}
			break;
		}
		if (!pass)
			break;

		if (c == "D") {
			vec++;
			if (vec == 5)
				vec = 1;
		}
		else {
			vec--;
			if (vec == 0)
				vec = 4;
		}

	}

	if (pass) {
		switch (vec) {
		case 1:
			while (true) {
				cx++;
				res++;
				if (cx > n) {
					break;
				}
				else if (b[cy][cx] == 2) {
					break;
				}

				if (b[cy][cx] == 1) {
					b[cy][cx] = 2;
				}
				else {
					b[cy][cx] = 2;
					b[yq.front()][xq.front()] = 0;
					yq.pop();
					xq.pop();
				}
				yq.push(cy);
				xq.push(cx);
			}
			break;
		case 2:
			while (true) {
				cy++;
				res++;
				if (cy > n) {
					break;
				}
				else if (b[cy][cx] == 2) {
					break;
				}

				if (b[cy][cx] == 1) {
					b[cy][cx] = 2;
				}
				else {
					b[cy][cx] = 2;
					b[yq.front()][xq.front()] = 0;
					yq.pop();
					xq.pop();
				}
				yq.push(cy);
				xq.push(cx);
			}
			break;
		case 3:
			while (true) {
				cx--;
				res++;
				if (cx < 1) {
					break;
				}
				else if (b[cy][cx] == 2) {
					break;
				}

				if (b[cy][cx] == 1) {
					b[cy][cx] = 2;
				}
				else {
					b[cy][cx] = 2;
					b[yq.front()][xq.front()] = 0;
					yq.pop();
					xq.pop();
				}
				yq.push(cy);
				xq.push(cx);
			}
			break;
		case 4:
			while (true) {
				cy--;
				res++;
				if (cy < 1) {
					break;
				}
				else if (b[cy][cx] == 2) {
					break;
				}

				if (b[cy][cx] == 1) {
					b[cy][cx] = 2;
				}
				else {
					b[cy][cx] = 2;
					b[yq.front()][xq.front()] = 0;
					yq.pop();
					xq.pop();
				}
				yq.push(cy);
				xq.push(cx);
			}
			break;
		}
	}

	cout << res;
}