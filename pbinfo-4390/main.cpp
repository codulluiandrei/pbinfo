// Popa Sebastian
// Universitatea din Bucuresti
#include <bits/stdc++.h>
using namespace std;
ifstream f("bingo.in");
ofstream g("bingo.out");
const string bingo = "bingo";
void get_pre();
int solve(const string &);
int solve2(const string &, const string &);
int solve3(const vector<int>);
int letind[130];
vector<int> indpre[5], indsuf[5], pre;
vector<string> allp;
int main()
{
    get_pre();
    string s;
    int t;
    for (f >> t; t; t--)
        f >> s, g << solve(s) << '\n';
    return 0;
}
int solve(const string &s)
{
    // precalculam pt fiecare pozitie prima aparitie din stanga si prima
    // din dreapta a caracterelor {b,i,n,g,o}
    for (int i = 0; i < 5; i++)
        indpre[i].assign(s.size(), -1), indsuf[i].assign(s.size(), -1);
    for (int i = 0; i < (int)s.size(); i++)
        for (int j = 0; j < 5; j++)
            if (s[i] == bingo[j])
                indpre[j][i] = i;
            else if (i)
                indpre[j][i] = indpre[j][i - 1];
    // indpre[j][i] = primul caracter egal cu bingo[j] din stanga lui i (inclusiv)
    for (int i = s.size() - 1; i >= 0; i--)
        for (int j = 0; j < 5; j++)
            if (s[i] == bingo[j])
                indsuf[j][i] = i;
            else if (i != s.size() - 1)
                indsuf[j][i] = indsuf[j][i + 1];
    // indsuf[j][i] = priul caracter egal cu bingo[j] din dreapta lui i (inclusiv)
    static int minim;
    minim = (1 << 28);
    // pentru fiecare anagrama vedem cum o putem obtine optim drept substring
    // dupa care adaugam costul de transformare a ei in bingo
    for (int i = 0; i < 120; i++)
        minim = min(minim, solve2(s, allp[i]) + pre[i]);
    return minim;
}
int solve2(const string &s, const string &p) // pentru fiecare caracter egal cu cel din mijloc
// gasim cele mai apropiate pozitii pentru celelalte caractere
{
    static int minim;
    minim = (1 << 28);
    for (int i = 0, p0, p1, p2, p3, p4; i < (int)s.size(); i++)
        if (s[i] == p[2])
        {
            p2 = i;
            p1 = indpre[letind[p[1]]][p2];
            if (p1 == -1)
                continue;
            p0 = indpre[letind[p[0]]][p1];
            if (p0 == -1)
                continue;
            p3 = indsuf[letind[p[3]]][p2];
            if (p3 == -1)
                continue;
            p4 = indsuf[letind[p[4]]][p3];
            if (p4 == -1)
                continue;
            minim = min(minim, solve3({p0, p1, p2, p3, p4}));
        }
    return minim;
}
int solve3(const vector<int> v) // cate mutari trebuie facute sa aducem
                                // caracterele langa cel din mijloc
{
    static int s;
    s = 0;
    for (int j = 0; j < 5; j++)
        if (j < 2)
            s += v[2] - v[j] + j - 2;
        else
            s += v[j] - v[2] + 2 - j;
    return s;
}
void get_pre() // precalculam toate anagramele sirului bingo (allp[]) si cate
               // inversiuni are fiecare   (pre[])
{
    string s;
    int cnt, i0, i1, i2, i3, i4;
    for (int i = 0; i < 5; i++)
        letind[bingo[i]] = i;
    for (i0 = 0; i0 < 5; i0++) // instead of next_permutation()
        for (i1 = 0; i1 < 5; i1++)
            if (i1 != i0)
                for (i2 = 0; i2 < 5; i2++)
                    if (i2 != i0 && i2 != i1)
                        for (i3 = 0; i3 < 5; i3++)
                            if (i3 != i0 && i3 != i1 && i3 != i2)
                            {
                                i4 = 10 - i0 - i1 - i2 - i3;
                                s = "", cnt = 0;
                                s += bingo[i0], s += bingo[i1], s += bingo[i2];
                                s += bingo[i3], s += bingo[i4];
                                for (int i = 0; i < 4; i++)
                                    for (int j = i + 1; j < 5; j++)
                                        if (letind[s[i]] > letind[s[j]])
                                            cnt++;
                                allp.push_back(s), pre.push_back(cnt);
                            }
}