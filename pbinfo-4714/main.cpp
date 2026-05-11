#include <fstream>
#define inFile "sprime.in"
#define outFile "sprime.out"
using namespace std;
bool a[100001];
int prime[10000], n, s;
int main()
{
    int i, j, cnt, x;
    // citire
    ifstream fin(inFile);
    fin >> s;
    fin.close();
    // ciurul lui Eratostene
    for (i = 4; i <= s; i += 2)
        a[i] = true;
    for (i = 3; i * i <= s; i += 2)
        if (!a[i])
            for (j = i * i; j <= s; j = j + 2 * i)
                a[j] = true;
    n = 1;
    prime[1] = 2;
    for (i = 3; i <= s; i += 2)
        if (!a[i]) prime[++n] = i;
    // calcul
    cnt = 0;
    for (i = 1; i <= n; ++i)
        for (j = i; j <= n && prime[i]+prime[j] <= s - prime[j]; j++)
        {
            x = s - (prime[i]+prime[j]);
            if (!a[x] && prime[j] <= x)
                cnt++;
        }
    ofstream fout(outFile);
    fout << cnt << "\n";
    fout.close();
    return 0;
}