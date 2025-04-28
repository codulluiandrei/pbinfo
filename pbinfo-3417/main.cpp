#include <iostream>
using namespace std;
int v[61],lc,n,st,dr;
int main()
{
    cin>>n;
    st=1;
    dr=n;
    for(int i=1;i<=2*n;i++){
        if(i%2==1){
            if(v[i-1]!=st){
                v[++lc]=st;
                st++;
            }
            else{
                st++;
            }
        }
        else{
            if(v[i-1]!=dr){
                v[++lc]=dr;
                dr--;
            }
            else{
                dr--;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<v[i+j-1]<<" ";
        }
        cout<<endl;
    }
    return 0;
}