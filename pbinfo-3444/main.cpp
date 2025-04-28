/// Sursa oficiala - 100p
/// prof. Eugen Nodea
# include <bits/stdc++.h>
using namespace std;
ifstream f("arh.in");
ofstream g("arh.out");
string T, S;
int i, L, nra;
string eval1();     /// calculeaza parantezele ()
string eval2();     /// calculeaza parantezele []
string sir();       /// formeaza sir de caractere
int numar();       /// formeaza numarul
void eval()
{
    while (i < T.size())
    {
        S += sir();
        int nr = numar();
        if (nr)
        {
            string r1 = eval1();
            for(int j=1; j<=nr; ++j)
                S += r1;
        }
        else
            if (T[i] == '[')S += eval2();
            else S += sir();
    }
}
string eval1()
{
    string r = "";
    if (T[i] == '(') i++;
    while (T[i] != ')')
    {
        r += sir();
        if (T[i] == '[') r += eval2();
        r += sir();
        int nr = numar();
        if (nr)
        {
            string r1 = eval1();
            for(int j=1; j<=nr; ++j)
                r += r1;
        }
        r += sir();
    }
    i++;
    return r;
}
string eval2()
{
    int par = 0;
    string r = "", r1 = "";
    if (T[i] == '[') i++;
    if (T[i] == '*') par = 1, i++;
    while (T[i] != ']')
    {
        r += sir();
        if (T[i] == '[') r += eval2();
        if (isdigit(T[i]))
        {
            int nr = numar();
            string r1 = eval1();
            for(int j=1; j<=nr; ++j)
                r += r1;
        }
        r += sir();
        if (T[i] == '*') i++;
    }
    if (T[i] == ']')
    {
        r1 = r;
        if (!par)
        {
            r1.erase(r1.end()-1);
        }
        reverse(r1.begin(), r1.end());
        i++;
    }
    return r + r1;
}
string sir()
{
    string r = "";
    while(isalpha(T[i]))
        r += T[i], i++;
    return r;
}
int numar()
{
    int r = 0;
    while (isdigit(T[i]))
    {
        r = r * 10 + (T[i] - '0');
        i++;
    }
    return r;
}
int main()
{
    f >> T;
    L = T.size();
    for(int i=0; i<L; ++i)
        if (T[i] == '(' || T[i] == '[') nra++;
    g << nra << "\n";
    eval();
    g << S;
    return 0;
}