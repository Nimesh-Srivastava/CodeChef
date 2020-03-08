#include<iostream>

using namespace std;

int main() {
	int numB, k = 0;
	int coin[100000], arr[100000], sum = 0;
	int test, count = 0, div;

	cin >> test;
	while (test > 0) {
		cin >> numB >> div;
		while (k != numB) {
			int buff1 = 0;
			int buff2 = 1000;
			int min1 = 1000, min2 = 1000;
			for (int i = 0; i < numB-k; i++) {
				cin >> coin[i];
				for (int j = coin[i]; j >= 0; j--) {
					if (coin[i] % div == 0) {
						break;
					}
					coin[i]--;
					count++;
					sum += count;
				}
				for (int l = numB - k; l < numB; l++) {
					int check = div - (coin[l] % div);
					if (check < min1) {
						min1 = check;
					}
				}
				if (min1 < min2) {
					min2 = min1;
				}
				//cout << count << endl;
				if (count > buff1) {
					buff1 = count;
				}				
				count = 0;
			}
			buff1 -= min2;
			if (buff1 < buff2) {
				buff2 = buff1;
			}
			cout << "Buffer : " << buff1 << endl;
			k++;
		}		
	}

	return 0;
}