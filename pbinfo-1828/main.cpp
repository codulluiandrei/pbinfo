#include <iostream>
#include <cassert>
using namespace std;

void citire(int a[], int &n);
void afisare(int a[], int n);
void inloc(int a[], int n);
int redus(int n);
void sortare(int a[], int n);


int main()
{
	int n , v[1005];
	citire(v , n);
	inloc(v , n);
    sortare(v , n);
	afisare(v , n);
	return 0;
}

void citire(int a[] , int & n)
{
	cin >> n;
	for(int i = 0 ; i < n ; i ++)
    {
		assert(cin >> a[i]);
        assert(a[i] > 1);
    }
}

void afisare(int a[], int n)
{
	for(int i = 0 ; i < n ; i ++)
		cout << a[i] << " ";
}
void inloc(int a[], int n)
{
	for(int i = 0 ; i < n ; i ++)
		a[i] = redus(a[i]);
}
int redus(int n)
{
	int d = 2, r = 1;
    while(n > 1)
    {
        if(n % d ==0)
        {
            r *= d;
            while(n % d == 0)
                n /= d;
        }
        d ++;
        if(d * d > n)
            d = n;
    }
    return r;
}

void sortare(int a[], int n)
{
	for(int i = 0 ; i < n - 1 ; i ++)
        for(int j = i + 1 ; j < n ; j ++)
            if(a[i] < a[j])
            {
                int aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
}
