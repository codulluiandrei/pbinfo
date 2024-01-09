#include <fstream>
#define DIM 1002
#define BLOCK 1000001
using namespace std;
int a[DIM][DIM], b[DIM][DIM], c[2][DIM*DIM];
char sol[DIM][DIM];
int n, m, i, j, poz, neg, d0;
pair<int, int> P[5], M[5];
int di[] = {-1, 1, 0, 0};
int dj[] = { 0, 0,-1, 1};
char s[DIM];
void lee(int is, int js, int a[DIM][DIM], int marc) {
    int p = 1, u = 1;
    c[0][1] = is;
    c[1][1] = js;
    a[is][js] = 1*marc;
    while (p <= u) {
        int ic = c[0][p];
        int jc = c[1][p];
        for (int d = 0; d<=3; d++) {
            int iv = ic + di[d];
            int jv = jc + dj[d];
            if (iv >= 1 && iv <= n && jv >= 1 && jv <= m && a[iv][jv] == 0) {
                u++;
                c[0][u] = iv;
                c[1][u] = jv;
                a[iv][jv] = a[ic][jc] + (1*marc);
            }
        }
        p++;
    }
}

int main () {
    ifstream fin ("labirint.in");
    ofstream fout("labirint.out");
    fin>>n>>m;
    for (i=1;i<=n;i++) {
        fin>>s+1;
        for (j=1;j<=m;j++)
            a[i][j] = b[i][j] = (s[j] == '0' ? 0 : BLOCK);
    }
    lee(1, 1, a, 1);
    d0 = a[n][m]-1;
    lee(n, m, b, -1);

    for (i=1;i<=n;i++) {
        for (j=1;j<=m;j++)
            if (a[i][j]!=BLOCK)
                sol[i][j] = '0';
            else {
                poz = 0;
                neg = 0;
                for (int d = 0; d <= 3; d++) {
                    int iv = i+di[d];
                    int jv = j+dj[d];
                    if (iv >= 1 && iv <= n && jv >= 1 && jv <= m) {
                        if (a[iv][jv] > 0)
                            P[++poz] = {iv, jv};
                        if (b[iv][jv] < 0)
                            M[++neg] = {iv, jv};
                    }
                }
                if (poz == 0 || neg == 0) {
                    sol[i][j] = '0';
                } else {
                    int rez = 0;
                    for (int ii=1;ii<=poz;ii++)
                        for (int jj=1;jj<=neg;jj++)
                            if (P[ii] != M[jj])
                                if (a[ P[ii].first ][ P[ii].second ] - 1 - b[ M[jj].first ][ M[jj].second ] + 1 < d0) {
                                    rez = 1;
                                    break;
                                }
                    sol[i][j] = '0' + rez;
                }
            }
    }

    for (i=1;i<=n;i++)
        fout<<sol[i]+1<<"\n";
	fout.close();
    return 0;
}
