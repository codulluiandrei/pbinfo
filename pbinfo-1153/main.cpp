# include <iostream>
using namespace std;
int n, v[105];
void citire(int &n, int v[])
{
    cin>>n;
    for(int i = 1; i <= n ; i++)
        cin>>v[i];
}
int nrcif( int st, int dr, int v[])
{
    if(st == dr)
    {
        int cnt = 1;
        while( v[st] > 9)
            v[st] /= 10, cnt++;
        if(cnt%2 == 0)
            return 1;
        else
            return 0;
    }
    else
    {
        int m = (st+dr)/2;
        int R1 = nrcif(st, m, v);
        int R2 = nrcif(m+1, dr, v);
        if( R1 && R2)
            return 1;
        else
            return 0;
    }
}
int main()
{
    citire(n, v);
    if(nrcif(1, n, v))
        cout<<"DA";
    else
        cout<<"NU";
    return 0;
}