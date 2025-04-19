#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
const int nmax = 3e5;
const int smax = 1e6;
int n;
int v[nmax + 5];
int fr[smax + 5];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>v[i];
    long long sum_cnt = 0;
    long long rez = 0;
    for(int p=20;p>=0;p--)
    {
        long long sum = 0;
        long long cnt = 0;
        ++fr[0];
        for(int i=1;i<=n;i++)
        {
            sum += v[i];
            cnt += fr[sum % (1 << p)];
            ++fr[sum % (1 << p)];
        }
        cnt -= sum_cnt;
        sum_cnt += cnt;
        cnt %= Mod;
        rez += 1LL * (1 << p) * cnt % Mod;
        rez %= Mod;
        sum = 0;
        fr[0] = 0;
        for(int i=1;i<=n;i++)
        {
            sum += v[i];
            fr[sum % (1 << p)] = 0;
        }
    }
    cout<<rez<<'\n';
    return 0;
}