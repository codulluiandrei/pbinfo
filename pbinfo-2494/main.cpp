#include <bits/stdc++.h>
using namespace std;

ifstream f("descmult.in");
ofstream g("descmult.out");

int n, a, b, c, nr, k;
int D[23], E[23];
int F[1000003];
unsigned long long nrd, p;

int main(){

    f >> c;
    f >> n >> a >> b;
    for(int i=1; i<=n; ++i)
        f >> D[i];
    for(int i=1; i<=n; ++i)
        f >> E[i];

    if (c == 1) {
        nrd = 1;
        for(int i=1; i<=n; ++i)
            nrd *= (E[i] + 1);
        g << nrd << '\n';

    } else {
        F[1] = k = 1;
        if (a == 1) g << "1 ";
        for(int i=1; i<=n; ++i){

            p = 1;
            int m = k;
            while(E[i]--) {

                p *= D[i];
                if (p > b) break;
                for(int j=1; j<=k; ++j) {
                    long long y = F[j] * p;

                    if (y <= b) {
                        if (y >= a) g << y << " ";
                        F[++m] = y;
                    }
                }
            }

            k = m;
        }

        g << '\n';
    }

    return 0;
}
