#include <fstream>
#include <iostream>
#include <bitset>
#include <vector>
#define DIM 100010
#define INF 100010

using namespace std;

int u[DIM], f[DIM], x[DIM], y[DIM], crt, S[DIM], m, h;

int v[DIM];
pair<int, int> A[DIM];
int n, maxim, i, j, last, p, d;

long long secv, sol;

int main() {
    ifstream fin ("restaurare.in");
    ofstream fout("restaurare.out");

    fin>>n;
    for (i=1;i<=n;i++) {
        fin>>v[i];
        if (v[i] > maxim)
            maxim = v[i];
    }

    for (i=1;i<=n;i++) {
        v[i] = maxim - v[i] + 1;
        f[ v[i] ]++;
    }

    for (i=1;i<=maxim;i++)
        f[i] += f[i-1];

    for (i=n;i>=1;i--) {
        x[ f[v[i] ] ]= v[i];
        y[ f[v[i] ] ]= i;
        f[ v[i] ]--;
    }

    for (i=1;i<=n;i++)
        u[i] = 1;
    secv = 1;

    last = 0;
    for (i=1;i<=n;i++) {
        if (x[i] != x[i-1]) {
            sol += secv * (x[i]-last);
            //
            A[++d] = make_pair( maxim-x[i]+2, secv * (x[i]-last) );
            //
            last = x[i];

        }
        p = y[i];

        u[p] = 0;
        if (u[p-1] == 1 && u[p+1] == 1)
            secv++;
        if (u[p-1] == 0 && u[p+1] == 0)
            secv--;
    }

    p = d;
    for (i=1;i<=maxim;i++) {
        if (A[p].first == i) {
            crt = A[p].second / (A[p-1].first - A[p].first);
            p--;
        }
        S[i] = S[i-1] + crt;
    }

    fin>>m;
    for (i=1;i<=m;i++) {
        fin>>h;
        fout<<S[h]<<"
";
    }
/*
    for (i=1;i<=maxim;i++)
        cout<<i<<" "<<S[i]<<"
";

    cout<<"
";
    for (i=1;i<=d;i++)
        cout<<A[i].first<<" "<<A[i].second<<"
";
*/
//    fout<<sol-1<<"
";


    return 0;
}

