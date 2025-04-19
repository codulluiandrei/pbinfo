#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double a,b,c,ma,mb,mc;
    int Ma,Mb,Mc;
    cin>>a>>b>>c;
    if(a+b>c && b+c>a && a+c>b)
    {
        ma=sqrt(2*(b*b+c*c)-a*a)/2;
        mb=sqrt(2*(a*a+c*c)-b*b)/2;
        mc=sqrt(2*(a*a+b*b)-c*c)/2;
        Ma=ma*100;
        Mb=mb*100;
        Mc=mc*100;
        cout<<Ma/100<<"."<<Ma/10%10<<Ma%10<<" ";
        cout<<Mb/100<<"."<<Mb/10%10<<Mb%10<<" ";
        cout<<Mc/100<<"."<<Mc/10%10<<Mc%10<<" ";
    }
    else
      	cout<<"Imposibil";
    return 0;
}