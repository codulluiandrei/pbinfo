#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
#define Nmax 100002
#define ll long long
using namespace std;
ifstream f("camioane.in");
ofstream g("camioane.out");
int n, m;
int ans[Nmax];
pair<pair<ll,ll>, int> A[Nmax], B[Nmax];
pair<ll,ll> StringToPair(string aux){
    pair<ll,ll> ans = {0,0};
    reverse(aux.begin(),aux.end());
    while (aux.size() > 16){
        ans.first = ans.first * 10 + aux.back() - '0';
        aux.pop_back();
    }
    while (!aux.empty()){
        ans.second = ans.second * 10 + aux.back() - '0';
        aux.pop_back();
    }
    return ans;
}
int main()
{
    f >> n >> m;
    string aux;
    for (int i=1;i<=n;i++){
        f >> aux;
        A[i].first = StringToPair(aux);
        A[i].second = i;
    }
    for (int i=1;i<=m;i++){
        f >> aux;
        B[i].first = StringToPair(aux);
        B[i].second = i;
    }
    sort(A+1,A+n+1);
    sort(B+1,B+m+1);
    int nr = 1;
    for (int i=1;i <= n && nr <= m;i++)
        if (A[i].first >= B[nr].first){ /// cautam traseul cu indicele A[i] cel mai mic pe care poate circula camionul C[nr]
            ans[A[i].second] = B[nr].second;
            nr++;
        }
    g << nr-1 << '\n';
    for (int i=1;i<=n;i++){
        g << ans[i] << ' ';
    }
    return 0;
}