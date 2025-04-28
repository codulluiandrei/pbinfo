#include <fstream>
#include <cstring>
#define LGMAX 202
#define CMAX 100002
using namespace std;
ifstream fin("virus.in");
ofstream fout("virus.out");
int n, rez, P, lgv, lgc;
int nr[CMAX];
char v[LGMAX], c[LGMAX], cmaxim[LGMAX];
void mutatie (int & poz, int& litera);
void codul(int x,char s[LGMAX]);
int main()
{int i, litera, poz, maxim;
 fin>>P>>v>>n;
 lgv=strlen(v);
 for (i=1; i<=n; i++)
     {fin>>c; lgc=strlen(c);
      mutatie(poz, litera);
      if (poz!=-1)
         {
          rez++;
          nr[poz*100+litera]++;
         }
     }
if (P==1)
   fout<<rez<<'\n';
   else
   {
    maxim=0;
    for (i=0; i<CMAX; i++)
        if (nr[i]>maxim)
            maxim=nr[i];
    cmaxim[0]='z'+1;
    for (i=0; i<CMAX; i++)
        if (nr[i]==maxim)
               {
                codul(i,c);
                if (strcmp(c,cmaxim)<0) strcpy(cmaxim,c);
               }
    fout<<cmaxim<<'\n';
   }
return 0;
}
void mutatie (int & poz, int &litera)
{int i;
 poz=-1;
 if (lgv!=lgc) return;
 for (i=0; i<lgv; i++)
      if (v[i]!=c[i])
         if (poz==-1) poz=i;
            else {poz=-1; return; }
 if (poz==-1) return;
 if (c[poz]>='A' && c[poz]<='Z') litera=c[poz]-'A';
    else litera=c[poz]-'a'+26;
}
void codul(int x,char s[LGMAX])
{int poz; char litera;
 strcpy(s,v);
 poz=x/100;
 if (x%100<26) litera='A'+x%100;
    else litera='a'+(x%100-26);
 s[poz]=litera;
}