#include<bits/stdc++.h>

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    cin>>t;

    while(t--){
        long long n;
        cin>>n;
        long long i, ii, iii;
        long long arr[n], check[n], curr_arr[n];
        vector<pair<long long, long long> > freq1;
        long long freq[n][n][n]; 
        for(i=0; i<n; i++){
            cin>>arr[i];
        }
        long long counter = 1, check_elem = 1;
        long long j = 1, temp = 1;
        for(i=0; i<n-j; i++){
            temp = 1;
            for(ii=0; ii<counter; ii++){
                curr_arr[ii] = arr[ii];
            }
            long long siz = sizeof(curr_arr)/sizeof(curr_arr[0]);
            if(curr_arr[i] == curr_arr[i+1]){
                freq[i][counter][temp];
                temp++;
            }
        }
        long long max_freq = 0, index1, index2, index3, prev;
        i=0, ii=0, iii=0;
        prev = max_freq;
        max_freq = max(max_freq, freq[i][ii][iii]);
        if(prev != max_freq){
            prev = max_freq;
            index1 = i;
            index2 = ii;
            index3 = iii;
        }
        long long occur = 0;
        for(ii=0; ii<index2; ii++){
            occur += freq[index1][ii][index3];
        }
        cout<<occur<<endl;
    }
}