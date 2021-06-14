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

void combinations_min (long long v[], long long start, long long n, long long k, long long maxk, long long &min_xor, vector<long long> &sol, vector<long long> &common, vector<long long> &p) {
        long long i;
        if (k > maxk) {
                for (i=1; i<=maxk; i++) {
                  sol.push_back(v[i]);
                }
                if(cal_xor(sol) < min_xor){
                  min_xor = cal_xor(sol);
                  common = sol;
                }
                sol.clear();
                return;
        }
        for (i=start; i<=n; i++) {
                if(find(p.begin(), p.end(), i) != p.end()){
                    continue;
                }
                v[k] = i;
                combinations_min (v, i+1, n, k+1, maxk, min_xor, sol, common, p);
        }
}

void combinations_max(long long v[], long long start, long long n, long long k, long long maxk, long long &max_xor, vector<long long> &sol, vector<long long> &common){
    long long i;
    if(k > maxk){
        for(i=1; i<maxk; i++){
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
        combinations_max (v, i+1, n, k+1, maxk, max_xor, sol, common);
    }
}

// void find_comb(vector<long long> &a, vector<long long> &b, long long index, long long cnt, vector<long long> &common){
//     long long i;
//     long long min_xor = INT_MAX;
//     long long prev = min_xor;
//     if(b.size() == cnt){
//         min_xor = min(min_xor, cal_xor(b));
//         if(prev != min_xor){
//             prev = min_xor;
//             common = b;
//         }
//     }
//     for(i=index; i<a.size(); i++){
//         b.push_back(a[i]);
//         find_comb(a, b, i+1, cnt, common);
//         b.pop_back();
//     }
// }

int find_pair(long long n, long long val, vector<long long> &p){
    long long i;
    long long ans = 0, max_i = 0;
    for(i=1; i<=n; i++){
        ans = (i ^ val);
        if(find(p.begin(), p.end(), ans) != p.end()){
            continue;
        }
        else{
            if(find(p.begin(), p.end(), i) != p.end()){
                continue;
            }
            else{
                if((ans > 0) && (ans <= n)){
                    max_i = max(max_i, i);
                    // max_i = i;       // no difference
                }
            }
        }
    }
    if(max_i != 0){
        p.push_back(max_i);
        ans = (max_i ^ val);
        p.push_back(ans);
        return 0;
    }
    else{
        return 1;
    }
}

void cal_rem(long long n, long long k, vector<long long> &p){
    long long i, curr_xor = 0;
    vector<long long> rem_elems;
    rem_elems.clear();
    for(i=1; i<=n; i++){
        if(find(p.begin(), p.end(), i) == p.end()){
            rem_elems.push_back(i);
        }
        else{
            curr_xor ^= i;
        }
    }
    long long min_xor = INT_MAX, element = 0;
    // for(i=0; i<rem_elems.size(); i++){
    //     if((curr_xor ^ rem_elems[i]) < min_xor){
    //         min_xor = curr_xor^rem_elems[i];
    //         element = rem_elems[i];
    //     }
    // }
    // p.push_back(element);
    vector<long long> sol;
    vector<long long> common;
    long long arr[1000005];
    combinations_min (arr, 1, n, 1, k - p.size(), min_xor, sol, common, p);
    // find_comb(rem_elems, sol, 0, k - p.size(), common);
    for(i=0; i<common.size(); i++){
        p.push_back(common[i]);
    }
}

// void diff_cal(long long n, long long k, long long j, vector<long long> &p){
//     long long min_xor = INT_MAX, prev;
//     prev = min_xor;
//     long long xor_sum = 0;
//     long long new_xor = 0;
//     vector<long long> rem_elems;
//     rem_elems.clear();
//     vector<long long> elems;
//     elems.clear();
//     long long i, ii;
//     for(i=1; i<=n; i++){
//         if(find(p.begin(), p.end(), i) == p.end()){
//             rem_elems.push_back(i);
//         }
//         else{
//             xor_sum ^= i;
//         }
//     }
//     sort(rem_elems.begin(), rem_elems.end());
//     for(ii=0; ii<(k-j); ii++){
//         p.push_back(rem_elems[ii]);
//     }
//     for(i=0; i<(rem_elems.size()-k+j+1); i++){
//         long long iii=i;
//         for(ii=0; ii<(k-j); ii++){
//             new_xor ^= rem_elems[iii];
//             iii++;
//         }
//         min_xor = min(min_xor, new_xor);
//         if(prev != min_xor){
//             iii = i;
//             for(ii=0; ii<(k-j); ii++){
//                 p.pop_back();
//             }
//             for(ii=0; ii<k-j; ii++){
//                 p.push_back(rem_elems[iii]);
//                 iii++;
//             }
//         }
//     }
// }

void pop_val(vector<long long> &p, long long index){
    vector<long long>::iterator it = (p.begin() + index);
    p.erase(it);
}

int cal(long long n, long long k){
    vector<long long> integers;
    integers.clear();
    long long nth = log2(n);
    integers.push_back(n);
    if(pow(2, nth+1)-1-n != 0){
        integers.push_back(pow(2, nth+1)-1-n);
    }
    else{
        integers.pop_back();
        integers.push_back(pow(2, nth));
        integers.push_back(pow(2, nth)-1);
    }
    // cout<<"1 : "<<n<<", 2 : "<<pow(2, nth+1)-1<<endl;
    // integers.push_back(pow(2, nth));
    // integers.push_back(pow(2, nth)-1);
    sort(integers.begin(), integers.end());
    long long i, j=0;
    int check = 1;
    bool working = true;
    for(i=0; i<k-2; i++){
        if(n-k == 1){
                long long arr[100005];
                long long max_xor = INT_MAX;
                vector<long long> sol, common;
                combinations_max(arr, 1, n, 1, k, max_xor, sol, common);
                // integers = common;
                display(common);
                break;
            }
        if((j == integers.size()) && (working == false)){
            cal_rem(n, k, integers);
            break;
        }
        long long siz = integers.size();
        long long front_val = integers[j];
        pop_val(integers, j);
        check = find_pair(n, front_val, integers);
        if(check == 0){
            j = 0;
            working = true;
            // cout<<"replacing : "<<front_val<<endl;
            // cout<<"new array :-"<<endl;
            // display(integers);
            cout<<endl;
        }
        else{
            integers.push_back(front_val);
            working = false;
            j++;
            i--;
        }
        sort(integers.begin(), integers.end());
    }
    display(integers);
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