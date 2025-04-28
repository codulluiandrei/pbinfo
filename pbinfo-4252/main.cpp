#include <iostream>
using namespace std;
void citire(int A[][101], int &n, int &m)
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) cin>>A[i][j];
}
void afisare(int A[][101], int n, int m)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) cout<<A[i][j]<<" ";
        cout<<endl;
    }
}
int lin_min(int A[][101], int n, int m)
{///linia pe care se afla valoarea minima
    int min=10000,imin=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(A[i][j]<min) { min=A[i][j]; imin=i; }
    return imin;
}
int lin_max(int A[][101], int n, int m)
{///linia pe care se afla valoarea maxima
    int max=0,imax=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(A[i][j]>max) { max=A[i][j]; imax=i; }
    return imax;
}
void interschimbare(int A[][101], int m, int x, int y)
{///interschimba linia x cu linia y
    for(int j=1;j<=m;j++) swap(A[x][j],A[y][j]);
}
int main()
{
    int A[101][101],n,m,x,y;
    citire(A,n,m);
    x=lin_min(A,n,m);
    y=lin_max(A,n,m);
    interschimbare(A,m,x,y);
    afisare(A,n,m);
    return 0;
}