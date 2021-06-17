#include<bits/stdc++.h>

using namespace std;

int main(void) {
	int t;
	char str[1001];
	int i, j, siz, newSiz, temp;

	cin >> t;
	while (t--) {
		cin >> str;
		temp = 0;
		siz = strlen(str);
		if (siz % 2 == 0) {
			newSiz = siz / 2;
		}
		else {
			newSiz = (siz / 2) + 1;
		}
		for (i = 0; i < siz / 2; i++) {
			for (j = newSiz; j < siz; j++) {
				if (str[i] == str[j]) {
					temp++;
					str[j] = 0; //overwrting to stop recurrsion
					break;
				}
			}
		}
		if (temp == (siz / 2)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}