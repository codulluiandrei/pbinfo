// Solutia bruta
#include <bits/stdc++.h>
using namespace std;

int a[200005], n, N, minim, cnt;

void Elimina(int x)
{
    int i, j = 0;
    for (i = 1; i <= n; i++)
        if (a[i] != x)
            a[++j] = a[i];
    n = j;
}

void Minim()
{
    cnt = 0; minim = 2000000001;
    for (int i = 1; i <= n; i++)
        if (a[i] < minim)
        {
            minim = a[i];
            cnt = 1;
        }
        else if (a[i] == minim) cnt++;
}

int main()
{
    int x, op;
    ifstream fin("mset.in");
    ofstream fout("mset.out");
    fin >> N;
    while (N--)
    {
        fin >> op;
        if (op == 1)
        {
            fin >> x;
            a[++n] = x;
        }
        else if (op == 2)
        {
            fin >> x;
            Elimina(x);
        }
        else /// op = 3
        {
            if (n == 0) fout << "-1\n";
            else
            {
                Minim();
                fout << minim << " " << cnt << "\n";
            }
        }
    }
    return 0;
}
