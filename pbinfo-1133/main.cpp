/*
    Sursa oficiala 100p - stiva
    Complexitate: O (n)
    prof. Eugen Nodea
    Colegiul National "Tudor Vladimirescu", Tg-Jiu
*/
# include <fstream>
# include <cstring>
using namespace std;
# define max(a, b) ((a) < (b) ? (b) : (a))
# define Lmax 100003
ifstream f("charlie.in");
ofstream g("charlie.out");
char s[Lmax], st[Lmax];
int p, L, vf, k, i, Max, j;
long long S;
void afis()
{
    for(int i=1; i <=vf; ++i)
        g << st[i];
    g<< "\n";
}
int main()
{
    f >> p; f.get();
    f.getline(s, 100001);
    L = strlen(s);
    if (p == 1) //a)
    {
        k = i = 0;
        while ( i < L )
        {
            j = i;
            while (s[j] > s[j+1] && s[j+1] < s[j+2] && j + 2 < L)
                j += 2;
            if (j - i >= 2)
            {
                if ( j - i + 1 > Max ) Max = j - i + 1;
                i = j;
            }
            ++i;
        }
        g << Max << "\n";
    }
    else //b)
    {
        st[1] = s[0]; st[2] = s[1];
        i = vf = 2;
        while ( i < L )
        {
            while (s[i] > st[vf] && st[vf] < st[vf-1] && vf > 1)
            {
                S += max(s[i] - 'a' + 1, st[vf-1] - 'a' + 1);
                --vf;
            }
            st[++vf] = s[i];
            ++i;
        }
        afis();
        g << S << "\n";
    }
    return 0;
}