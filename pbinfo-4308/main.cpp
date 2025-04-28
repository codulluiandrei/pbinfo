#include <iostream>
using namespace std;
int paianjen(int n, int m)
{
    if(n==1 || m==1) return 1;
    else return paianjen(n-1,m)+paianjen(n,m-1);
}
int main()
{
    int n,m;
    cin>>n>>m;
    cout<<paianjen(n,m);
    return 0;
}