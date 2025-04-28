#include <cstdio>
#include <vector>
#define N 1<<16
#define I(x,y) (x<<8)|y
#define Afis(x) printf("%d %d\n",x>>8,x&255)
using namespace std;
int n,m,i,j,X,Y,vulpe=-1,capat=-2,baza,top,vulpi[N],capete[N],Lee[N],Q[N],k,p,e,
D[5]={-256,256,-1,1,0},*d,x[1001],y[1001],used[1001],cx,cy,lg,caz;
vector<int> v[N];
void fill(int,int),DF(int);
int main()
{
    freopen("cartite.in","r",stdin);
    freopen("cartite.out","w",stdout);
    scanf("%d",&caz);
    scanf("%d%d",&n,&m);m++;n++;
    scanf("%d%d",&i,&j);X=I(i,j);
    for(j=0;j<=m;j++)vulpi[I(0,j)]=vulpi[I(n,j)]=1;
    for(i=0;i<=n;i++)vulpi[I(i,0)]=vulpi[I(i,m)]=1;
    scanf("%d",&k);
    for(;k;k--){scanf("%d%d%d",&i,&j,&p);fill(I(i,j),p);}
    scanf("%d",&e);
    for(k=1;k<=e;k++)
    {
        scanf("%d%d",&i,&j);
        x[k]=I(i,j);v[x[k]].push_back(k);
        scanf("%d%d",&i,&j);
        y[k]=I(i,j);v[y[k]].push_back(k);
        capete[x[k]]=capete[y[k]]=1;
    }
    Q[1]=X;top=1;Lee[X]=1;
    for(baza=1;baza<=top;baza++)
    {
        i=Q[baza];
        for(d=D;*d;d++)
        {
            if(vulpi[i+*d])continue;
            if(Lee[i+*d])continue;
            Lee[i+*d]=Lee[i]+1;
            Q[++top]=i+*d;
            if(capete[i+*d])break;
        }
        if(capete[i+*d])
        {
            cx=(i+*d)>>8;
            cy=(i+*d)&255;
            lg=Lee[i+*d]-1;
            break;
        }
    }
    if(caz==1)
    {
        printf("%d %d %d\n",cx,cy,lg);
        return 0;
    }
    for(i=1;i<=e;i++)
    {
        if(!vulpi[x[i]]){DF(x[i]);break;}
        if(!vulpi[y[i]]){DF(x[i]);break;}
    }
    return 0;
}
void DF(int nod)
{
    for(;v[nod].size();)
    {
        int edge=v[nod].back();
        if(used[edge]){v[nod].pop_back();continue;}
        used[edge]=1;
        DF(x[edge]+y[edge]-nod);
    }
    Afis(nod);
}
void fill(int x,int y)
{
    int *q;
    if(x<0||y<0)return;
    if(vulpi[x])return;
    vulpi[x]=1;
    for(q=D;*q;q++)fill(x+*q,y-1);
}