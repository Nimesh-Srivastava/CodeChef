#include<bits/stdc++.h>

using namespace std;

struct line {
	long long int x1, y1, x2, y2;
	long long int left() {
		if (x1 < x2) {
			return x1;
		}
		else {
			return x2;
		}
	}
	long long int right() {
		if (x1 > x2) {
			return x1;
		}
		else {
			return x2;
		}
	}
	double slope() {
		if (x2 == x1) {
			return 0;
		}
		else {
			return (y2 - y1) / (x2 - x1);
		}
	}
	double cons() {
		return y2 - (slope() * x2);
	}
	double calX(double y) {
		return (y - cons()) / slope();
	}
}arb, nor;

int inter(line l1, line l2) {
	if (l1.slope() == l2.slope()) {
		if (l1.cons() == l2.cons()) {
			if (l1.left() >= l2.right() || l1.right() <= l2.left()) {
				return 0;
			}
			else {
				return 1;
			}
		}
		else {
			return 0;
		}
	}
	else {
		double x1;
		x1 = l1.calX(l2.cons());
		if ((x1 >= l1.x1) && (x1 <= l1.x2)) {
			if (l1.left() >= l2.right() || l1.right() <= l2.left()) {
				return 0;
			}
			else {
				return 1;
			}
		}
		else {
			return 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		long int n, q;
		cin >> n >> q;
		long long int a[1000005];
		for (long int i = 0; i < n; i++) {
			cin >> a[i];
		}
		long long int pt1[1000005], pt2[1000005], pt3[1000005];
		for (long int i = 0; i < q; i++) {
			cin >> pt1[i] >> pt2[i] >> pt3[i];
			long long int points = 0;
			arb.x1 = pt1[i];
			arb.x2 = pt2[i];
			arb.y1 = pt3[i];
			arb.y2 = pt3[i];
			for (long int j = 0; j < n - 1; j++) {
				nor.x1 = j + 1;
				nor.y1 = a[j];
				nor.x2 = j + 2;
				nor.y2 = a[j + 1];
				points += inter(nor, arb);
			}
			cout << points << endl;
		}
	}
	return 0;
}