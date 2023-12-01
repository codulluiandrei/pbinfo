#include <fstream>
using namespace std;

ifstream f("ecuatie2.in");
ofstream g("ecuatie2.out");

int main()
{
    int a=0,b, x, tip;
    char op, c;
    f>>c;
    if(c=='x')  /// x op a = b
    {
        f>>op>>a>>c>>b;
        if(op=='+')
        {
            x=b-a;
            tip=2;
        }
        else if(op=='-')
        {
            x=b+a;
            tip=4;
        }
        else if(op=='*')
        {
            x=b/a;
            tip=6;
        }
        else
        {
            x=b*a;
            tip=8;
        }

    }
    else  /// a op x = b
    {
        while(isdigit(c))
        {
            a=a*10+c-'0';
            f>>c;
        }
        op=c;
        f>>c>>c;
        f>>b;
        if(op=='+')
        {
            x=b-a;
            tip=1;
        }
        else if(op=='-')
        {
            x=a-b;
            tip=3;
        }
        else if(op=='*')
        {
            x=b/a;
            tip=5;
        }
        else
        {
            x=a/b;
            tip=7;
        }
    }
    g<<tip<<endl<<x<<endl;
    return 0;
}
