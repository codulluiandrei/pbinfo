//problema succes
/*
 *  Vom determina pentru fiecare zi de cumparare i ziua j (j>i) in care vanzarea se va face la pretul maxim, si vom determina maximul posibil
 *  Daca pentru nici o pereche i j suma existenta nu creste, ea va ramane aceeasi
 * 
 * */

#include <iostream>
using namespace std;

int v[1005], n, S;

int main(){
	cin  >> n >> S;
	for(int i = 0 ; i < n ; ++i)
		cin >> v[i];
	int smax = S;
	for(int i = 0 ; i < n ; ++i)
	{
		int pmax = i + 1;
		for(int j = i + 1; j < n ; ++j)
			if(v[j] > v[pmax])
				pmax = j;
		int cnt = S/v[i];
		int sc = S % v[i] + cnt * v[pmax];
		if(sc > smax)
			smax = sc;
	}
	cout << smax << "
";
	return 0;
}
