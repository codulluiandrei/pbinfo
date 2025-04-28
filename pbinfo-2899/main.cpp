#include <fstream>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <cstring>
#include <string>
#include <algorithm>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define NMAX 101
#define LMAX 60
#define MAX(a,b) (a)>(b)?(a):(b)
using namespace std;
ifstream fin("timbre.in");
ofstream fout("timbre.out");
struct timbru
{
    char serie[LMAX];
    vector<pii>valori;
    int valoare;
};
vector<string>rez;
timbru timbre[NMAX];
int nrt;
int cerinta, n;
char t[LMAX];
int lg, valoare;
bool gasit, dublura;
void c1();
void c2();
void c3();
int main()
{
    char ch;
    fin>>cerinta;
    fin>>n;
    fin.get(ch);
    for (int i=0;i<n;++i)
    {
        fin.getline(t, LMAX);
        lg = strlen(t);
        for (int j=lg-1;j>=0;--j)
        {
            if (t[j] == ' ')
            {
                t[j] = 0;
                valoare = atoi(t+j+1);
                break;
            }
        }
        gasit = false;
        for (int j=0;j<nrt;++j)
        {
            if (!strcmp(timbre[j].serie, t))
            {
                gasit = true;
                dublura = false;
                for (int k=0;k<timbre[j].valori.size();++k)
                {
                    if(timbre[j].valori[k].first == valoare)
                    {
                        ++timbre[j].valori[k].second;
                        dublura = true;
                        break;
                    }
                }
                if (!dublura)
                {
                    timbre[j].valori.pb(mp(valoare, 1));
                    timbre[j].valoare += valoare;
                }
                break;
            }
        }
        if (!gasit)
        {
            strcpy(timbre[nrt].serie, t);
            timbre[nrt].valori.pb(mp(valoare, 1));
            timbre[nrt].valoare += valoare;
            ++nrt;
        }
    }
    switch(cerinta)
    {
    case 1:
        c1();
        break;
    case 2:
        c2();
        break;
    case 3:
        c3();
        break;
    default:
        break;
    }
    fin.close();
    fout.close();
    return 0;
}
void c1()
{
    fout<<nrt<<'\n';
}
void c2()
{
    int af = 0;
    for (int i=0;i<nrt;++i)
    {
        for(int j=0;j<timbre[i].valori.size();++j)
        {
            if (timbre[i].valori[j].second == 1)
            {
                ++af;
            }
        }
    }
    fout<<af<<'\n';
}
void c3()
{
    int vMax = 0;
    for (int i=0;i<nrt;++i)
    {
        vMax = MAX(vMax, timbre[i].valoare);
    }
    for (int i=0;i<nrt;++i)
    {
        if (timbre[i].valoare == vMax)
        {
            string act(timbre[i].serie);
            rez.pb(act);
        }
    }
    sort(rez.begin(), rez.end());
    for (auto x:rez)
    {
        fout<<x<<'\n';
    }
}