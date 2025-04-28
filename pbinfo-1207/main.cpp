//Carmen Popescu - 100 puncte
#include <fstream>
using namespace std;
int nr[10],  // nr[k] = numarul de cifre k din toate numerele date
    m,       // numarul maxim de cifre
    a[9][10][10],  // a[i][j][k] numarul de numere de j cifre
                   //            care contin pe pozitia i
                   //            cifra k
    t[10],         // t[k] numarul de numere avand k cifre
    b[10][10],     // b[i][j] = numarul de numere cu j cifre care nu au inca
                   //           completata cifra de pe pozitia i
    sum[10000];    // suma numerelor finale, numar mare
                   // sum[0] cifra unit, sum[1]=cifra zecilor etc
ifstream fin("cifre9.in");
ofstream fout("cifre9.out");
void citire()
{
    int x,k,n,i;
    fin>>n;
    for (i=0;i<n;i++)
    {
        fin>>x;
        if (x==0)
        {
            nr[0]++;
            t[1]++;
        }
        else
        {
            k=0;
            while (x>0)
            {
                nr[x%10]++;
                x=x/10;
                k++;
            }
            t[k]++;
            if (k>m)
                m=k;
        }
    }
}
int minim(int &a,int &b)
{
    int m;
    m=a;
    if (b<m)
        m=b;
    a=a-m;
    b=b-m;
    return m;
}
void distrib()
{
    int i,j,k,p,q,mx=0;
    for (i=0;i<=m;i++)
        for (j=i+1;j<=m;j++)
            b[i][j]=t[j];
    // 0 la cifra unitatilor
    k=0;
    for (j=1;j<=m && nr[0]>0;j++)
        a[0][j][0]=minim(b[0][j],nr[0]);
    // 0 la cifra de pe pozitia i (i=1, cifra zecilor, i=2 cifra sutelor ect)
    // ATENTIE! numerele de q cifre nu pot avea pe pozitia q-1 cifra 0
    for (i=1;i<=m && nr[0]>0;i++)
        for (j=i+2;j<=m;j++)
            a[i][j][0]=minim(b[i][j],nr[0]);
    // distribuim celelalte cifre (cifrele diferite de 0)
    for (k=1;k<=9;k++)   // cifra
        for (i=0;i<m && nr[k]>0;i++)  // pozitia
            for (j=i+1;j<=m && nr[k]>0;j++)  // nr de cifre
            {
                q=minim(b[i][j],nr[k]);
                if (t>0)
                {
                    a[i][j][k]=q;
                    sum[i]+=q*k;  // cifra k apare de q
                                  // ori pe pozitia i
                                  // => k*q pe pozitia i in suma
                    p=i;          // verificam transportul
                    while (sum[p]>9)
                    {
                        q=sum[p]/10;
                        sum[p]=sum[p]%10;
                        p++;
                        sum[p]+=q;
                        if (p>mx)   // mx numarul de cifre din suma
                            mx=p;
                    }
                }
            }
    for (i=mx;i>=0;i--)
        fout<<sum[i];
    fout<<"\n";
}
void constr()
{
    int i,j,c,nr,p=0;
    for (j=m;j>=1;j--)   // numarul de cifre
        while (t[j]>0)   // numarul de numere cu j cifre
        {
            nr=0;
            for (i=j-1;i>=0;i--)
            {
                c=9;
                while (a[i][j][c]==0)
                    c--;
                nr=nr*10+c;
                a[i][j][c]--;
            }
            fout<<nr<<'\n';
            p=1;
            t[j]--;
        }
 }
int main()
{
    citire();
    distrib();
    constr();
    return 0;
}