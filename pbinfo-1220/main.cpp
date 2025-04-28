//Emanuela Cerchez 100 puncte
#include <fstream>
#include <cstring>
#define NMAX 5001
#define LGMAX 40001
#define INF 1000000000
using namespace std;
ifstream fin("scadere.in");
ofstream fout("scadere.out");
char s[LGMAX], snr[10];
int x[NMAX];
int st[LGMAX];
int n, cerinta;
int rez;
void sir(int x);
int evalexp();
int main()
{int i, nrp=0;
 fin>>cerinta>>n;
 for (i=1; i<=n; i++) fin>>x[i];
 if (cerinta==1)
    {
     rez=x[1]-x[2];
     for (i=3; i<=n; i++)
	      if (x[i]>=0) rez+=x[i];
		     else  rez-=x[i];
     fout<<rez<<'\n';
     fout<<"x1-";
     for (i=3; i<=n; i++)
	     {
	      if (x[i]>=0)
		     {if (nrp%2==0)
                 {fout<<"("; nrp++;}
		     }
	         else
	         {if (nrp%2)
                 {fout<<"(";  nrp++;}
		     }
	      fout<<"x"<<i-1<<"-";
	     }
     fout<<"x"<<n;
     for (i=0; i<nrp; i++) fout<<")";
     fout<<'\n';
     fout.close();
     return 0;}
 fin>>s;
 rez=evalexp();
 fout<<rez<<'\n';
 fout.close();
 return 0;
}
int evalexp()
{int vf=0, i, nr;
 st[0]=INF;
 for (i=0; s[i]; )
     if (s[i]=='(')
	      {st[++vf]=INF; i++;}
		  else
		  if (s[i]==')')
		     {if (st[vf-1]==INF) st[vf-1]=st[vf];
		         else st[vf-1]-=st[vf];
		      vf--;i++;}
		      else
			  {
		       if (s[i]=='-')i++;
			   if (s[i]=='x')
			      {i++;//sar x
		           nr=0;
		           while (s[i]>='0'&& s[i]<='9') {nr=nr*10+s[i]-'0'; i++;}
		           if (st[vf]==INF) st[vf]=x[nr];
		               else st[vf]-=x[nr];
			      }
	          }
 return st[0];
}