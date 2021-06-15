#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin>>t;

    while(t--){
        long long D, d, Q, P, x;
        cin>>D>>d>>P>>Q;
        long long count = 0;
        x = D / d;
        if( x % 2 == 0){
            count = d * ((x / 2) * (2 * P + (x - 1) * Q));
        }
        else{
            count = d * (x * (P + ((x - 1) / 2) * Q));
        }
        count += (D % d) * (P + (x * Q));
        cout<<count<<endl;
    }
    return 0;
}