// Prof. Nicu Vlad-Laurentiu
#include<fstream>
#define N 302
#define D 100002
#include<cstring>
using namespace std;
int a[N][N];
char v[N][N];
int m,n;
//xi yi=pozitiile initial
//xf,yf=pozitiile finale
//m,n dimensiunile matricii
const int dx[]={0,0,0,1,-1};
const int dy[]={0,1,-1,0,0};
//am presupus ca se poate merge in 4 directii: sus, jos, st,dr
int cx[D],cy[D];
//coada
int lee(int xi,int yi,int xf,int yf)
{
        int f,b,x,y,xx,yy,i;
        memset(a,0,sizeof(a));
        b=1;
        f=1;
        cx[f]=xi;
        cy[f]=yi;
        while (f<=b)
        {
                x=cx[f];
                y=cy[f];
                f++;
                for (i=1;i<=4;i++)
                {
                        xx=x+dx[i];
                        yy=y+dy[i];
                        if (xx==xf&&yy==yf)
                                return a[x][y]+1;
                        //nu fac bordare si verific daca cooronatele se afla in matrice
                        if (xx>0&&yy>0&&xx<=n&&yy<=m)
                        {
                                //verific daca locul respectiv e liber si daca casuta nu a mai fost vizitata
                                if (v[xx][yy]=='a'&&a[xx][yy]==0)
                                {
                                        a[xx][yy]=a[x][y]+1;
                                        b++;
                                        cx[b]=xx;
                                        cy[b]=yy;
                                }
                        }
                }
        }
        return a[xf][yf];
}
int main()
{
        int i,j,q,xi,yi,xf,yf;
        char ch[N+1];
        FILE *fin=fopen("abq.in","rt");
        ofstream fout("abq.out");
        fscanf(fin,"%d%d",&n,&m);
        for (i=1;i<=n;i++)
                { fscanf(fin,"%s",ch);
                    for (j=0;j<strlen(ch);j++) v[i][j+1]=ch[j];
                       }
        fscanf(fin,"%d",&q);
        for (i=1;i<=q;i++)
        {
                fscanf(fin,"%d%d%d%d",&xi,&yi,&xf,&yf);
                if(v[xi][yi]=='b'||v[xf][yf]=='b') fout<<-1<<'\n';
                else if(v[xi][yi]=='a'){int k=lee(xi,yi,xf,yf);
                                     fout<<(k==0?-1:k+1)<<'\n';}
                else fout<<-1<<'\n';
        }
}