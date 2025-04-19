#include <iostream>
using namespace std;
int n,a,x,y,v[10005];
void generare(int a)
{
	if(a<=n)
		if(v[a] == 0)
		{
			v[a] = 1;
			generare(a+x);
			generare(a+y);
		}
}
int main(){
	cin >> n >> a >> x >> y;
	generare(a);
	for(int i = 0 ; i <= n ; i ++)
		if(v[i] == 1)
			cout << i << " ";
	return 0;
}