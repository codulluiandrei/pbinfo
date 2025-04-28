#include <iostream>
using namespace std;
int n,a,x,y,v[1000005],q[1000005];
void generare(int a)
{
	int st = 1 , dr = 1;
	q[1] = a, v[a] =1;
	while(st <= dr)
	{
		int k = q[st];
		if(v[k+x] == 0)
			v[k + x] = 1 , q[++dr ] = k + x;
		if(v[k + y] == 0)
			v[k + y] = 1 , q[++dr ] = k + y;
		st ++;
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