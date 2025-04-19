#include <iostream>
using namespace std;
int n , p , a[1050][1050];
void pattern (int i1 , int j1 , int i2 , int j2)
{
	if(i1 < i2)
	{
		int im = (i1 + i2) / 2 , jm = (j1 + j2) / 2;
		for(int i = i1 ; i <= im ; i ++)
			for(int j = j1 ; j <= jm ; j ++)
				a[i][j] = 1;
		pattern(i1 , jm + 1 , im , j2);
		pattern(im + 1 , j1 , i2 , jm);
		pattern(im + 1 , jm + 1 , i2 , j2);
	}
}
int main(){
	cin >> n;
	p = 1;
	for(int i = 1 ; i <= n ; i ++)
		p *= 2;
	pattern(1 , 1 , p , p);
	for(int i = 1 ; i <= p ; i ++)
	{
		for(int j = 1; j <= p ; j ++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	return 0;
}