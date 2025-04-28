/// Sursa oficiala O(ValMax*log(ValMax) + Q*log(ValMax))
#include <fstream>
using namespace std;
ifstream f("macarie.in");
ofstream g("macarie.out");
const int NMAX = 1e6;
int C, N, M, Q;
int A[NMAX + 5];
int NrMultipli[NMAX + 5];
int cnt = 0;
struct lista
{
    int div, frecv;
};
lista Divizori[NMAX + 5];
void Precalculare()
{
    for (int i = 1; i <= N; ++i) /// NrMultipli[x] va retine pentru cate numere din sirul citit x este divizor
        NrMultipli[A[i]]++;      /// valorile din sir ul citit
    for (int d = 1; d <= NMAX; ++d)
        for (int j = 2 * d; j <= NMAX; j += d)
            NrMultipli[d] += NrMultipli[j];
    for (int i = 1; i <= NMAX; ++i)
        if (NrMultipli[i] != 0)
            Divizori[cnt].div = i, Divizori[cnt].frecv = NrMultipli[i], cnt++; /// creez lista divizori memorand {divizor,frecventa}
}
int main()
{
    f >> N >> Q;
    for (int i = 1; i <= N; ++i)
        f >> A[i];
    Precalculare();
    for (int i = 1; i < cnt; ++i)
        Divizori[i].frecv += Divizori[i - 1].frecv; /// sume partiale pe lista Divizorilor, a.i. Divizor[i].frecv este ultima
                                                    /// pozitie pe care apare i in lista divizorilor
    for (int i = 1; i <= Q; ++i)
    {
        int x = 0;
        f >> x;
        int st = 0, dr = cnt - 1;
        int pos = 0;
        while (st <= dr)
        { /// caut binar valoare divizorului aflat pe pozitia x
            int mij = (st + dr) / 2;
            if (x <= Divizori[mij].frecv)
            {
                dr = mij - 1;
                pos = mij;
            }
            else
                st = mij + 1;
        }
        g << Divizori[pos].div;
        if (i < Q)
            g << ' ';
        else
            g << '\n';
    }
    return 0;
}