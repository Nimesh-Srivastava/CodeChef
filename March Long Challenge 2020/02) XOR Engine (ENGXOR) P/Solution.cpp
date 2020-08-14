#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        int a[1000005], p, zor;
        for (int i = 0; i < n;i++) {
            cin >> a[i];
        }
        for (int i = 0; i < q; i++) {
            cin >> p;
            int eve = 0;
            int odd = 0;
            for (int j = 0; j < n; j++) {
                zor = p ^ a[j];
                int sum = 0;
                while (zor != 0) {
                    sum += zor % 2;
                    zor /= 2;
                }
                if (sum % 2 == 0) {
                    eve++;
                }
                else {
                    odd++;
                }
            }
            cout << eve << " " << odd << "\n";
        }
    }
    return 0;
}