#include <iostream>
using namespace std;
int di[]={-1,-1,1,1};
int dj[]={-1,1,1,-1};
int n,A[12][12],c,lmax;
int inside(int i, int j)
{
    return i>=1 && i<=n && j>=1 && j<=n;
}
void back(int i, int j, int k)
{
    A[i][j]=k;
    if(i==n && j==n) { c++; if(k>lmax) lmax=k; }
    else
        for(int d=0;d<=3;d++)
        {
            int iv=i+di[d], jv=j+dj[d];
            if(inside(iv,jv) && A[iv][jv]==0) back(iv,jv,k+1);
        }
    A[i][j]=0;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>A[i][j];
    back(1,1,1);
    if(c==0) cout<<"Dorel :((";
    else cout<<c<<endl<<lmax;
    return 0;
}