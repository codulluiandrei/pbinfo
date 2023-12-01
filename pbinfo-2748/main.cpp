#include <iostream>
using namespace std;

int main()
{
    long long n,x,y,z,a,b,c;
    cin>>n;
    //calculez numarul de pasi pt fiecare culoar
    x=n*4-4;
    y=(n-2)*4-4;
    z=(n-4)*4-4;
    //calculez cmmdc si cmmmc pt primele 2
    a=x; b=y;
    while(b)
    {
        long long r=a%b;
        a=b;
        b=r;
    }
    c=x*y/a;
    //calculez cmmdc si cmmmc si cu al treilea
    a=c; b=z;
    while(b)
    {
        long long r=a%b;
        a=b;
        b=r;
    }
    c=c*z/a;// => c e nr de pasi pe care trebuie sa il faca fiecare pana la intalnire
    //impart pe c la numarul de pasi de pe fiecare culoar
    cout<<c/x<<" "<<c/y<<" "<<c/z;
    return 0;
}
