//problema fast-food1
/*
 *  Folosim un vector de frecventa, in care care marcam pentru fiecare moment de timp, 
 *  numarul de persoane din restaurant.
 * 
 * */
#include <iostream>
using namespace std;
int v[10005], n, x, y;
int main(){
	cin  >> n;
	int hmax = 0, hmin = 10005;
	for(int i = 0 ; i < n ; ++i){
		cin >> x >> y;
		if(x < hmin)
			hmin = x;
		if(y > hmax)
			hmax = y;
		for(int j = x ; j <= y ; j ++)
			v[j] ++;
	}
	//for(int i = hmin; i <= hmax; i++)
	//	cout << v[i] << " ";
	//cout << endl;
	int max = v[hmin];
	for(int i = hmin; i <= hmax; i++)
		if(max < v[i])
			max = v[i];
	cout << max;
	return 0;
}