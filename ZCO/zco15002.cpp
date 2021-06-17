#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n, k, i, j = 1, sum = 0;
    cin >> n >> k;
    vector<long long> v(n);
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    i = 0;
    while (j < n)
    {
        if (v[j] - v[i] >= k)
        {
            sum += n - j;
            i++;
        }
        else
        {
            j++;
        }
    }
    cout << sum << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}