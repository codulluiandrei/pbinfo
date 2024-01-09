# include <iostream>
using namespace std;

int n, v[105];

void citire(int &n, int v[])
{
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>v[i];
}

int impar(int v[], int st, int dr)
{
    if(st == dr)
    {
        if(v[st] %2 == 0)
            return 0;
        else
            return 1;
    }
    else
    {
        int mij = (st + dr)/2;
        int R1 = impar(v, st, mij);
        int R2 = impar(v, mij+1, dr);
        if( R1 || R2 )
            return 1;
        else
            return 0;

    }
}

int main()
{
     citire(n, v);
     if(impar(v, 1, n))
        cout<<"DA";
     else
        cout<<"NU";
     return 0;
}
