#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
double fct(double x){
    return sin(x)+sin(2*x)+ x;
}
double cb(double x,double st,double dr){
    double mij=(st+dr)/2.;
    if(dr-st<0.00000001) return mij;
    if (fct(mij)<x) return cb(x,mij,dr );
    return cb(x,st,mij);
}
int main()
{
    double a;
    cin >> a;
    double x = cb(a,0,1);
    cout << std::fixed << std::setprecision(8) << x << endl;
    return 0;
}