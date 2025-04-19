#include <bits/stdc++.h>
#define nmax 1005
using namespace std;
int n, k, a[nmax], mid, req;
int main()
{
    cin>>n>>k;
    assert(1 <= n && n <= 1000);
    assert(1 <= k && k <= 1000);
    for (int i=1;i<=n;++i){
        cin>>a[i];
        assert(1 <= a[i] && a[i] <= 1000);
    }
    sort(a+1,a+n+1);
    mid = a[n/2+1];
    int act = n/2+1;
    while (act <= n && a[act] == mid){
        ++req, ++act;
    }
    if (req > k){
        cout<<mid<<'\n';
    } else {
        cout<<mid+1<<'\n';
    }
    return 0;
}