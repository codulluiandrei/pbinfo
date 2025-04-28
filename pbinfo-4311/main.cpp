#include <iostream>
using namespace std;
void sume(int n, int &i, int &p)
{
    if(n<10)
        if(n%2==0) { p=n; i=0; }
        else { i=n; p=0; }
    else
    {
        sume(n/10,i,p);
        if(n%2==0) p=p+n%10;
        else i=i+n%10;
    }
}
int suma(int a, int b)
{
    if(a>b) return 0;
    else
    {
        int i,p;
        sume(a,i,p);
        if(i==p) return suma(a+1,b)+a;
        else return suma(a+1,b);
    }
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<suma(a,b);
    return 0;
}