#include <fstream>
#include <iostream>
#define nmax 10005
#define inFile  "mixperm.in"
#define outFile "mixperm.out"

using namespace std;

int a[nmax], b[nmax], n;
int sta[nmax], dra[nmax], stb[nmax], drb[nmax];
int suma_st[nmax], sumb_st[nmax], suma_dr[nmax], sumb_dr[nmax];
long long app_st[nmax], bpp_st[nmax], app_dr[nmax], bpp_dr[nmax];
int S, sTotal;
long long sPP;

void Citire()
{
    int i;
    ifstream fin(inFile);
    fin >> n;
    for (i = 1; i <= n; i++)
        fin >> a[i];
    for (i = 1; i <= n; i++)
        fin >> b[i];
    fin.close();
}

void Precalculare()
{
    int i;
    S = 0;
    sTotal = n * (n + 1) / 2;
    sPP = 1LL * n * (n + 1) * (2 * n + 1) / 6;
    for (i = 1; i <= n; i++)
    {
        S = S ^ i;
        sta[i] = sta[i - 1] ^ a[i];
        stb[i] = stb[i - 1] ^ b[i];
        suma_st[i] = suma_st[i - 1] + a[i];
        sumb_st[i] = sumb_st[i - 1] + b[i];
        app_st[i] = app_st[i - 1] + a[i] * a[i];
        bpp_st[i] = bpp_st[i - 1] + b[i] * b[i];
    }
    for (i = n; i >= 1; i--)
    {
        dra[i] = dra[i + 1] ^ a[i];
        drb[i] = drb[i + 1] ^ b[i];
        suma_dr[i] = suma_dr[i + 1] + a[i];
        sumb_dr[i] = sumb_dr[i + 1] + b[i];
        app_dr[i] = app_dr[i + 1] + a[i] * a[i];
        bpp_dr[i] = bpp_dr[i + 1] + b[i] * b[i];
    }
}

inline bool Valid(int j, int i, int aSum, int bSum)
{
    if ((S ^ sta[j - 1] ^ bSum ^ dra[i + 1]) == 0 &&
        sTotal==suma_st[j-1] + suma_dr[i+1]+(sumb_st[i] - sumb_st[j - 1]) &&
        sPP==app_st[j-1] + app_dr[i+1]+(bpp_st[i] - bpp_st[j - 1]))
            return true;
    if ((S ^ stb[j - 1] ^ aSum ^ drb[i + 1]) == 0 &&
        sTotal==sumb_st[j-1] + sumb_dr[i+1]+(suma_st[i] - suma_st[j - 1]) &&
        sPP==bpp_st[j-1] + bpp_dr[i+1]+(app_st[i] - app_st[j - 1]))
            return true;
    return false;
}

void Rezolvare()
{
    int ans, i, j, aSum, bSum;
    ans = 0;
    for (i = 1; i <= n; i++)
    {
        aSum = bSum = 0;
        for (j = i; j >= 1; j--)
        {
            aSum = aSum ^ a[j];
            bSum = bSum ^ b[j];
            if (Valid(j, i, aSum, bSum))
            {
                ans++;
                ///cout << j << " " << i << "\n";
            }
        }
    }

    ofstream fout(outFile);
    fout << ans << "\n";
    fout.close();
}

int main()
{
    Citire();
    Precalculare();
    Rezolvare();
    return 0;
}
