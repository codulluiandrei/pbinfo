#include <fstream>
#define inFile  "countbits.in"
#define outFile "countbits.out"
using namespace std;

int a[32768];
/// a[i]=numarul bitilor de 1 din reprezentarea in baza 2 a lui i

void Precalc()
{
    int i, cnt, x;
    a[0] = 0;
    a[1] = 1;
    for (i = 2; i <= 32767; i++)
    {
        x = i;
        cnt = 0;
        while (x > 0)
        {
            cnt++;
            x = (x & (x - 1));
        }
        a[i] = cnt;
    }
}

int main()
{
    int i, n, A, B, C, D, E, f1, f2, f3, P;
    int cnt;
    P = (1 << 15);
    Precalc();
    ifstream fin(inFile);
    ofstream fout(outFile);
    fin >> n >> A >> B >> C >> D >> E;
    f1 = A; f2 = B;
    cnt = a[f1 % P] + a[f1 / P] + a[f2 % P] + a[f2 / P];
    for (i = 3; i <= n; i++)
    {
        f3 = 1 + (1LL*f1*C + 1LL*f2*D) % E;
        cnt += (a[f3 % P] + a[f3 / P]);
        f1 = f2;
        f2 = f3;
    }
    fout << cnt << "\n";
    return 0;
}
