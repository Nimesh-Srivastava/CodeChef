#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

int main() {
    double t;
    long long int a, b, c, d;
    
    cin>>t;
    while(t--) {
        cin>>a>>b>>c>>d;
        if(a==b) {
            cout<<"YES"<<endl;
        }
        else if((a!=b && c==d) || abs(a-b) % abs(c-d)) {
            cout<<"NO"<<endl;
        }
        else {
            cout<<"YES"<<endl;
        }
    }
    return 0;
}