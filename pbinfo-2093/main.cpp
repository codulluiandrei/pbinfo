#include <fstream>
#define INF 2000000001
#define DIM 100010
using namespace std;
ifstream fin ("aesm.in");
ofstream fout("aesm.out");
struct nod {
    int minim;
    int poz;
    int cnt;
};
nod A[DIM * 4];
int n, m, x, t, p;
void build(int nod, int st, int dr) {
    if (st == dr) {
        fin>>A[nod].minim;
        A[nod].poz = st;
        A[nod].cnt = 1;
    } else {
        int mid = (st + dr)/2;
        build(2*nod, st, mid);
        build(2*nod+1, mid+1, dr);
        A[nod].minim = A[2*nod].minim;
        A[nod].poz = A[2*nod].poz;
        if (A[2*nod+1].minim < A[nod].minim) {
            A[nod].minim = A[2*nod+1].minim;
            A[nod].poz = A[2*nod+1].poz;
        }
        A[nod].cnt = A[2*nod].cnt + A[2*nod+1].cnt;
    }
}
void update(int nod, int st, int dr, int poz, int x) {
    if (st == dr) {
        A[nod].minim = x;
        A[nod].poz = st;
        if (x == INF)
            A[nod].cnt = 0;
        else
            A[nod].cnt = 1;
    } else {
        int mid = (st + dr)/2;
        if (poz <= mid)
            update(2*nod, st, mid, poz, x);
        if (poz > mid)
            update(2*nod+1, mid+1, dr, poz, x);
        A[nod].minim = A[2*nod].minim;
        A[nod].poz = A[2*nod].poz;
        if (A[2*nod+1].minim < A[nod].minim) {
            A[nod].minim = A[2*nod+1].minim;
            A[nod].poz = A[2*nod+1].poz;
        }
        A[nod].cnt = A[2*nod].cnt + A[2*nod+1].cnt;
    }
}
int getPoz(int nod, int st, int dr, int p) {
    if (st == dr) {
        return st;
    } else {
        int mid = (st + dr)/2;
        if (A[2*nod].cnt >= p)
            return getPoz(2*nod, st, mid, p);
        else
            return getPoz(2*nod+1, mid+1, dr, p-A[2*nod].cnt);
    }
}
int main () {
    fin>>n;
    build(1, 1, n);
    fin>>m;
    for (int i=1;i<=m;i++) {
        fin>>t;
        if (t == 1) {
            fout<<A[1].minim<<"\n";
            update(1, 1, n, A[1].poz, INF);
        } else {
            fin>>p>>x;
            update(1, 1, n, t = getPoz(1, 1, n, p), x);
        }
    }
    return 0;
}