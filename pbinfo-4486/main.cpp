#include <bits/stdc++.h>
using namespace std;
int n, m, A, B;
int sol[3000], k;
int NrCif(int n)
{
    if (n < 10) return 1;
    return 1 + NrCif(n / 10);
}
void Back(int top, int val)
{
    if (top > n)
    {
        if (val >= A && val <= B)
            sol[k++] = val;
    }
    if (top <= m)
    {
        int cif = val % 10;
        for (int i = cif - 1; i <= cif + 1; i += 2)
            if (i >= 0 && i <= 9)
                Back(top + 1, val * 10 + i);
    }
}
int main()
{
    cin >> A >> B;
    n = NrCif(A);
    m = NrCif(B);
    for (int i = 1; i <= 9; i++)
        Back(2, i);
    sort(sol, sol + k);
    for (int i = 0; i < k; i++)
        cout << sol[i] << "\n";
    return 0;
}