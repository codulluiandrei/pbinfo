#include <fstream>
#include <climits>
#define DIM 100010
#define INF INT_MAX
#define MOD 9901
using namespace std;
ifstream fin ("aepim.in");
ofstream fout("aepim.out");
int A[4*DIM][3][3];
int n, m, a, b, t, i, minim[3][3], x, k, aux[3][3];
void decodif(int x, int k, int a[3][3]) {
    for (int i=k-1;i>=0;i--)
        for (int j=k-1;j>=0;j--) {
            a[i][j] = x%10;
            x /= 10;
        }
}
void prod(int a[3][3], int b[3][3], int c[3][3], int k) {
    for (int i=0;i<k;i++)
        for (int j=0;j<k;j++) {
            c[i][j] = 0;
            for (int t = 0; t<k; t++) {
                c[i][j] += a[i][t] * b[t][j];
                c[i][j] %= MOD;
            }
        }
}
void copiere(int a[3][3], int b[3][3], int k) {
    for (int i=0;i<k;i++)
        for (int j=0;j<k;j++)
            a[i][j] = b[i][j];
}
void afisare(int a[3][3], int k) {
    for (int i=0;i<k;i++)
        for (int j=0;j<k;j++)
            fout<<a[i][j]<<" ";
    fout<<"\n";
}
void init(int a[3][3], int k) {
    for (int i=0;i<k;i++)
        for (int j=0;j<k;j++) {
            if (i==j)
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
}
void build(int nod, int st, int dr) {
    if (st == dr) {
        fin>>x;
        decodif(x, k, A[nod]);
    } else {
        int mid = (st + dr)/2;
        build(2*nod, st, mid);
        build(2*nod+1, mid+1, dr);
        prod(A[2*nod], A[2*nod+1], A[nod], k);
    }
}
void query(int nod, int st, int dr, int a, int b) {
    if (a <= st && dr <= b) {
        prod(minim, A[nod], aux, k);
        copiere(minim, aux, k);
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
        decodif(b, k, A[nod]);
    } else {
        int mid = (st + dr)/2;
        if (a <= mid)
            update(2*nod, st, mid, a, b);
        if (a > mid)
            update(2*nod+1, mid+1, dr, a, b);
        prod(A[2*nod], A[2*nod+1], A[nod], k);
    }
}
int main () {
    fin>>n>>k;
    build(1, 1, n);
    fin>>m;
    for (int i=1;i<=m;i++) {
        fin>>t>>a>>b;
        if (t == 1) {
            init(minim, k);
            query(1, 1, n, a, b);
            afisare(minim, k);
        } else {
            update(1, 1, n, a, b);
        }
    }
    return 0;
}