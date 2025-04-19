#include <fstream>
#include <climits>
#define DIM 100010
#define INF INT_MAX
using namespace std;
ifstream fin ("aecmmdci.in");
ofstream fout("aecmmdci.out");
int A[4*DIM];
int n, m, a, b, t, i, minim;
int cmmdc(int a, int b) {
    int r;
    while (b) {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}
void build(int nod, int st, int dr) {
    if (st == dr) {
        fin>>A[nod];
    } else {
        int mid = (st + dr)/2;
        build(2*nod, st, mid);
        build(2*nod+1, mid+1, dr);
        A[nod] = cmmdc(A[2*nod], A[2*nod+1]);
    }
}
void query(int nod, int st, int dr, int a, int b) {
    if (a <= st && dr <= b) {
        if (minim == INF)
            minim = A[nod];
        else
            minim = cmmdc(minim, A[nod]);
    } else {
        int mid = (st + dr)/2;
        if (a <= mid)
            query(2*nod, st, mid, a, b);
        if (b > mid)
            query(2*nod+1, mid+1, dr, a, b);
    }
}
void update(int nod, int st, int dr, int a, int b) {
    if (st == dr) {
        A[nod] = b;
    } else {
        int mid = (st + dr)/2;
        if (a <= mid)
            update(2*nod, st, mid, a, b);
        if (a > mid)
            update(2*nod+1, mid+1, dr, a, b);
        A[nod] = cmmdc(A[2*nod], A[2*nod+1]);
    }
}
int main () {
    fin>>n;
    build(1, 1, n);
    fin>>m;
    for (int i=1;i<=m;i++) {
        fin>>t>>a>>b;
        if (t == 1) {
            minim = INF;
            query(1, 1, n, a, b);
            fout<<minim<<"\n";
        } else {
            update(1, 1, n, a, b);
        }
    }
    return 0;
}