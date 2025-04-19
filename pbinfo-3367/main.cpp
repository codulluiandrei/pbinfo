#include <iostream>
#include <fstream>
using namespace std;
int ver(int m)
{
    int s=0;
    while(m!=0){if(m==2) s++;s=s+m; m=m/3;} //cout<<s<<endl;
    return s;
}
int main()
{
    ifstream f("croseta.in");
    ofstream g("croseta.out");
    int n,y;
    f>>n;
    n=n/2;
    int ls=1,ld,ok=0,m;
    ld=n;
    do{m=(ls+ld)/2;
       y=ver(m);
    if(n==y)
    {
        g<<m;ok=1;
    }
    else
        if(y<n)
        ls=m+1;
    else
        ld=m-1;
    }while(ls<=ld && ok==0);
    ////if(ok==0) g<<"bunica a gresit";
    return 0;
}