#include <iostream>
using namespace std;

long long val[15],win[15],n;
char a[15],x,y;

int main(){
    for(char i='A';i<='E';i++){
        a[i-'A']=i;
        val[i-'A']=300;
    }
    for(char i='a';i<='e';i++){
        a[i-'a'+('E'-'A'+1)]=i;
        val[i-'a'+('E'-'A'+1)]=300;
    }
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        ///Cautam valorile
        for(int j=0;j<=9;j++){
            if(a[j]==x){
                x=j;
                break;
            }
        }
        for(int j=0;j<=9;j++){
            if(a[j]==y){
                y=j;
                break;
            }
        }
        ///Castiguri
        win[(int)x]+=val[(int)y];
        ///Balansari
        if(val[(int)x]<=950){
            val[(int)x]+=50;
        }
        if(val[(int)y]>=50){
            val[(int)y]-=50;
        }
    }
    for(int i=0;i<=9;i++){
        cout<<a[i]<<' '<<win[i]<<'\n';
    }
    return 0;
}