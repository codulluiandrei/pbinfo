#include <iostream>
#include <fstream>
using namespace std;
void citire(int a[], int &n);
void afisare(int a[], int n);
int palindrom(int x);
void eliminare(int a[], int & n ,int p);
int main()
{
	int n , v[1005];
	citire(v , n);
	for(int i = n - 1 ; i >= 0 ; i --)
		if(palindrom(v[i]))
			eliminare(v , n , i);
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
int palindrom(int x)
{
	int y = x , ogl = 0;
	while(y)
	{
		ogl = 10 * ogl + y % 10;
		y /= 10;
	}
	return ogl == x;
}
void eliminare(int a[], int & n ,int p)
{
	for(int i = p ; i < n - 1 ; i ++)
		a[i] = a[i + 1];
	n --;
}