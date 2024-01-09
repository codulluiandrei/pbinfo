# include <iostream>
using namespace std;

int n, v[205];

void citire(int &n, int v[])
{
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>v[i];
}

int prim(int v[], int st, int dr)
{
    if(st == dr)
    {
        if(v[st]<2)
            return 0;
        if (v[st]>2 && v[st]%2==0)
            return 0;
        for (int d=3; d*d<=v[st]; d+=2)
            if (v[st]%d==0)
                return 0;
        return 1;
    }
    else
    {
        int mij = (st + dr)/2;
        int R1 = prim(v, st, mij);
        int R2 = prim(v, mij+1, dr);
        if( R1 || R2 )
            return 1;
        else
            return 0;

    }
}

int main()
{
     citire(n, v);
     if(prim(v, 1, n))
        cout<<"DA";
     else
        cout<<"NU";
     return 0;
}
