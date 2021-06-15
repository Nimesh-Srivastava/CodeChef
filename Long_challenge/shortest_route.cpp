#include<bits/stdc++.h>

#define maxn 3e5 + 5;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--){
        int n, m, low = -1, high = -1;
        cin>>n>>m;
        int arr1[n], arr2[m], temp[n];
        int i, maxi = maxn;
        for (i=0; i<n; i++){
            cin>>arr1[i];
        }
        for (i=0; i<m; i++){
            cin>>arr2[i];
        }
        for (i=0; i<n; i++){
            if (i==0){
                temp[i]=0;
            }
            else if (arr1[i] != 0) {
                temp[i] = 0;
            }
            else{
                temp[i] = maxi;
            }
        }
        for(i=0; i<n; i++){
            if (arr1[i] == 1){
                high = i;
            }
            if(high != -1){
                if (arr1[i] == 0){
                    temp[i] = min(temp[i], i-high);
                }
            }
        }
        for(i=n-1; i>=0; i--){
            if (arr1[i] == 2){
                low=i;
            }
            if(low != -1){
                if (arr1[i] == 0){
                    temp[i] = min(temp[i], low-i);
                }
            }
        }
        for (i=0; i<m; i++){
            int j = arr2[i] - 1;
            if(temp[j] != maxi){
                cout<<temp[j]<<" ";
            }
            else{
                cout<<-1<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}