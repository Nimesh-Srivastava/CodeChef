#include<bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long int n, maxm, i, price;
	vector<int>vec;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> price;
		vec.push_back(price);
	}
	price = 0, maxm = 0;
	sort(vec.begin(), vec.end());
	for (i = 0; i < n; i++) {
		price = vec[i] * (n - i);
		maxm = max(price, maxm);
	}
	cout << maxm;

	return 0;
}