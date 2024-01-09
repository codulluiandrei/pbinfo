# include <iostream>
using namespace std;

int n, v[505];

void citire(int &n, int v[])
{
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>v[i];
}

int prim(int v[], int st, int dr)
{
    if(st == dr)
        return 1;
    else
    {
        int mij = (st + dr)/2;
        int R1 = prim(v, st, mij);
        int R2 = prim(v, mij+1, dr);
        if( R1==R2 && R1 == 1 && v[st] == v[dr])
            return 1;
        else
            return 0;

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
