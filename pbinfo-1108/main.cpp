#include <fstream>
#include <iostream>
using namespace std;
int a[105][105][105], p, u,i;
short int n,m,k1,l1,c1,k2,l2,c2,x,y,z,xc,yc,zc;
struct camera{short int x,y,z;}c[1000005];
short int dx[]={-1,0,0,0,0,1}, dy[]={0,-1,0,0,1,0},dz[]={0,0,-1,1,0,0};
ofstream g("traseu.out");
void citeste()
{ifstream f("traseu.in");
 f>>n>>m;
 f>>k1>>l1>>c1>>k2>>l2>>c2;
 for(i=1;i<=m;i++)
   {
    f>>x>>y>>z;
    a[x][y][z]=-1;
   }
 }
void bordare()
{ for(int i=0;i<=n+1;i++)
  for(int j=0;j<=n+1;j++)
  {a[0][i][j]=-1;a[n+1][i][j]=-1;
   a[i][0][j]=-1;a[i][n+1][j]=-1;
   a[i][j][0]=-1;a[i][j][n+1]=-1;
  }
}
 void coada()
 { p=u=1;
   c[1].x=k1; c[1].y=l1; c[1].z=c1;
   a[k1][l1][c1]=1;
   while((p<=u)&& (a[k2][l2][c2]==0))
   { x=c[p].x; y=c[p].y;z=c[p++].z;
     for(i=0;i<6;i++)
     { xc=x+dx[i]; yc=y+dy[i]; zc=z+dz[i];
       if (a[xc][yc][zc]==0)
         { u++;a[xc][yc][zc]=a[x][y][z]+1;c[u].x=xc; c[u].y=yc; c[u].z=zc;}
     }
    }
 }
void drum(int val)
 { while(val>0)
   {   if (a[x-1][y][z]==val-1) --x;
     else
       if (a[x][y-1][z]==val-1) --y;
       else
        if (a[x][y][z-1]==val-1) --z;
        else
        if (a[x][y][z+1]==val-1) ++z;
        else
        if (a[x][y+1][z]==val-1) ++y;
        else
        if (a[x+1][y][z]==val-1) ++x;
     --val;
     c[val].x=x; c[val].y=y; c[val].z=z;
   }
}
 int main()
 { citeste();bordare();
   coada();
   int val=a[k2][l2][c2];
   g<<val<<endl;
   c[val].x=k2; c[val].y=l2; c[val].z=c2;
   drum(val);
   for(int i=1;i<=val; i++)
        g<<c[i].x<<<<c[i].y<<<<c[i].z<<endl;
   g.close();
   return 0;
 }