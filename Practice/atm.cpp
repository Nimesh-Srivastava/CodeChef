#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    float ac_balance;
    cin>>x>>ac_balance;
    if((x%5 == 0) && (x+0.5 <= ac_balance)) cout<<ac_balance-x-0.5<<"\n";
    else cout<<ac_balance<<"\n";
    return 0;
}
