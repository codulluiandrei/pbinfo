#include <iostream>
using namespace std;
unsigned long long a[2001][2001];
int main(){
 int g,o;
 cin>>g>>o;
 for(int i=0;i<=2000;i++){a[0][i]=1;a[i][0]=1;}
 for(int i=1;i<=2000;i++){
  for(int j=1;j<=2000;j++){
   a[i][j]=a[i-1][j]+a[i][j-1];
  }
 }
 cout<<a[g][o];
 return 0;
}