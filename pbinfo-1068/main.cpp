//prof.Carmen Minca
#include <fstream>
using namespace std;
int a[58][58][58],t[58][58][58];
int n,k;
ifstream f("suma5.in");
ofstream g("suma5.out");
void citeste()
{
 int i,l,c,x;
 k=0;
 f>>n;
 for(i=1;i<=n;i++)
 while (n>0)
 { k++;
   for(l=1;l<=k;l++)
    for(c=1;c<=k;c++)
       { f>>x;
	     t[k][l][c]=a[k][l][c]=x;
	   }
   n=n-k*k;
 }
 g<<k<<;//nr niveluri
 f.close();
}
void suma()
{ int i,l,c,x;
 for(i=k-1;i>=1;i--)
   for(l=1;l<=i;l++)
    for(c=1;c<=i;c++)
       { if(t[i+1][l][c]<=t[i+1][l][c+1]) x=t[i+1][l][c];
	        else x=t[i+1][l][c+1];
	     if(x>t[i+1][l+1][c])x=t[i+1][l+1][c];
	     if(x>t[i+1][l+1][c+1])x=t[i+1][l+1][c+1];
	     t[i][l][c]=t[i][l][c]+x;
       }
}
void drum()
{int c,l,i=1,s,nr=0;
  s=t[1][1][1];
  g<<s;
  g<<endl<<1;
  l=c=1;
do
{ nr=nr+i*i;
  s=s-a[i][l][c]; i++;
  if(s)
 {if(t[i][l][c]==s) {l=l;c=c;}
  else
  if(t[i][l][c+1]==s)c=c+1;
  else
  if(s==t[i][l+1][c])l=l+1;
  else  {l=l+1;c=c+1;}
  g<<<<nr+(l-1)*i+c; }
}while(s);
g<<endl;
g.close();
}
int main()
{citeste();
suma();
drum();
}