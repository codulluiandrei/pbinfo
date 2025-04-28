#include <iostream>
using namespace std;
int main()
{
    int c, np=0, ni=0,cer;
    unsigned long long n;
    cin>>cer>>n;
    if(n==0) np++;
    while(n)
    {
      c=n%10;
      if(n%2==1) ni++;
      else np++;
      n/=10;
    }
    if(cer==1) cout<<ni;
    else cout<<np;
    return 0;
}