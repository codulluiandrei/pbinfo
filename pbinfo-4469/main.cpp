#include <bits/stdc++.h>

using namespace std;

int n, m, x, y;
long long r;
long long L[100002];

int main()
{
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>x>>y;
        L[i]=1LL*x*x+1LL*y*y;
    }
    sort(L+1, L+n+1);
    cin>>m;
    for (int i=1; i<=m; i++) {
        cin>>r;
        int st=1, dr=n, poz=0;
        while (st<=dr) {
            int m = st + (dr-st)/2;
            if (L[m] <= r*r) {
                poz = m;
                st = m + 1;
            } else dr = m - 1;
        }
        cout<<poz<<" ";
    }
    return 0;
}
