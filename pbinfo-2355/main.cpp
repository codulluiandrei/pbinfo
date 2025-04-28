#include <fstream>
using namespace std;
ifstream fin("card.in");
ofstream fout("card.out");
int xd[]={-1,-1,0,1,1,1,0,-1},yd[]={0,1,1,1,0,-1,-1,-1};
long long val;
int n,m,k,a[52][52],viz[52][52],xstart,ystart,nrsol,sol[20],nr,s[20],nrsolutii;
void copie(int s[],int sol[],int nrsol)
{for(int i=1;i<=nrsol;i++)
sol[i]=s[i];
}
void bordare()
{
    int i;
    for(i=0;i<=n+1;i++)
        viz[i][0]=viz[i][m+1]=-1;
     for(i=0;i<=m+1;i++)
        viz[0][i]=viz[n+1][i]=-1;
    }
void citire()
{int i,j;
fin>>n>>m>>xstart>>ystart>>k;
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        fin>>a[i][j];
}
void bkt(int x,int y)
{int xn,yn;
    if(val==a[xstart][ystart])
    {
       if(nr<nrsol||nrsol==k+1)
    {
        nrsol=nr;nrsolutii=1;k=nr;
        copie(s,sol,nrsol);
    }
    else
        if(nr==nrsol)              //solutia s are nr elemente; sol optima sol are nrsol elemente
       {
           nrsolutii++;            //nrsolutii retine numar de solutii obtinute
         if(s[nr]<sol[nrsol])
        {
             copie(s,sol,nrsol);
        }
        else
            if(s[nr]==sol[nrsol]&&s[1]<sol[1])
                copie(s,sol,nrsol);
        }
    }
    else
        for(int dir=0;dir<8;dir++)
        {xn=x+xd[dir];yn=y+yd[dir];
         if(viz[xn][yn]==0&&nr<k)
            {viz[xn][yn]=1;
                for(int i=0;i<4;i++)                //aleg operatia
            {
                switch(i)
                  { case 0:val+=a[xn][yn];break;
                    case 1:val-=a[xn][yn];break;
                    case 2:val+=2*a[xn][yn];break;
                    case 3:val+=(a[xn][yn]/2);break;
                }
                nr++;
                s[nr]=a[xn][yn];
                bkt(xn,yn);
                nr--;
                switch(i)
                {   case 0:val-=a[xn][yn];break;
                    case 1:val+=a[xn][yn];break;
                    case 2:val-=2*a[xn][yn];break;
                    case 3:val-=(a[xn][yn]/2);break;
                }
            }
            viz[xn][yn]=0;
          }
       }
}
int main()
{int i;
citire();
bordare();
viz[xstart][ystart]=1;
nr=0;nrsol=k+1;
bkt(xstart,ystart);
fout<<nrsolutii<<endl;
for(i=1;i<=nrsol;i++)
    fout<<sol[i]<<" ";
    return 0;
}