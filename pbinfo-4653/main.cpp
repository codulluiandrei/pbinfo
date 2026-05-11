//prof. Em. Cerchez
#include <fstream>
#include <algorithm>
#define LGMAX 1002
using namespace std;
ifstream fin("expresie.in");
ofstream fout("expresie.out");
int n, p, q, lg, suma, lgsum, lgrez;
char s[LGMAX];
char a[LGMAX];
typedef int NrMare[LGMAX];
NrMare secv, sum, rez;
void adun(NrMare x, int lgx, NrMare y, int lgy, NrMare z, int& lgz);
void dif(NrMare x, int lgx, NrMare y, int lgy, NrMare z, int& lgz);
void afisare(NrMare x, int lgx);
int compars(int i, int j);
int comparnr(NrMare x, int lgx, NrMare y, int lgy);
int main()
{int i, j, nr, imax, k, semn;
 fin>>n>>p>>q>>s;
 lg=n-p-q;
 //determin secventa de maxima lexicografic
 imax=0;
 if (p>0)
    {for (i=1; i<n-lg+1; i++)
         if (compars(i,imax)>0) imax=i;
    }
 //cifrele de secventa maxima sunt pe pozitiile imax..imax+lg-1
 nr=0;
 if (imax==0) //secventa este la inceput
    {for (j=imax+lg; j<n; j++) a[nr++]=s[j]; suma=0;}
    else
    {
     p--; //plus se pune inaintea acestei secvente
     suma=s[0]-'0';
     for (j=1; j<imax; j++) a[nr++]=s[j];
     for (j=imax+lg; j<n; j++) a[nr++]=s[j];
    }
 //sortez celelalte cifre
 sort(a,a+nr);
 //primele q vor fi cu minus, ultimele p cu plus
 for (i=0; i<q; i++) suma=suma-(a[i]-'0');
 for (i=q; i<nr; i++) suma=suma+(a[i]-'0');
 if (suma<0) {suma=-suma; semn=-1;}
    else semn=1;
 //adunam sum cu secventa maxima
 for (k=0, j=imax+lg-1; j>=imax; j--, k++) secv[k]=s[j]-'0';
 do
   {sum[lgsum++]=suma%10; suma/=10; }
 while (suma);
 if (semn==1)
    adun(secv, lg, sum, lgsum, rez, lgrez);
    else
    if (comparnr(secv,lg,sum,lgsum)>=0) {dif(secv,lg,sum,lgsum, rez, lgrez); semn=1;}
       else
       dif(sum,lgsum,secv,lg,rez,lgrez);
 if (semn==-1) fout<<'-';
 afisare(rez, lgrez);
 return 0;
}
void adun(NrMare x, int lgx, NrMare y, int lgy, NrMare z, int& lgz)
{int t, i, val;
 //cel mai scurt dintre numere il completez cu zerouri nesemnificative
 if (lgx<lgy) {lgz=lgy; for (i=lgx; i<lgy; i++) x[i]=0; }
    else {lgz=lgx; for (i=lgy; i<lgx; i++) y[i]=0; }
 //incep adunarea
 for (t=i=0; i<lgz; i++)
     {
      val=x[i]+y[i]+t;
      z[i]=val%10;
      t=val/10;
     }
 //daca a mai ramas o cifra de transport
 if (t) z[lgz++]=t;
}
void afisare(NrMare x, int lgx)
{int i;
 for (i=lgx-1; i>=0; i--) fout<<x[i];
 fout<<'\n';
}
int compars(int i, int j)
//returneaza 1 daca secventa care incepe la pozitia i este mai mare lexicografic decat secventa care incepe la pozitia j
//0 daca sunt egale
//-1 altfel
{int k;
 for (k=0; k<lg && s[i+k]==s[j+k]; k++);
 if (k==lg) return 0;
 if (s[i+k]>s[j+k]) return 1;
 return -1;
}
void dif(NrMare x, int lgx, NrMare y, int lgy, NrMare z, int& lgz)
//z=x-y (se garanteaza x>=y)
{int i, val, t;
  //cel mai scurt dintre numere il completez cu zerouri nesemnificative
 lgz=lgx; for (i=lgy; i<lgx; i++) y[i]=0;
 //incep scaderea
 for (t=i=0; i<lgz; i++)
     {
      val=x[i]-y[i]+t;
      if (val<0) {val+=10; t=-1;}
         else t=0;
      z[i]=val;
     }
 //daca am zerouri nesemnificative, le elimin
 if (lgz>1 && z[lgz-1]==0) lgz--;
}
int comparnr(NrMare x, int lgx, NrMare y, int lgy)
{int i;
 if (lgx>lgy) return 1;
 if (lgx<lgy) return -1;
 for (i=0; i<lgx && x[i]==y[i]; i++);
 if (i==lgx) return 0;
 if (x[i]<y[i]) return -1;
 return 1;
}