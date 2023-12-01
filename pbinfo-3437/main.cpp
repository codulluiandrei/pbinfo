//Em. Cerchez 100 puncte
#include <fstream>
#include <cstring>
#define LGMAX 21
#define LMAX 100
#define NMAX 6002

using namespace std;
ifstream fin("datorii.in");
ofstream fout("datorii.out");
struct firma
      {
       char nume[LGMAX];
       long long int SD, SP;
      } ;
int n, D, cerinta, lg;
firma F[NMAX];
char s[LMAX];
int cauta(char * s);
int main()
{int i, j, nr, p10, poz1, poz2;
 char *p, c;
 fin>>cerinta>>D;fin.get(c);
 for (i=0; i<D; i++)
      {
       fin.getline(s,LMAX);
       lg=strlen(s);
       nr=0; p10=1;
       for (j=lg-1; s[j]>='0' && s[j]<='9'; j--)
            {
             nr=nr+p10*(s[j]-'0');
             p10*=10;
            }
        s[j]=0;
        p=strchr(s,'>');
        *(p-1)=0;
        poz1=cauta(s);   F[poz1].SD+=nr;
        poz2=cauta(p+2); F[poz2].SP+=nr;
      }
  if (cerinta==1)
      fout<<n<<'\n';
      else
      for (i=1; i<=n; i++)
          fout<<F[i].nume<<' '<<F[i].SD<<' '<<F[i].SP<<'\n';
  fout.close();
  return 0;
}


int cauta(char * s)
{int st=0, dr=n+1, mij, i;
while (dr-st>1)
      {
       mij=(st+dr)/2;
       if (strcmp(F[mij].nume,s)<0) st=mij;
          else dr=mij;
      }
 if (dr<=n && strcmp(F[dr].nume,s)==0) return dr;
 for (i=n; i>=dr; i--) F[i+1]=F[i];
 n++;
 F[dr].SD=F[dr].SP=0;
 strcpy(F[dr].nume,s);
 return dr;
}
