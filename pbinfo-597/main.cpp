//problema poza
/*
 *  Determinam cel mai de sus, mai de jos, mai din stanga si mai din dreapta obiect de prim plan si
 * 	afisam elementele dintre acestea
 * 
 * */
#include <iostream>
using namespace std;
int a[1001][1001], n, m;
int main(){
	cin  >> n >> m;
	for (int i = 1 ;i <= n ; ++i)
		for(int j = 1 ; j <= m ; ++j)
			cin >> a[i][j];
	int imin = n+1, imax = 0, jmin = m + 1, jmax = 0;
	for (int i = 1 ;i <= n ; ++i)
		for(int j = 1 ; j <= m ; ++j)
			if(a[i][j] == 1)
			{
				if(i < imin) imin = i;
				if(i > imax) imax = i;
				if(j < jmin) jmin = j;
				if(j > jmax) jmax = j;
			}
	cout << imax - imin + 1  << " " << jmax - jmin + 1 << endl;
	for (int i = imin ;i <= imax ; ++i){
		for(int j = jmin ; j <= jmax ; ++j)
			cout << a[i][j] << " ";
		cout << endl;
	}
	return 0;
}