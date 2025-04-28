#include <iostream>
using namespace std;
int n,m,q,k,x,y,fx[6],fy[6];
int main()
{
    cin>>n>>m>>k>>q;
    while(k--){
        cin>>x>>y;
        if(fx[x]!=1){fx[0]++;}
        fx[x]=1;
        if(fy[y]!=1){fy[0]++;}
        fy[y]=1;
    }
    ///Numarul de casute neatacate
    int s=n*m-m*fx[0]-n*fy[0]+fx[0]*fy[0];
    ///Imposibil
    if(s<q){
        cout<<"0";
    }
    else {
        ///Aranjamente fara repetitie de s luate cate q
        int p=1;
        for(int i=s-q+1;i<=s;i++){p*=i;}
        cout<<p;
    }
}