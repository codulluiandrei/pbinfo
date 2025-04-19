#include <iostream>
#include <cmath>
#define PI 3.141592653589
using namespace std;
int main()
{
    double a,b,c,u,alfa;
    cin>>a>>b>>u;
    alfa=180-u;
    c=sqrt(pow((a+b*cos(alfa*PI/180)),2)+pow((b*sin(alfa*PI/180)),2));
    int C=c*100;
    cout<<C/100<<"."<<(C/10)%10<<C%10;
    return 0;
}