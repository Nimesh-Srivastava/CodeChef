#include<bits/stdc++.h>

using namespace std;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const{
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
#define umap_pll_l  unordered_map<pair<long long int, long long int>, long long int, hash_pair>

void dfs_a(long long int node_s, long long int par, vector<vector<long long int>>&G, vector<long long int> &S, vector<long long int> &P, vector<long long int> &C, vector<long long int> &L, long long int curr_leaf){
  C[node_s] = 1; P[node_s] = par;
  L[node_s] = curr_leaf;
  for(auto curr_node: G[node_s]){
    if(curr_node != par){
      dfs_a(curr_node, node_s, G, S, P, C, L, curr_leaf+1);
      C[node_s] += C[curr_node];
      S[node_s] += S[curr_node] + C[curr_node];
    }
  }
}

void dfs_b(long long int node_s, long long int par, vector<vector<long long int>>&G, vector<long long int> &T, vector<long long int> &S, vector<long long int> &C, umap_pll_l & dp_cont, umap_pll_l & dp_c, long long int n){
  T[node_s] = T[par] + n - 2*C[node_s];
  for(auto curr_node: G[node_s])
    if(curr_node != par){
      dfs_b(curr_node, node_s, G, T, S, C, dp_cont, dp_c, n);
      dp_c[make_pair(node_s,curr_node)] = C[curr_node];
      dp_cont[make_pair(node_s, curr_node)] = S[curr_node];
      dp_cont[make_pair(curr_node, node_s)] = T[node_s] - S[curr_node] - C[curr_node];
    }
  dp_c[make_pair(node_s, par)] = n - C[node_s];

}

void shift_up(long long int& u, long long int dist, vector<vector<long long int>> & dp_present){
  for(long long int i=20; i>=0; i--)
    if((1<<i) <= dist){
      dist -= (1<<i);
      u = dp_present[u][i];
    }
}

long long int find_low(long long int a, long long int b, vector<vector<long long int>> &dp_present, vector<long long int> & L){
  long long int u = a, v = b;
  if(L[u] > L[v]) shift_up(u, L[u]-L[v], dp_present);
  if(L[u] < L[v]) shift_up(v, L[v]-L[u], dp_present);
  if (u==v) return u;
  for(int i=19; i>=0; i--)
    if(dp_present[u][i] != 0 && dp_present[u][i] != dp_present[v][i])
      u = dp_present[u][i], v = dp_present[v][i];
  u = dp_present[u][0];
  return u;
}

void getMidProps(long long int &a, long long int &b, vector<vector<long long int>>& dp_present, vector<long long int> &L, vector<long long int> & v){
  long long int lower = find_low(a, b, dp_present, L);
  long long int dist = abs(L[lower] - L[a]) + abs(L[lower] - L[b]);
  long long int mva = (dist-1)/2, mvb;
  long long int m1 = a, m2;
  shift_up(m1, mva, dp_present);
  mvb = dist - 1 - mva; m2 = b;
  if(m1 != lower) m2 = dp_present[m1][0];
  else{
    shift_up(m2, mvb, dp_present);
  }
  v[0] = m1; v[1] = m2;  v[2] = mva; v[3] = mvb;
}

void solve(vector<vector<long long int>> &G, int n, int q){
  vector<long long int> S(n+1, 0), P(n+1, 0), C(n+1, 0), T(n+1, 0), L(n+1, 0);
  umap_pll_l dp_cont, dp_c;
  dfs_a(1, 0, G, S, P, C, L, 1);

  T[0] = S[1] + C[1];
  dfs_b(1, 0, G, T, S, C, dp_cont, dp_c, n);
  vector<vector<long long int>> dp_present(n+1, vector<long long int>(20, 0));
  for(int node_s=1; node_s<=n; node_s++) dp_present[node_s][0] = P[node_s];
  for(int j=1; j<20; j++)
    for(int node_s=1; node_s<=n; node_s++)
    dp_present[node_s][j] = dp_present[dp_present[node_s][j-1]][j-1];
  vector<long long int> v(4, 0);
  long long int a, b, ans=0;
  while(q--){
    cin>>a>>b;
    if (L[a] < L[b]) swap(a, b);
    getMidProps(a, b, dp_present, L, v);
    long long int m1 = v[0], m2 = v[1], da=v[2], db=v[3];
    long long int conta = T[a] - (da+1)*dp_c[{m1, m2}] - dp_cont[{m1, m2}];
    long long int contb = T[b] - (db+1)*dp_c[{m2, m1}] - dp_cont[{m2, m1}];
    ans = conta + contb;
    cout <<ans << "\n";
  }
}

int main(){
    ios::sync_with_stdio(false);  cin.tie(NULL);
  int t; cin>>t;
  long long int n, q;
  while(t--){
    cin>>n>>q;
    vector<vector<long long int>> G(n+1);
    long long int u, v;
    for(int i=1; i<n; i++){
      cin>>u>>v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    solve(G, n, q);
  }
return 0;
}