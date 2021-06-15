#include<iostream>

using namespace std;

int main() {
    int t, n1, n2, k;
    
    cin>>t;
    while(t--) {
        char a[100];
        cin>>n1>>k;
        n2=n1;
        for(int i=0; i<n1; i++) {
            cin>>a[i];
        }
        for(int i=n1-1; i>=n1-k; i--) {
            if(a[i]=='T') {
                n2--;
            }
            else {
                for(int j=0; j<n2; j++) {
                    if(a[j]=='H') {
                        a[j]='T';
                    }
                    else {
                        a[j]='H';
                    }
                }
                n2--;
            }
        }
        int count=0;
        for(int i=0; i<n2; i++) {
            if(a[i]=='H') {
                count++;
            }
        }
        cout<<count<<endl;
    }
    
    return 0;
}