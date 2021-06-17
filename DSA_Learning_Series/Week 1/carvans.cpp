#include<bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	int arr[10000], count, i, n;

	cin >> t;
	while (t--) {
		count = 1;
		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (i = 1; i < n; i++) {
			if (arr[i - 1] > arr[i]) {
				count++;
			}
			else {
				arr[i] = arr[i - 1];
			}
		}
		cout << count << endl;
	}

	return 0;
}