#include <fstream>
#include <cassert>
#include <cstring>
#define LGMAX 5200002
#define LGMAXOP 300
#define NMAX 20002
using namespace std;
ifstream fin("indiciu.in");
ofstream fout("indiciu.out");
char sir[LGMAX];        //expresia
char s[LGMAX];        //auxiliar
char rez[LGMAX];
char auxrez[LGMAX];
char *valoare;
char op[NMAX][LGMAXOP]; //operanzii
int lg[NMAX];           //lungimile operanzilor
char opt[NMAX];         //operatorii
int nrop;               //numarul de operanzi
int lgcod;              //lungimea codului
long long int lungime (int x, int nrop);
int main()
{char *p;
 int i, j, k, lgrez, lgval, st, dr, lgaux, mij, last, poz;
 fin.getline(sir,LGMAX);
 p=strchr(sir,'='); *p=0;
 valoare=p+1; lgval=strlen(valoare);
 assert(0<lgval && lgval<=20000);
 p=sir;
 ///extrage operanzii si operatorii
 for (i=0; sir[i]; i++)
     if (sir[i]=='+' || sir[i]=='*')
        {
         ++nrop;
         opt[nrop]=sir[i];
         sir[i]=0;
         strcpy(op[nrop],p);
         lg[nrop]=strlen(op[nrop]);
         assert(lg[nrop]>0 && lg[nrop]<=255);
         p=sir+i+1;
        }
  ++nrop;
  strcpy(op[nrop],p);
  lg[nrop]=strlen(op[nrop]);
  assert(nrop>0 && nrop<=10001);
   assert(lg[nrop]>0 && lg[nrop]<=255);
  /*for (i=1; i<=nrop; i++) fout<<op[i]<<'\n';
  for (i=1; i<nrop; i++) fout<<opt[i];
  fout<<'\n';*/
  if (nrop==1) {fout<<valoare<<'\n'; return 0;}
  ///determin lungimea codului prin cautare binara
  st=0; dr=lgval+1;
  while (dr-st>1)
        {
         mij=(st+dr)/2;
         lgrez=lungime(mij, nrop);
         if (lgrez>=lgval) dr=mij;
            else st=mij;
        }
   if (lungime(dr, nrop)!=lgval) {fout<<"Eroare\n"; return 0;}
   //reconstitui codul
 lgcod=dr;
 for (last=nrop; op[last][0]!='#'; last--)
      if (opt[last-1]=='+')
         {valoare[lgval-lg[last]]=0; lgval-=lg[last];}
         else
         {
         for (j=i=0;valoare[i];i++)
             {s[j++]=valoare[i]; i+=lg[last];}
         s[j]=0;
         strcpy(valoare,s);
         //fout<<s<<'\n';
         lgval=j;
         }
 //last=ultima aparitie a codului
 //determin lungimea rezultatului pana la last
 poz=lungime(lgcod,last-1);
 if (last-1>0)
    if (opt[last-1]=='+')
        for (k=poz; k<poz+lgcod; k++) fout<<valoare[k];
        else
        for (k=1; k<=lgcod; k++) fout<<valoare[k];
    else
    for (k=0; k<lgcod; k++) fout<<valoare[k];
 fout<<'\n';
 return 0;
}
long long int lungime (int x, int nrop)
{long long int lgrez;
 int i;
 if (op[1][0]=='#')
    lgrez=x;
    else
    lgrez=lg[1];
  for (i=1; i<nrop; i++)
       {if (opt[i]=='+')
          {
           if (op[i+1][0]=='#') lgrez+=x;
              else lgrez+=lg[i+1];
          }
          else
          {
           if (op[i+1][0]=='#')
              lgrez+=lgrez*x;
              else
              lgrez+=lgrez*lg[i+1];
          }
        if (lgrez>LGMAX) return LGMAX;
       }
 return lgrez;
}