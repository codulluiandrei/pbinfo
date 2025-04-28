#include <bits/stdc++.h>
using namespace std;
ifstream fin("sir_eval.in");
ofstream fout("sir_eval.out");
char s[30], numeVar[12];
int main()
{
    int i, a, b;
    char op;
    fin >> s;
    /// pozitionare pe '='
    for (i = 0; s[i] != '='; i++)
        ;
    s[i] = 0;
    strcpy(numeVar, s);
    i++;
    /// constructie a
    a = 0;
    while ('0' <= s[i] && s[i] <= '9')
    {
        a = a * 10 + s[i] - '0';
        i++;
    }
    op = s[i];
    i++;
    /// constructie b
    b = 0;
    while ('0' <= s[i] && s[i] <= '9')
    {
        b = b * 10 + s[i] - '0';
        i++;
    }
    if (op == '+') a += b;
    else a *= b;
    fout << numeVar << "=" << a << "\n";
    return 0;
}