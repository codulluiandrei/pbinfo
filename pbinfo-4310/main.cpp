#include <iostream>
using namespace std;
void cifre(int n, int &i, int &p)
{
    if(n<10)
        if(n%2==0) { p=1; i=0; }
        else { i=1; p=0; }
    else
    {
        cifre(n/10,i,p);
        if(n%2==0) p++;
        else i++;
    }
}
int suma(int a, int b)
{
    if(a>b) return 0;
    else
    {
        int i,p;
        cifre(a,i,p);
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