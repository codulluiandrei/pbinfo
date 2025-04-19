#include <iostream>
#include <cmath>
#define PI 3.141592653589
using namespace std;
int main()
{
    double AB,BC,AC,u1,u2,u3;
    cin>>AB>>BC>>AC;
    if(AB+BC>AC && AB+AC>BC && BC+AC>AB)
    {
        u1=acos((AC*AC+AB*AB-BC*BC)/(2*AC*AB));
        u2=acos((AB*AB+BC*BC-AC*AC)/(2*AB*BC));
        u3=acos((AC*AC+BC*BC-AB*AB)/(2*BC*AC));
        int U1=(u1*180/PI)*100,U2=(u2*180/PI)*100,U3=(u3*180/PI)*100;
        cout<<U1/100<<"."<<U1/10%10<<U1%10<<" ";
        cout<<U2/100<<"."<<U2/10%10<<U2%10<<" ";
        cout<<U3/100<<"."<<U3/10%10<<U3%10;
    }
    else
        cout<<"Imposibil";
    return 0;
}