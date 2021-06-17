#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long x, y;
    cin >> x >> y;
    if (y % x)
    {
        cout << -1 << "\n";
        return;
    }
    y /= x;
    bool found = false;
    long long ans = 1e9;               // like INT_MAX
    for (long long i = 1; i < 62; i++) // considering binary representations
    {
        long long tt = y + i;
        long long cnt = 0, ta = 0;         // ta = time taken = tt
        for (long long j = 0; j < 62; j++) //considering binary representations
        {
            if ((1ll << j) & tt) // is bit j present in y+i
            {
                cnt++;
                ta += j;
            }
        }
        if (cnt == i)
        {
            ans = min(ans, ta + cnt - 1);
            found = true;
        }
    }
    if (!found)
    {
        ans = -1;
    }
    cout << ans << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}