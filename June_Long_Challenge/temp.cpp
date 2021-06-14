#include<bits/stdc++.h>

using namespace std;

void display(vector<long long> &p){
    sort(p.begin(), p.end());
    for(long long i=0; i<p.size(); i++){
        cout<<p[i]<<" ";
    }
}

long long cal_xor(vector<long long> &p){
    long long xor_sum = 0;
    for(long long i=0; i<p.size(); i++){
        xor_sum ^= p[i];
    }
    return xor_sum;
}

// void comb(long long N, long long K, vector<long long> sol, vector<long long> &common, long long &max_xor) {
//     string bitmask(K, 1);
//     bitmask.resize(N, 0);
//     do {
//         for (long long i = 0; i < N; ++i)
//         {
//             if (bitmask[i]) {
//               sol.push_back(i+1);
//             }
//         }
//         if(cal_xor(sol) > max_xor){
//           max_xor = cal_xor(sol);
//           common = sol;
//         }
//         sol.clear();
//     } while (prev_permutation(bitmask.begin(), bitmask.end()));
// }

void combinations (long long v[], long long start, long long n, long long k, long long maxk, long long &max_xor, vector<long long> &sol, vector<long long> &common) {
        long long i;
        if (k > maxk) {
                for (i=1; i<=maxk; i++) {
                  sol.push_back(v[i]);
                }
                if(cal_xor(sol) > max_xor){
                  max_xor = cal_xor(sol);
                  common = sol;
                }
                sol.clear();
                return;
        }
        for (i=start; i<=n; i++) {
                v[k] = i;
                combinations (v, i+1, n, k+1, maxk, max_xor, sol, common);
        }
}

int cal(long long n, long long k){
    vector<long long> num;
    long long i, max_xor = 0;
    for(i=1; i<=n; i++){
        num.push_back(i);
    }
    vector<long long> sol, common;
    long long arr[10000];
    // comb(n, k, sol, common, max_xor);
    combinations(arr, 1, n, 1, k, max_xor, sol, common);
    display(common);
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    cin>>t;

    while(t--){
        long long n, k;
        cin>>n>>k;
        if(k == 1){
            cout<<n;
        }
        else if(n == k){
            for(long long i=0; i<n; i++){
                cout<<i+1<<" ";
            }
        }
        else if(k > n){
            return 0;
        }
        else{
            int solve = cal(n, k);
        }
        cout<<endl;
    }
    return 0;
}