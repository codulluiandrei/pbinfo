#include <iostream>
using namespace std;
int v[1000001],a[1000001];
int main()
{
    int i,n,x,y,z;
    cin>>n;
    v[1]=0;
    v[2]=1;
    v[3]=1;
    for(i=4;i<=n;i++)
    {
     x=v[i-1];a[i]=i-1;
     if(i%2==0){y=v[i/2];
                if(y<x){a[i]=i/2;x=y;}
     }
     if(i%3==0){z=v[i/3];
                if(z<x){a[i]=i/3; x=z;}
     }
     v[i]=x+1;
    }
    cout<<v[n]<<endl;
    return 0;
}