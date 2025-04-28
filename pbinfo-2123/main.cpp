//em. cerchez 100 puncte
#include <bits/stdc++.h>
#define NMax 20
using namespace std;
ofstream fout("relatii.out");
ifstream fin("relatii.in");
int N, M;
int R[NMax][NMax];
int p[NMax];
void citire();
void afisare();
int verif();
int main()
{
int i, j, st, dr, aux;
citire();
for (i=1; i<=N; i++) p[i]=i;
while (1)
      {
      if (verif()) break;
      //generez permutarea urmatoare
      for (j=N-1; p[j]>p[j+1]; j--);
      //maresc p[j]
      for (i=N; p[i]<p[j]; i--);
      //interschimb p[i] cu p[j]
      aux=p[i]; p[i]=p[j]; p[j]=aux;
      //inversez sufixul j+1..N
      for (st=j+1, dr=N; st<dr; st++, dr--)
          {aux=p[st];p[st]=p[dr]; p[dr]=aux;}
      }
afisare();
return 0;
}
void citire()
{
char c1, c2, c3;
int i;
fin>>N>>M;
for (i=0; i<M; i++)
    {
    fin>>c1>>c2>>c3;
    if (c2=='>')
       {R[c1-'a'+1][c3-'a'+1]=1;
        R[c3-'a'+1][c1-'a'+1]=-1;}
        else
        {
        R[c1-'a'+1][c3-'a'+1]=-1;
        R[c3-'a'+1][c1-'a'+1]=1;
        }
    }
}
void afisare()
{
int i;
for (i=1; i<=N; i++)
    fout<<(char)(p[i]-1+'a');
fout<<'\n';
fout.close();
}
int verif()
{
int i, j;
for (i=1; i<N; i++)
    for (j=i+1; j<=N; j++)
        if (R[p[i]][p[j]]==1) return 0;
return 1;
}