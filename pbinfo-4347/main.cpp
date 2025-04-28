#include <bits/stdc++.h>
using namespace std;
ifstream fin("matematica.in");
ofstream fout("matematica.out");
char s[1001], s1[1001];
long long int nr, t, S, i, g, c, nrmic;
int main ()
{
    fin >> c>>s;
    strcpy (s1, s);
    char *p = strtok (s, "+-");
    while (p)
    {
        nr = 0;
        for (i = 0; i < strlen (p); i++)
            nr = nr * 10 + (p[i] - '0');
        if (s1[p - s - 1] == '+' || p==s)
            t = 1;
        if (s1[p - s - 1] == '-')
            t = -1;
        if(g==0) nrmic=t*nr,g=1;
        else
           if(t*nr<nrmic ) nrmic=t*nr;
        /// fout<<t*nr<<endl;
        S = S + t * nr;
        p = strtok (NULL, "+-");
    }
    if(c==1)
        fout << S;
    else
        fout<<S-2*nrmic;
    return 0;
}