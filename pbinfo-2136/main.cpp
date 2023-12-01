#include<fstream>
#include<iostream>
#include<algorithm>
using namespace std;
ifstream fin("peste.in");
ofstream fout("peste.out");
int maxi;
char c;
short int v[102][20],f[105],cerinta,n,d[25];

int maimare(int k1, int k2)//daca linia k1< linia k2 returneaza 1
{
short int N1=0,nr1[40],i;
for(i=1;i<=v[k1][0];i++)//lipesc k1k2 si obtin nr1
    if(v[k1][i]!=-1)
      nr1[++N1]=v[k1][i];
for(i=1;i<=v[k2][0];i++)
    if(v[k2][i]!=-1)
      nr1[++N1]=v[k2][i];
short int N2=0,nr2[40];//lipesc k2k1 si obtin nr2
for(i=1;i<=v[k2][0];i++)
    if(v[k2][i]!=-1)
      nr2[++N2]=v[k2][i];
for(i=1;i<=v[k1][0];i++)
    if(v[k1][i]!=-1)
      nr2[++N2]=v[k1][i];//compar nr1 si nr2 cifra cu cifra de la stanga la dreapta
i=1;
while(i<=N1)
    if(nr1[i]<nr2[i])
        return 1;
    else if(nr1[i]>nr2[i])
        return 0;
    else i++;
return 0;
}
void schimb_linia(int k1,int k2)
{   int l=max(v[k1][0],v[k2][0]);
	for(int j=0;j<=l;j++)
	  swap(v[k1][j],v[k2][j]);
}
void sortare_ptr_lipire()
{   int k1,k2;
    for(k1=1;k1<n;k1++)
        for(k2=k1+1;k2<=n;k2++)
            if(maimare(k1,k2)==1)
                schimb_linia(k1,k2);
}
void afisare()
{ int i,j;
	for(i=1;i<=n;i++)
   	for(j=1;j<=v[i][0];j++)
   	   if(v[i][j]!=-1) fout<<v[i][j];
   	fout<<'\n';
}
int main ()
{
   int i,j,k,m,p1,p2;
   long long x,cut,xmax;
    fin>>cerinta;
    fin>>n; fin.get();
    for(i=1;i<=n;i++)
    {
        j=1;
        while(1)
        {
            fin.get(c);
            if(c!='\n')
            {
                v[i][j]=c-'0';
                j++;
            }
            else
                break;
        }
        v[i][0]=j-1;
    }
    for(i=1;i<=n;i++)
        {
            for(j=1,xmax=0;j<=v[i][0]-1;j++)
            {
                for(k=1;k<=v[i][0];k++)
                    d[k]=v[i][k];
                m=v[i][0]-2;
                for(k=j;k<=m;k++)
                    d[k]=d[k+2];
                for(k=1,x=0;k<=m;k++)
                    x=x*10+d[k];
                if(x>xmax)
                {
                    xmax=x;
                    p1=j;p2=j+1;
                    if(v[i][j]>v[i][j+1])
                       cut=v[i][j]*10+v[i][j+1];
                    else
                      cut=v[i][j+1]*10+v[i][j];
                }
            }
            v[i][p1]=-1;v[i][p2]=-1;
            f[cut]++;
        }
        for(i=0,maxi=0;i<=99;i++)
            if(f[i]>maxi)
                maxi=f[i];

if(cerinta==1)
        fout<<maxi<<'\n';
    else
    {
      sortare_ptr_lipire();
      afisare();
    }
fin.close();
fout.close();
return 0;
}

