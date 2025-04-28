//Nicu Vlad Laurentiu - Liceul Teoretic "Mihail Kogalniceanu" Vaslui 100 puncte
#include <fstream>
#define N 204
#define INF 10000
#define M 10000
using namespace std;
ifstream cin("lasere.in");
ofstream cout("lasere.out");
struct laser
{
    int x,y,dir;
} X[N];
int A[N][N],n,m, i,j,k, B[M],nr=0,tr,p1,p2,s,cer;
int dx[8]={-1,-1,-1,0,1,1,1,0};
int dy[8]={-1,0,1,1,1,0,-1,-1};
int main()
{
    cin>>cer;
    cin>>n>>m;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++) cin>>A[i][j];
    for(i=0;i<=n+1;i++) A[0][i]=A[i][0]=A[i][n+1]=A[n+1][i]=INF;
    for(k=0; k<m; k++)
    {
        cin>>X[k].x>>X[k].y>>X[k].dir;
        if(X[k].dir==1)for(i=X[k].x-1; i>=1; i--) A[i][X[k].y]--;
        else if(X[k].dir==2)for(i=X[k].y+1; i<=n; i++) A[X[k].x][i]--;
        else if(X[k].dir==3)for(i=X[k].x+1; i<=n; i++) A[i][X[k].y]--;
        else if(X[k].dir==4)for(i=X[k].y-1; i>=1; i--) A[X[k].x][i]--;
    }
     tr=0;
    for(i=1;i<=n;i++)
     {
        for(j=1;j<=n;j++)
        {
            int ok=1;
            for(int l=0;l<8 && ok;l++)
                if(A[i][j]>A[i+dx[l]][j+dy[l]])ok=0;
            if(ok==1){ B[j]=1; nr++;}
        }
        p1=0;
        for(s=1;s<n;)
            if(B[s]==1)
            {
                p1=s;
                while(B[s]) s++;
                if(s-p1>=2)tr++;
            }
            else s++;
         for(s=1;s<=n;s++){ B[s]=0;}
     }
    if(cer==1)cout<<nr<<"\n";
        else cout<<tr<<"\n";
   /* for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++) cout<<A[i][j]<<" ";
        cout<<"\n";
    }*/
}