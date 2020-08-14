#include<bits/stdc++.h>
using namespace std;

int c_row = 0;
int c_col = 0;
int c_blocks = 1;
int c_moves = 0;
int init = 8;

int rowMax(int r0, int c0) {
	int sub0 = r0 - c0;
	int cnt = 0;
	int blocks = 0;
	int r1[100], c1[100];
	if (c0 <= r0) {
		for (int i = 1; i <= 8;i++) {
			for (int j = 1;j <= 8;j++) {
				int sub1 = i - j;
				if ((sub1 == sub0) && (i != r0)) {
					r1[cnt] = i;
					c1[cnt] = j;
					cnt++;
				}
			}
		}
	}
	blocks = cnt + 1;
	int* i1;
	i1 = std::max_element(r1, r1 + cnt);
	c_row = *i1;
	for (int i = 0; i < cnt; i++) {
		if (r1[i] == c_row) {
			c_col = c1[i];
		}
	}
	c_moves++;
	return 0;
}
int rowMin(int r0, int c0) {
	int sub0 = r0 - c0;
	int cnt = 0;
	int blocks = 0;
	int r1[100], c1[100];
	if (r0 <= c0) {
		for (int i = 1; i <= 8;i++) {
			for (int j = 1;j <= 8;j++) {
				int sub1 = i - j;
				if ((sub1 == sub0) && (i != r0)) {
					r1[cnt] = i;
					c1[cnt] = j;
					cnt++;
				}
			}
		}
	}
	int* i1;
	i1 = std::min_element(r1, r1 + cnt);
	c_row = *i1;
	for (int i = 0; i < cnt; i++) {
		if (r1[i] == c_row) {
			c_col = c1[i];
		}
	}
	c_moves++;
	return 0;
}
int colMax(int r0, int c0) {
	int sum0 = r0 + c0;
	int cnt = 0;
	int blocks = 0;
	int r1[1000], c1[1000];
	if (c0 <= r0) {
		for (int i = 1; i <= 8;i++) {
			for (int j = 1;j <= 8;j++) {
				int sum1 = i + j;
				if ((sum1 == sum0) && (i != r0)) {
					r1[cnt] = i;
					c1[cnt] = j;
					cnt++;
				}
			}
		}
	}
	int* i1;
	i1 = std::max_element(c1, c1 + cnt);
	c_col = *i1;
	for (int i = 0; i < cnt; i++) {
		if (c1[i] == c_col) {
			c_row = r1[i];
		}
	}
	c_moves++;
	return 0;
}
int colMin(int r0, int c0) {
	int sum0 = r0 + c0;
	int cnt = 0;
	int blocks = 0;
	int r1[100], c1[100];
	if (r0 <= c0) {
		for (int i = 1; i <= 8;i++) {
			for (int j = 1;j <= 8;j++) {
				int sum1 = i + j;
				if ((sum1 == sum0) && (i != r0)) {
					r1[cnt] = i;
					c1[cnt] = j;
					cnt++;
				}
			}
		}
	}
	int* i1;
	i1 = std::min_element(c1, c1 + cnt);
	c_col = *i1;
	for (int i = 0; i < cnt; i++) {
		if (c1[i] == c_col) {
			c_row = r1[i];
		}
	}
	c_moves++;
	return 0;
}

int main() {
	int t;
	int i = 0;
	int arr[1000];
	cin >> t;
	while (t--) {
		int r0, c0;
		cin >> r0 >> c0;
		c_row = r0;
		c_col = c0;
		while (1) {
			rowMax(c_row, c_col);
			arr[i] = c_row;
			arr[i + 1] = c_col;
			i += 2;
			if (c_moves >= 16) {
				break;
			}
			if (c_row == 8 || c_col == 8) {
				c_row--;
				c_col--;
				c_moves++;
				arr[i] = c_row;
				arr[i + 1] = c_col;
				i += 2;
				if (c_moves >= 16) {
					break;
				}
			}
			colMax(c_row, c_col);
			arr[i] = c_row;
			arr[i + 1] = c_col;
			i += 2;
			if (c_moves >= 16) {
				break;
			}
			rowMin(c_row, c_col);
			arr[i] = c_row;
			arr[i + 1] = c_col;
			i += 2;
			if (c_moves >= 16) {
				break;
			}
			colMin(c_row, c_col);
			arr[i] = c_row;
			arr[i + 1] = c_col;
			i += 2;
			if (c_moves >= 16) {
				break;
			}
		}
		cout << c_moves << endl;
		for (int i = 0; i < (c_moves * 2);i = i + 2) {
			cout << arr[i] << " " << arr[i + 1] << endl;
		}
	}
	return 0;
}