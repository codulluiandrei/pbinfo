#include <iostream>
#include <cmath>
#define PI 3.141592653589
using namespace std;
int main()
{
    float n,l,apotema,unghi;
    cin>>n>>l;
    unghi=((n-2)*180)/n;
    apotema=tan(unghi/2*PI/180)*(l/2);
    float A=((n*l*apotema)/2);
    A*=100;
    int a=(int)(A);
    cout<<a/100<<"."<<(a/10)%10<<a%10;
    return 0;
}