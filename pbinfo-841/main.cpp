#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("bomber.in");
ofstream fout("bomber.out");
int n , m , v[105] , x[105] , y[105] , p[105] , start;
void explozie(int k)
{
	v[k] = 1;
	for(int i = 1 ; i <= n ; i ++)
		if(v[i] == 0 && (x[i] - x[k])*(x[i] - x[k]) + (y[i] - y[k])*(y[i] - y[k]) <= p[k] * p[k] )
			explozie(i);
}
int main(){
	fin >> n >> start;
	for(int i = 1 ; i <= n ; i ++)
			fin >> x[i] >> y[i] >> p[i];
	fin.close();
	explozie(start);
	int cnt = 0;
	for( int i = 1; i <= n ; i ++)
		if(v[i] == 0)
			cnt ++;
	fout << cnt;
	fout.close();
	return 0;
}