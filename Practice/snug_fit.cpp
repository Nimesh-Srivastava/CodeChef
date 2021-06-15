#include<bits/stdc++.h>

using namespace std;

int main() {
    long long int t;
    
    cin>>t;
    while(t--) {
        long long int n;
        cin>>n;
        long long int a[n], b[n];
        for(long long int i=0; i<n; i++) {
            cin>>a[i];
        }
        sort(a, a+n);
        for (long long int i=0; i<n; i++) {
            cin>>b[i];
        }
        sort(b, b+n);
        long long int sum=0;
        for(long long int i=0; i<n; i++) {
            sum+=min(a[i], b[i]);
        }
        cout<<sum<<endl;
    }
    
    return 0;
}