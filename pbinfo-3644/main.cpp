#include <iostream>
using namespace std;
int main()
{
    long long x, y, a, b, c, d, k=0, p=0, aux;
    cin>>x>>a>>b;
    cin>>y>>c>>d;
    if(a>b)
        aux=a, a=b, b=aux;
    if(c>d)
        aux=c, c=d, d=aux;
    k = b/x - (a-1)/x;
    p = d/y - (c-1)/y;
    if(p<k)
        cout<<"Ioana "<<k<<'\n';
    else if (p>k)cout<<"Maria "<<p<<'\n';
        else cout<<"Egalitate "<<k;
    return 0;
}