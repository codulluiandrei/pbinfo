#include <iostream>
using namespace std;
unsigned long long dinti(int n)
{
    if(n==1) return 1;
    else return n+2*dinti(n-1);
}
int main()
{
    int n;
    cin>>n;
    cout<<dinti(n);
    return 0;
}