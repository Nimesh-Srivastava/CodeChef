#include<iostream>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int xw=0, xp=0, rw=0, rp=0;
        cin>>xw>>xp>>rw>>rp;
        int water=0, pulp=0;
        water = rw/xw;
        pulp = rp/xp;
        cout<<water+pulp<<endl;
    }
    return 0;
}