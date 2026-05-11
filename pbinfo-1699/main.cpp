///prof. prop. Rotar Mircea
#include <fstream>
using namespace std;
char ch,a[202][202];
       /**E V S N**/
int dx[]={0,0,1,-1},
    dy[]={1,-1,0,0};
int P,n,K,lin,col,i,j,k,ok=0,depl[4],dir;
ifstream f("robotel.in");
ofstream g("robotel.out");
int main()
{
    f>>P>>n>>K;
    for(i=1;i<=K;i++)
    {
        f>>lin>>col>>ch;
        if( ch == 'E') a[lin][col] = 1;
        if( ch == 'V') a[lin][col] = 2;
        if( ch == 'S') a[lin][col] = 3;
        if( ch == 'N') a[lin][col] = 4;
    }
    if(P==1)
    {
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                if(a[i][j]==1)///caut E-V
                {
                    for(k=j+1;k<=n && a[i][k]==0;k++);
                    if(a[i][k]==2)
                    {
                        g<<i<<" "<<j<<" "<<i<<" "<<k<<'\n';
                        ok++;
                    }
                    j=k-1; ///sar peste spatii pentru urmatoarea cautare
                }
                if(a[i][j]==3)///caut S-N
                {
                    for(k=i+1;k<=n && a[k][j]==0;k++);
                    if(a[k][j]==4)
                        {
                            g<<i<<" "<<j<<" "<<k<<" "<<j<<'\n';
                            ok++;
                        }
                }
            }
            if(ok==0) g<<ok<<'\n';
            return 0;
    }
    else
    {
        lin=1;col=1;
        dir=0; ///directia de deplasare E<-0, V<-1, S<-2, N<-3
        ok=1;
        if(a[1][1]!=0)
        {
            dir=a[1][1]-1;
        }
        if(dir==3 || dir==1) ok=0;
        while(ok)
        {
          lin+=dx[dir];col+=dy[dir];
          if(lin==0||lin==n+1||col==n+1||col==0){ok=0;}
          if (ok) depl[dir]++;
          if(a[lin][col]!=0){
                if ( (a[lin][col] + dir+1)%4==3 ) ok = 0; ///N-S,E-V
            dir=a[lin][col]-1;
          }
        }
        g<<depl[3]<<" "<<depl[0]<<" "<<depl[2]<<" "<<depl[1]<<'\n';
    }
    return 0;
}