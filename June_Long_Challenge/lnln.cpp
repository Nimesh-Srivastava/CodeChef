#include<bits/stdc++.h>

using namespace std;

void display(vector<long long> &p){
    sort(p.begin(), p.end());
    for(long long i=0; i<p.size(); i++){
        cout<<p[i]<<" ";
    }
}

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

long long cal_xor(vector<long long> &p){
    long long xor_sum = 0;
    for(long long i=0; i<p.size(); i++){
        xor_sum ^= p[i];
    }
    return xor_sum;
}

void find_min_comb(vector<long long> &a, vector<long long> &b, long long index, long long cnt, vector<long long> &common, long long &min_xor){
    long long i;
    if(b.size() == cnt){
        if(cal_xor(b) < min_xor){
            min_xor = cal_xor(b);
            common = b;
        }
    }
    for(i=index; i<a.size(); i++){
        b.push_back(a[i]);
        find_min_comb(a, b, i+1, cnt, common, min_xor);
        b.pop_back();
    }
}

void find_max_comb(vector<long long> &a, vector<long long> &b, long long index, long long cnt, vector<long long> &common, long long &max_xor){
    long long i;
    if(b.size() == cnt){
        if(cal_xor(b) > max_xor){
            max_xor = cal_xor(b);
            common = b;
        }
    }
    for(i=index; i<a.size(); i++){
        b.push_back(a[i]);
        find_max_comb(a, b, i+1, cnt, common, max_xor);
        b.pop_back();
    }
}

void diff_cal(long long n, long long k, vector<long long> &p){
  long long i;
  vector<long long> rem_elems;
  long long curr_xor = cal_xor(p);
  rem_elems.clear();
    for(i=1; i<=n; i++){
        if(find(p.begin(), p.end(), i) == p.end()){
            rem_elems.push_back(i);
        }
    }
    vector<long long> sol;
    vector<long long> common;
    long long min_xor = INT_MAX;
    long long max_xor = 0;
    if(curr_xor > 0){
      find_min_comb(rem_elems, sol, 0, k - p.size(), common, min_xor);
    }
    else{
      find_max_comb(rem_elems, sol, 0, k - p.size(), common, max_xor);
    }
    p.insert(p.end(), common.begin(), common.end());
}

void pop_val(vector<long long> &p, long long index){
    vector<long long>::iterator it = (p.begin() + index);
    p.erase(it);
}

int cal(long long n, long long k){
    vector<long long> integers;
    integers.clear();
    long long nth = log2(n);
    // integers.push_back(n);
    // integers.push_back(n-1);
    integers.push_back(pow(2, nth));
    integers.push_back(pow(2, nth)-1);
    sort(integers.begin(), integers.end());
    long long i, j=0;
    int check = 1;
    bool working = true;
    for(i=0; i<k-2; i++){
        if(j == integers.size() && working == false){
            diff_cal(n, k, integers);
            break;
            // return 0;
        }
        long long front_val = integers[j];
        pop_val(integers, j);
        check = find_pair(n, front_val, integers);
        if(check == 0){
            j = 0;
            working = true;
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