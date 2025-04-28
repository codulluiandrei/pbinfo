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
int col_min(int A[][101], int n, int m)
{///coloana pe care se afla valoarea minima
    int min=10000,jmin=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(A[i][j]<min) { min=A[i][j]; jmin=j; }
    return jmin;
}
int col_max(int A[][101], int n, int m)
{///coloana pe care se afla valoarea maxima
    int max=0,jmax=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(A[i][j]>max) { max=A[i][j]; jmax=j; }
    return jmax;
}
void interschimbare(int A[][101], int n, int x, int y)
{///interschimba linia x cu linia y
    for(int i=1;i<=n;i++) swap(A[i][x],A[i][y]);
}
int main()
{
    int A[101][101],n,m,x,y;
    citire(A,n,m);
    x=col_min(A,n,m);
    y=col_max(A,n,m);
    interschimbare(A,n,x,y);
    afisare(A,n,m);
    return 0;
}