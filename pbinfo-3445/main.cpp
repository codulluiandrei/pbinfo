/// sursa oficiala 100p O(N)
/// student Tamio-Vesa Nakajima
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using cd = complex<double>;
int main(){
    ifstream f("leftmax.in");
    ofstream g("leftmax.out");
    // Citim inputul.
    int n;
    f >> n;
    vector<int> v(n);
    for(auto& x : v)
        f >> x;
    // Folosim o stiva pentru a calcula sirurile
    // st si dr din solutie.
    vector<int> st(n), dr(n);
    stack<int> stiva;
    for(int i = 0; i < n; ++i){
        while(!stiva.empty() && v[stiva.top()] < v[i]){
            dr[stiva.top()] = i - 1;
            stiva.pop();
        }
        st[i] = (stiva.empty() ? 0 : stiva.top() + 1);
        stiva.push(i);
    }
    while(!stiva.empty()){
        dr[stiva.top()] = n - 1;
        stiva.pop();
    }
    // Acum vom itera prin sir, retinand solutia in ret.
    ll ret = 0;
    for(int i = 0; i < n; ++i){
        const ll L = i - st[i], R = dr[i] - i;
        ret += (min(R, L) + 1) * (R - L + 2 + max(R, L)) / 2;
    }
    // Afisam solutia.
    g << ret % 1000000007 << endl;
    return 0;
}