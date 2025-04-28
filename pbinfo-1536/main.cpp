#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define InFile "ecuatii.in"
#define OutFile "ecuatii.out"
#define LgMax 300
using namespace std;
char s[LgMax],s1[LgMax],s2[LgMax];
int n;
long nr1, nr2, nrx1, nrx2;
void rezolva(char *, long &, long &);
int main()
{
FILE * fin=fopen(InFile,"r");
FILE * fout=fopen(OutFile,"w");
int i;
char *p;
fscanf(fin,"%d", &n);
for (i=0; i<n; i++)
    {
       fscanf(fin,"%s", s1);
       p=strchr(s1,'=');
       strcpy(s2,p+1);
       *p=NULL;
       rezolva(s1, nr1, nrx1);
       rezolva(s2, nr2, nrx2);
       if (nrx1==nrx2)
          if (nr1==nr2)
             fprintf(fout,"infinit\n");
             else
             fprintf(fout,"imposibil\n");
          else
          fprintf(fout,"%.4lf\n",((double)(nr2-nr1)/(nrx1-nrx2)));
    }
fclose(fin);
fclose(fout);
return 0;
}
void rezolva(char *s, long &nr, long &nrx)
{char *p, ss[LgMax];
 long v;
 int semn=1, l;
strcpy(ss,s);
p=strtok(ss,"+-");
nr=0; nrx=0;
while (p)
      {
      l=strlen(p);
      if (p[0]=='x') nrx+=semn;
      else
      if (p[l-1]=='x')
         {p[l-1]=NULL;
          v=atol(p);
          nrx=nrx+semn*v;
         }
         else
         {v=atol(p);
         nr=nr+semn*v;}
      if (s[p+l-ss]=='+')
         semn=1;
         else
         semn=-1;
      p=strtok(NULL, "+-");
      }
}