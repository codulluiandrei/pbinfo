#include <iostream>
using namespace std;

int A[515][515],n;

void pattern(int A[][515],int n,int sus,int jos,int st,int dr)
{
    if(n>=1)
    {
        int mi=(sus+jos)/2;
        int mj=(st+dr)/2;
        A[mi][mj]=n;
        pattern(A,n-1,sus,mi-1,st,mj-1);//NV
        pattern(A,n-1,sus,mi-1,mj+1,dr);//NE
        pattern(A,n-1,mi+1,jos,st,mj-1);//SV
        pattern(A,n-1,mi+1,jos,mj+1,dr);//SE
    }
}

void afisare(int A[][515],int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
}

int xlan(int x, int n)
{
    if(n==0) return 1;
    else
    {
        int p=xlan(x,n/2);
        if(n%2==0) return p*p;
        else return p*p*x;
    }
}

int main()
{
    int n,m;
    cin>>n;
    m=xlan(2,n)-1;
    pattern(A,n,1,m,1,m);
    afisare(A,m);
    return 0;
}
