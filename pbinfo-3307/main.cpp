#include <iostream>
using namespace std;
int main()
{
    int n,a,b;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        int ca=a,cb=b,rest;
        while(cb!=0)
        {
            rest=ca%cb;
            ca=cb;
            cb=rest;
        }
        a=a/ca;
        b=b/ca;
        int cnt2=0,cnt5=0;
        while(b%2==0)
        {
            cnt2++;
            b/=2;
        }
        while(b%5==0)
        {
            cnt5++;
            b/=5;
        }
        if(b==1)
            cout<<"fractie finita"<<'\n';
        else
        {
            if(cnt2+cnt5==0)
                cout<<"fractie periodica simpla"<<'\n';
            else
                cout<<"fractie periodica mixta"<<'\n';
        }
    }
    return 0;
}