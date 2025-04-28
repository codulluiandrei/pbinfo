//autor Carmen Minca - 100p
#include <fstream>
using namespace std;
int a[185][185];
ifstream f("teren.in");
ofstream g("teren.out");
int main()
{int n,t,m, r,c,i,j,p,nrb=0,nrc=0,x,y,z,u,k,lat,ok,nr;
f>>p>>n>>m>>t>>r>>c;
for(k=1;k<=t;k++)
{  f>>x>>y>>z>>u;
   for(i=x;i<=z;i++)
        for(j=y;j<=u;j++)
        {a[i][j]++;
         nrb=max(nrb,a[i][j]);}
}
if(p==1) g<<a[r][c]<<'\n';///cerinta 1
else if(p==2)g<<nrb<<'\n';  ///cerinta 2
else{
///cerinta 3
for(i=1;i<=n-nrc; i++)
    for(j=1;j<=m-nrc;j++)
      if(a[i][j]==0)
        { lat=1; ok=1;
          while(ok)
            {x=z=lat+i;y=u=lat+j;
             if(x>n || y>m)ok=0;
             while(z>=i && ok )
              { if(a[x][u]+a[z][y]==0){u--; z--;}
                else ok=0;
              }
             if(ok)lat++;
            }
          nrc=max(lat, nrc);
        }
g<<nrc*nrc<<'\n';}
return 0;
}