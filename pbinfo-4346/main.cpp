#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("autoruz.in");
ofstream fout("autoruz.out");
int comparare(int x[], int y[])
{
    while (x[0]>1 && x[x[0]]==0) x[0]--;
    while (y[0]>1 && y[y[0]]==0) y[0]--;
    if (x[0]!=y[0])
        return (x[0]<y[0]?-1:1);
    else
    {
        int c=x[0];
        while (x[c]==y[c] && c>0) c--;
        if (c==0)
            return 0;
        else
            return (x[c]<y[c]?-1:1);
    }
}
void init_mare(int nrMARE_d[], int nrMARE_s[])
{
    for(int i=0; i<=nrMARE_s[0]; i++)
        nrMARE_d[i] = nrMARE_s[i];
}
void afisare(int nrMARE[])
{
    for(int i=nrMARE[0]; i>=1; i--)
        fout << nrMARE[i];
}
void suma(int x[], int y[], int s[])
{
    int lg = (x[0]>=y[0]?x[0]:y[0]);
    int t = 0;
    for(int i=x[0]+1; i<=lg; i++) x[i]=0;
    for(int i=y[0]+1; i<=lg; i++) y[i]=0;
    s[0]=lg;
    for(int i=1; i<=lg; i++)
    {
        s[i] = x[i] + y[i] + t;
        t    = s[i]/10;
        s[i] = s[i]%10;
    }
    if (t==1)
        s[++s[0]]=1;
}
int cerinta, n;
char m[12], nr[8], p[56];
int main()
{
    fin >> cerinta;
    if (cerinta==1)
    {
        int autoIS=0;
        int i;
        fin >> n;
        for(i=1; i<=n; i++)
        {
            fin >> m >> nr >> p;
            fin.get();
            if (nr[0]=='I' && nr[1]=='S')
                autoIS++;
        }
        fout << autoIS++;
    }
    if (cerinta==2)
    {
        int i, j;
        int P[56], maxP[56];
        char marca[12];          // marca masinii cu pretul maxim
        fin >> n;
        // prima masina
        fin >> m >> nr >> p;
        fin.get();
        strcpy(marca, m);
        maxP[0] = strlen(p);
        for(j=0; p[j]; j++)
            maxP[maxP[0]-j] = p[j] - '0';
        // restul masinilor
        for(i=2; i<=n; i++)
        {
            fin >> m >> nr >> p;
            fin.get();
            P[0] = strlen(p);
            for(j=0; p[j]; j++)
                P[P[0]-j] = p[j] - '0';
            if (comparare(P, maxP)==1)      // algoritm maxim
            {
                init_mare(maxP, P);
                strcpy(marca, m);
            }
            else
                if (comparare(P, maxP)==0)
                    if (strcmp(marca,m)>0)  // lexicografic
                        strcpy(marca, m);
        }
        //afisare(maxP);
        fout << marca;
    }
    if (cerinta==3)
    {
        int i, j;
        int P[61];
        int sumPartiala[61];
        int sumFinala[61];
        sumFinala[0]=1;
        fin >> n;
        fin >> m >> nr >> p;
        fin.get();
        P[0] = strlen(p);
        for(j=0; p[j]; j++)
            P[P[0]-j] = p[j] - '0';
        init_mare(sumPartiala,P);
        if (n==1)
            init_mare(sumFinala,P);
        for(i=2; i<=n; i++)
        {
            fin >> m >> nr >> p;
            fin.get();
            P[0] = strlen(p);
            for(j=0; p[j]; j++)
                P[P[0]-j] = p[j] - '0';
            suma(P, sumPartiala, sumFinala);
            init_mare(sumPartiala, sumFinala);
        }
        afisare(sumFinala);
    }
    return 0;
}