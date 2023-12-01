#include <bits/stdc++.h>
using namespace std;

int n;
long long m, a;

inline long long lgput(int x, int y){
    long long ans = 1, aux = x;
    for(int p = 1; p <= y ; p = p << 1){
        if(y & p) ans = ans * aux;
        aux = aux * aux;
    }
    return ans;
}

inline int cautb(long long x, int put){
    long long st = 1, dr = pow(x, 1.0 / put);
    while(st <= dr){
        int mij = (1LL * st + dr) / 2;
        if(lgput(mij, put) > x) dr = mij - 1;
        else st = mij + 1;
    }
    return dr;
}

int main()
{
    ifstream f("abx.in");
    ofstream g("abx.out");

    f >> n >> m;
    for(int i=1; i <= n; ++i){
        f >> a;
        long long sol = 0, dif = m + 100;
        for(int j=2; j <= 60 ; ++j){
            long long y = cautb(a, j);
            long long z = lgput(y, j);
            if(abs(a - z) <= dif && z <= m)
                sol = z, dif = abs(a - z);
            z = lgput(y + 1, j);
            if(abs(a - z) < dif && z <= m)
                sol = z, dif = abs(a - z);
        }
        g << sol << "\n";
    }

    return 0;
}
