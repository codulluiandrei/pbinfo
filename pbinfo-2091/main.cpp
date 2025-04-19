#include <fstream>
#include <climits>
#define DIM 100010
#define INF INT_MAX
using namespace std;
ifstream fin ("aimi.in");
ofstream fout("aimi.out");
struct nod {
    int value;
    int add;
};
nod A[4*DIM];
int n, m, a, b, t, i, minim, x;
void build(int nod, int st, int dr) {
    if (st == dr) {
        fin>>A[nod].value;
    } else {
        int mid = (st + dr)/2;
        build(2*nod, st, mid);
        build(2*nod+1, mid+1, dr);
        A[nod].value = min(A[2*nod].value, A[2*nod+1].value);
    }
}
void query(int nod, int st, int dr, int a, int b) {
    if (a <= st && dr <= b) {
        minim = min(minim, A[nod].value);
    } else {
        if (A[nod].add == 1) {
            A[2*nod].value = A[nod].value;
            A[2*nod].add = 1;
            A[2*nod+1].value = A[nod].value;
            A[2*nod+1].add = 1;
            A[nod].add = 0;
        }
        int mid = (st + dr)/2;
        if (a <= mid)
            query(2*nod, st, mid, a, b);
        if (b > mid)
            query(2*nod+1, mid+1, dr, a, b);
        A[nod].value = min(A[2*nod].value, A[2*nod+1].value);
    }
}
void update(int nod, int st, int dr, int a, int b, int x) {
    if (a <= st && dr <= b) {
        A[nod].value = x;
        A[nod].add = 1;
    } else {
        if (A[nod].add == 1) {
            A[2*nod].value = A[nod].value;
            A[2*nod].add = 1;
            A[2*nod+1].value = A[nod].value;
            A[2*nod+1].add = 1;
            A[nod].add = 0;
        }
        int mid = (st + dr)/2;
        if (a <= mid)
            update(2*nod, st, mid, a, b, x);
        if (b > mid)
            update(2*nod+1, mid+1, dr, a, b, x);
        A[nod].value = min(A[2*nod].value, A[2*nod+1].value);
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
            fin>>x;
            update(1, 1, n, a, b, x);
        }
    }
    return 0;
}