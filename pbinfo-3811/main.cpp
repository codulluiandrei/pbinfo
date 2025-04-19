#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double a,b,c,p;
    cin>>a>>b>>c;
    if(a+b>=c && b+c>=a && a+c>=b)
    {
        p=(a+b+c)/2;
        double bA=sqrt((4*b*c)/((b+c)*(b+c))*p*(p-a)),bB=sqrt((4*a*c)/((a+c)*(a+c))*p*(p-b)),bC=sqrt((4*a*b)/((a+b)*(a+b))*p*(p-c));
        int b1=bA*100,b2=bB*100,b3=bC*100;
        cout<<b1/100<<"."<<b1/10%10<<b1%10<<" ";
        cout<<b2/100<<"."<<b2/10%10<<b2%10<<" ";
        cout<<b3/100<<"."<<b3/10%10<<b3%10<<" ";
    }
    else
        cout<<"Imposibil";
    return 0;
}