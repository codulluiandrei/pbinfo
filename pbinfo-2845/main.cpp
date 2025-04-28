#include <iostream>
#include <cmath>
using namespace std;
int n,m,x,y;
int main(){
 	cin>>x>>y>>n>>m;
 	for(int i=1;i<=n;i++){
  		for(int j=1;j<=m;j++){
   			cout<<1+abs(x-i)+abs(y-j)<<' ';
  		}
  		cout<<'\n';
 	}
 	return 0;
}