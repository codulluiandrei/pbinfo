#include <fstream>
#include <cstring>
#define LGMAX 100
using namespace std;
ifstream fin("virgule.in");
ofstream fout("virgule.out");
char s[LGMAX];
int sol[LGMAX], solmin[LGMAX];
int nrmin, lg;
void afisare();
void bkt(int k);
void copiaza(int k);
int Compar(int inc1, int sf1, int inc2, int sf2);
int main()
{int i;
 fin>>(s+1);
 lg=strlen(s+1);
 for (i=lg-1; i>=1; i--)
        {
          sol[1]=i;
          bkt(2);
        }
 afisare();
 return 0;
}
void bkt(int k)
{int rez, i;
 rez=Compar(sol[k-1]+1,lg, sol[k-2]+1,sol[k-1]);
 if (rez<=0) return ;
 rez=Compar(solmin[nrmin]+1, lg, sol[k-1]+1, lg);
 if (rez>0) copiaza(k);
     else
     if (rez==0)
         {
          i=1;
          while (i<k-1 && sol[i]==solmin[i]) i++;
          if (Compar(sol[i-1]+1, sol[i], solmin[i-1]+1, solmin[i])>0) copiaza(k);
         }
 //incerc sa mai pun o virgula dupa cifra de pe pozitia i
 for (i=lg-1; i>sol[k-1]; i--)
        {
          rez=Compar(sol[k-2]+1, sol[k-1], sol[k-1]+1,i);
          if (rez>=0) break;
          sol[k]=i;
          bkt(k+1);
        }
}
void afisare()
{int i, k;
 k=1;
 for (i=1; i<=lg; i++)
     {fout<<s[i];
      if (i==solmin[k]) {fout<<','; k++;}
     }
  fout<<'\n';
}
void copiaza(int k)
{ int i;
  nrmin=k-1;
  for (i=1; i<k; i++) solmin[i]=sol[i];
}
int Compar(int inc1, int sf1, int inc2, int sf2)
{int i, j;
 while (inc1<sf1 && s[inc1]=='0') inc1++;
 while (inc2<sf2 && s[inc2]=='0') inc2++;
 if (sf1-inc1+1>sf2-inc2+1) return  1;
 if (sf1-inc1+1<sf2-inc2+1) return -1;
 //au aceeasi lungime
 for (i=inc1, j=inc2; i<=sf1 && s[i]==s[j]; i++, j++);
 if (i>sf1) return 0;
 if (s[i]<s[j]) return -1;
 return 1;
}