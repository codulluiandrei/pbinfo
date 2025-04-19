#include <iostream>
using namespace std;
void citire(int a[], int &n);
void afisare(int a[], int n);
void inloc(int a[], int n);
int prim(int n);
int urmatorul_prim(int n);
int main()
{
	int n , v[1005];
	citire(v , n);
	inloc(v , n);
	afisare(v , n);
	return 0;
}
void citire(int a[] , int & n)
{
	cin >> n;
	for(int i = 0 ; i < n ; i ++)
		cin >> a[i];
}
void afisare(int a[], int n)
{
	for(int i = 0 ; i < n ; i ++)
		cout << a[i] << " ";
}
void inloc(int a[], int n)
{
	for(int i = 0 ; i < n ; i ++)
		if(! prim(a[i]))
			a[i] = urmatorul_prim(a[i]);
}
int prim(int n)
{
	if(n < 2)
		return 0;
	if(n == 2)
		return 1;
	if(n % 2 == 0)
		return 0;
	for(int d = 3 ; d * d <= n ; d += 2)
		if(n % d == 0)
			return 0;
	return 1;
}
int urmatorul_prim(int n){
	while(! prim(n))
		n ++;
	return n;
}