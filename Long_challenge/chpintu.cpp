#include<bits/stdc++.h>

using namespace std;

int main() {
    int t, n, m;
    
    cin>>t;
    while(t--) {
        cin>>n>>m;
        int a[100], b[100];
        for(int i=0; i<n; i++) {
            cin>>a[i];
        }
        for(int i=0; i<n; i++) {
            cin>>b[i];
        }
        int k=0;
        int val[100];
        for(int i=0; i<n; i++) {
            int sum=0;
            for(int j=0; j<n; j++) {
                if(a[i]==a[j]) {
                    sum+=b[j];
                }
            }
            val[k]=sum;
            k++;
        }
        int* i1;
        i1=min_element(val,val+n);
        cout<<*i1<<endl;
    }
}