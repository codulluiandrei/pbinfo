#include <iostream>
using namespace std;
int turnuri(int n)
{
    if(n==1) return 1;
    else return 1+2*turnuri(n-1);
}
int main()
{
    int n;
    cin>>n;
    cout<<turnuri(n);
    return 0;
}