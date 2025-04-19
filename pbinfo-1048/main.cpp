#include <fstream>
#define DIM 100010
using namespace std;
int v[DIM];
int n, i, T, st, dr, x, q, maxim;
int cautMinim(int x);
int cautMaxim(int x);
int main(){
    ifstream fin("schi.in");
    ofstream fout("schi.out");
    fin>>n;
    maxim = -1;
    for (i=1;i<=n;i++) {
        fin>>x;
        if (x > maxim)
            maxim = x;
        v[i] = maxim;
    }
    fin>>q;
    for (i=1;i<=q;i++) {
        fin>>x;
        st = cautMinim(x);
        if (st == -1)
            fout<<"0 ";
        else {
            dr = cautMaxim(x);
            fout<<dr-st+1<<" ";
        }
    }
    return 0;
}
int cautMinim(int x) {
    int p = 1, u = n, mid;
    while (p<=u) {
        mid = (p+u)/2;
        if (x<=v[mid]) {
            u = mid-1;
        } else {
            p = mid+1;
        }
    }
    if (v[p] == x)
        return p;
    else
        return -1;
}
int cautMaxim(int x) {
    int p = 1, u = n, mid;
    while (p<=u) {
        mid = (p+u)/2;
        if (x>=v[mid]) {
            p = mid+1;
        } else {
            u = mid-1;
        }
    }
    if (v[u] == x)
        return u;
    else
        return -1;
}