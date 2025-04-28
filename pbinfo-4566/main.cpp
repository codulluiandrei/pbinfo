// rapeanu.cpp
#include <bits/stdc++.h>
using namespace std;
ifstream fin("turism.in");
ofstream fout("turism.out");
const int MOD = 1e9 + 7;
int add(int a, int b) {
  a += b;
  if(a >= MOD) {
    a -= MOD;
  }
  return a;
}
int sub(int a, int b) {
  a -= b;
  if(a < 0) {
    a += MOD;
  }
  return a;
}
int mult(int a, int b) {
  return 1LL * a * b % MOD;
}
int lgpow(int b, int e) {
  int p = 1;
  while(e) {
    if(e & 1) {
      p = mult(p, b);
    }
    b = mult(b, b);
    e >>= 1;
  }
  return p;
}
void dfs(int nod, const vector<vector<int>> &graph, vector<int> &low, vector<int> &id, vector<int>& node_stack, vector<bool>& in_stack, int &last_id, function<void(int)> &callback) {
  low[nod] = id[nod] = ++last_id;
  node_stack.push_back(nod);
  in_stack[nod] = true;
  for(auto it: graph[nod]) {
    if(id[it] == 0){
      dfs(it, graph, low, id, node_stack, in_stack, last_id, callback);
    }
    if(in_stack[it]) {
      low[nod] = min(low[nod], low[it]);
    }
  }
  if(low[nod] == id[nod]) {
    int node_count = 0;
    while(in_stack[nod]){
      node_count++;
      in_stack[node_stack.back()] = false;
      node_stack.pop_back();
    }
    callback(node_count);
  }
}
int main() {
  int t;
  fin >> t;
  int n, m, q;
  fin >> n >> m >> q;
  vector<vector<int> > graph(n + 1, vector<int>());
  for(int i = 1;i <= m;i++) {
    int x, y;
    fin >> x >> y;
    graph[x].push_back(y);
  }
  vector<int> fact(max(n, q) + 1, 1);
  vector<int> ifact(max(n, q) + 1, 1);
  for(int i = 1;i <= n;i++) {
    fact[i] = mult(fact[i - 1], i);
  }
  ifact[n] = lgpow(fact[n], MOD - 2);
  for(int i = n - 1;i >= 0;i--) {
    ifact[i] = mult(ifact[i + 1], i + 1);
  }
  auto arang = [&fact, &ifact](int n, int k) {
    if(n < k) {
      return 0;
    }
    return mult(fact[n], ifact[n - k]);
  };
  vector<int> answer(q + 1, 0);
  vector<int> fr(n + 1, 0);
  function<void(int)> strat1 = [&fr, q](int n) {
    fr[n]++;
  };
  function<void(int)> strat2 = [&answer, q, &arang](int n) {
    for(int i = 1;i <= n;i++) {
      answer[i] = add(answer[i], arang(n, i));
    }
  };
  vector<int> id(n + 1, 0);
  vector<int> low(n + 1, 0);
  vector<int> node_stack(n + 1, 0);
  vector<bool> in_stack(n + 1, 0);
  int last_id = 0;
  for(int i = 1;i <= n;i++) {
    if(id[i] == 0) {
      dfs(i, graph, low, id, node_stack, in_stack, last_id, (t == 1 ? strat1:strat2));
    }
  }
  for(int i = 1;i <= n;i++) {
    if(!fr[i])continue;
    int current = 1;
    for(int j = 1;j <= q;j++){
      current = mult(current, i);
      answer[j] = add(answer[j], mult(fr[i], current));
    }
  }
  for(int i = 1;i <= q;i++) {
    fout << answer[i] << "\n";
  }
  return 0;
}