#include <bits/stdc++.h>

using namespace std;

void dfs(long long node, long long pass, vector<vector<long long> > &p, vector<long long> &q, vector<long long> &r, long long curr){
    bool isleaf = true;
    long long max_val = 0;
    for(auto curr_node : p[node]){
        if(curr_node != pass){
            isleaf = false;
            max_val = max(max_val, q[curr_node]);
        }
    }
    if(isleaf){
        r.push_back(curr);
        return;
    }
    long long var = 0;
    for(auto curr_node : p[node]){
        if(curr_node == pass){
            continue;
        }
        if(q[curr_node] == max_val && var == 0){
            dfs(curr_node, node, p, q, r, curr+1);
            var++;
        }
        else{
            dfs(curr_node, node, p, q, r, 1);
        }
    }
}

void path_length(long long node, long long pass, vector<vector<long long> > &p, vector<long long> &q){
    bool isleaf = true;
    for(auto curr_node : p[node]){
        if(curr_node == pass){
            continue;
        }
        isleaf = false;
        path_length(curr_node, node, p, q);
        q[node] = max(q[node], 1 + q[curr_node]);
    }
    if(isleaf){
        q[node] = 1;
    }
}

void line_division(long long node, long long pass, vector<vector<long long> > &p, vector<long long> &q, long long n){
    vector<long long> p_length(n+1, 0);
    path_length(node, pass, p, p_length);
    dfs(node, pass, p, p_length, q, 1);
}

long long maxPath(long long node, vector<vector<long long> > &p, long long n){
    vector<bool> over(n+1, false);
    long long fwd = -1, away = 0;
    over[node] = true;
    queue<pair<long long, long long> > q;
    q.push({node, 0});
    while(q.size()){
        auto index = q.front();
        q.pop();
        long long var = index.first;
        long long dist = index.second;
        if(fwd < dist){
            fwd = dist, away = var;
        }
        for(auto curr_node : p[var]){
            if(over[curr_node]){
                continue;
            }
            over[curr_node] = true;
            q.push({curr_node, dist+1});
        }
    }
    return away;
}

long long find_ans(vector<vector<long long> > &p, long long n, long long k){
    if(k == 1){
        return 1;
    }
    long long result = maxPath(1, p, n);
    vector<long long> vertices;
    line_division(result, 0, p, vertices, n);
    sort(vertices.rbegin(), vertices.rend());
    long long siz = 1, sum = 0, i = 0;
    while(sum < k){
        siz++;
        sum += vertices[i++];
    }
    return siz;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    cin>>t;

    while(t--){
        long long n, k, i = 0;
        cin>>n>>k;
        long long temp1, temp2;
        vector<vector<long long> > edges(n+1);
        for(i=1; i<n; i++){
            cin>>temp1>>temp2;
            edges[temp1].push_back(temp2);
            edges[temp2].push_back(temp1);
        }
        cout<<find_ans(edges, n, k)<<endl;
    }
    return 0;
}