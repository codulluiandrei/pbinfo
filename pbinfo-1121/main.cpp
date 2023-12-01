//Cristina Sichim, C.N. Ferdinand I Bacau
#include <fstream>

using namespace std;
ifstream f("p2048.in");
ofstream g("p2048.out");

int v[10001],n,m,i,j,k,st,dr,p,X,Y,Z,z,s;
char d;

int main()
{ f>>n>>m;
  for(i=1;i<=n;++i){f>>v[i]; if(v[i]==2048) s=1;}
  st=1;dr=n;
  for(i=1;i<=m && !s;i++)
  { f>>d;
    z=0;
    if(d=='D')
      {for(j=dr;j>st;j--)
         if(v[j]==v[j-1]) {v[j]*=2;
                           if(v[j]==2048) s=1;
                           for(k=j-1;k>st;k--)v[k]=v[k-1];
                           st++;
                           z++;
                          }
      }
    else
     { for(j=st;j<dr;j++)
          if(v[j]==v[j+1]){ v[j]*=2;
                            if(v[j]==2048) s=1;
                            for(k=j+1;k<dr;k++)v[k]=v[k+1];
                            dr--;
                            z++;
                          }
     }
     X=i;
     if(z==0) X=i-1,i=m;
     Z=max(Z,z);
     if(s)i=m;
  }
Y=v[st];
for(i=st+1;i<=dr;i++)  Y=max(Y,v[i]);
g<<X<<'\n'<<Y<<'\n'<<Z<<'\n';
f.close();g.close();
    return 0;
}
