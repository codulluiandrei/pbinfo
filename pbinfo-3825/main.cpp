#include <iostream>
#include <cmath>
#define PI 3.141592653589
using namespace std;
int main()
{
    double n,a,radius;
    cin>>n>>a;
    radius=a/(2*sin(PI*1/n));/// (2*sin(180/n));
    int R=radius*100;
    cout<<R/100<<"."<<R/10%10<<R%10;
    return 0;
}