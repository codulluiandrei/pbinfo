#include <iostream>
using namespace std;
int di[]={-1,-1,1,1};
int dj[]={-1,1,1,-1};
int n,m,A[12][12],B[12][12],x,y,z,c;
int ok(int i, int j)
{
    if(i<1 || i>n || j<1 || j>m) return 0;
    if(A[i][j]%2==1) return 0;
    if(B[i][j]!=0) return 0;
    return 1;
}
void back(int i, int j, int k)
{
    B[i][j]=k;
    if(k==z) c++;
    else
        for(int d=0;d<4;d++)
        {
            int iv=i+di[d], jv=j+dj[d];
            if(ok(iv,jv)) back(iv,jv,k+1);
        }
    B[i][j]=0;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>A[i][j];
    cin>>x>>y>>z;
    back(x,y,1);
    if(c==0) cout<<"Mr. Anderson wins!";
    else cout<<c;
    return 0;
}