#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char v[1001],temp;
    cin>>v;
    int n=strlen(v);
    for(int i=0;i<n;i++){
     for(int j=0;j<n-1;j++){
      if(v[j+1]<v[j]){
       temp=v[j];
       v[j]=v[j+1];
       v[j+1]=temp;
      }
     }
    }
    cout<<v;
    return 0;
}
