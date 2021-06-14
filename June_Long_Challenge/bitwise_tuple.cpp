#include<bits/stdc++.h>

using namespace std;

long long power(long long a, long long b){
    long long ans = 1;
    while(b--){
        ans *= a;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin>>t;

    while(t--){
        long long n, m;
        cin>>n>>m;
        long long expo = power(2, n);
        expo--;
        long long result = power(expo, m);
        long long div = power(10, 9) + 7;
        result = result % div;
        cout<<result<<endl;
    }
    return 0;
}