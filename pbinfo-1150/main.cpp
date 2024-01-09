# include <iostream>
using namespace std;

int n, v[105];

void citire(int &n, int v[])
{
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>v[i];
}

bool prim(int v[], int st, int dr)
{
    if(st == dr)
    {
        if (v[st]%2==0)
            return true;
        else
            return false;
    }
    else
    {
        int mij = (st + dr)/2;
        int R1 = prim(v, st, mij);
        int R2 = prim(v, mij+1, dr);
        if( R1 && R2)
            return true;
        else
            return false;

    }
}

int main()
{
     citire(n, v);
     if(prim(v, 1, n)==1)
        cout<<"DA";
     else
        cout<<"NU";
     return 0;
}