#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
struct parcela{ unsigned int indice, latime;
              } C[10002];
ifstream fin("praslea.in");
ofstream fout("praslea.out");
long long N,L,M,P,indice_precedent,alaturate,max_parcele,Pom;
bool cmp(parcela a,parcela b)
{
return a.indice<b.indice;
}
int main()
{
int i,ok=0;
fin>>N>>M>>L;
float x;
//citirea datelor
for(i=0;i<M;++i)
fin>>C[i].indice>>C[i].latime;
M++;
C[M].indice=N+1;C[M].latime=0; //sortarea parcelelor in functie de indice
fin>>P;
sort(C,C+M,cmp);
max_parcele=N-C[M-1].indice;
i=0;
while(i<M)
{
    alaturate=C[i].indice-indice_precedent-1;
    max_parcele=max(max_parcele,alaturate);            //rezolvare cerinta a)
    if(!ok && P<=(alaturate*L))
       {Pom=indice_precedent+ceil((double)P/L);ok=1;} // pomul e inaintea parcelei curente
    else
    {
        if (alaturate>0) P=P-(alaturate)*L;
        if(!ok && P<=C[i].latime)                 //pomul e in parcela curenta
           {Pom=C[i].indice;ok=2;}
        else
         P=P-C[i].latime;                        // pomul e situat la dreapta parcelei curente
    }
    indice_precedent=C[i].indice;
    i++;
}
fout<<max_parcele<<'\n';
if(ok==0)
Pom=C[M-1].indice+ceil((double)P/L);  //pomul e situat la drapta ultimei parcele din cele M citite
fout<<Pom<<'\n';
return 0;
}