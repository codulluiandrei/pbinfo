#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("halfsort1.in");
ofstream fout("halfsort1.out");
void citire(int a[], int &n);
void afisare(int a[], int n);
void sortare(int a[], int st , int dr , int criteriu);
int main()
{
	int n , v[1005];
	citire(v , n);
	sortare(v , 0 , n/2 , 0);
	sortare(v , n/2 , n , 1);
	afisare(v , n);
	return 0;
}
void citire(int a[] , int & n)
{
	fin >> n;
	for(int i = 0 ; i < n ; i ++)
		fin >> a[i];
}
void afisare(int a[], int n)
{
	for(int i = 0 ; i < n ; i ++)
		fout << a[i] << " ";
}
void sortare(int a[], int st , int dr , int criteriu)
{
	//criteriu == 1 -> ordonare descrescatoare
	//criteriu != 1 -> ordonare crescatoare
	int semn  = 1;
	if(criteriu == 1)
		semn = -1;
	for(int i = st ; i < dr -1 ; i ++)
		for(int j = i + 1 ; j < dr ; j ++)
			if(semn * a[i] > semn * a[j])
			{
				int aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
}