#include <bits/stdc++.h>
#define nmax 15
using namespace std;
int st[nmax], n, N;
char cuv[nmax]; /// cuvantul citit
char lit[nmax]; /// lit[i] memoreaza o litera distincta din cuv[]
int nr[nmax];  /// nr[i]=de cate ori apare lit[i] in cuv[]
ifstream fin("permrep.in");
ofstream fout("permrep.out");
void CitireMemorare()
{
    int i, j;
    fin >> cuv;
    N = strlen(cuv);
    n = 0;
    for (i = 0; cuv[i] != 0; i++)
    {
        /// cauta litera cuv[i] in lit[]
        for (j = 1; j <= n && cuv[i] != lit[j]; j++)
            ;
        if (j > n) /// cuv[i] nu apare in lit[]
        {
            n++;
            lit[n] = cuv[i];
            nr[n] = 1;
        }
        else nr[j]++;
    }
    /// sorteaza literele crescator in lit[]
    for (i = 1; i < n; i++)
        for (j = i + 1; j <= n; j++)
            if (lit[i] > lit[j])
            {
                char ch = lit[i];
                lit[i] = lit[j];
                lit[j] = ch;
                int x = nr[i];
                nr[i] = nr[j];
                nr[j] = x;
            }
}
void Afisare()
{
    for (int i = 1; i <= N; i++)
        fout << lit[st[i]];
    fout << "\n";
}
void Back(int top)
{
    if (top == N + 1) Afisare();
    else for (int i = 1; i <= n; i++)
        if (nr[i] > 0)
        {
            nr[i]--;
            st[top] = i;
            Back(top + 1);
            nr[i]++;
        }
}
int main()
{
    CitireMemorare();
    Back(1);
    return 0;
}