#include<iostream>
using namespace std;
const int di[]={-1,1,0,0};
const int dj[]={0,0,-1,1};
int A[12][12],c,n,m,x,y,p;
int inside(int i,int j)
{
   return i>=1 && i<=n && j>=1 && j<=m;
}
void back(int i, int j, int k)
{
    A[i][j]--;
    if(k==p) c++;
    else for(int d=0;d<4;d++)
    {
        int iv=i+di[d];
	    int jv=j+dj[d];
	    if(inside(iv,jv) && A[iv][jv]>0)
		   back(iv,jv,k+1);
    }
    A[i][j]++;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
	    for(int j=1;j<=m;j++)
        {
            cin>>A[i][j];
			p=p+A[i][j];
		}
   cin>>x>>y;
   back(x,y,1);
   if(c==0) cout<<"Mr. Anderson wins!";
   else cout<<c;
   return 0;
}