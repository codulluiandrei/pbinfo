#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("harta3.in");
ofstream fout("harta3.out");
struct Muchie{
	int i, j;
	double cost;
};
int n , m , x[101], y[101], P[101];
Muchie M[5000];
int main()
{
    fin >> n;
    for(int i = 1 ; i <= n ; i ++)
		fin >> x[i] >> y[i];
	for(int i = 1 ; i < n ; i ++)
		for(int j = i + 1 ; j <= n ; j ++)
		{
			m ++;
			M[m].i = i, M[m].j = j, M[m].cost = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
		}
	for(int i = 1 ; i <= m ; i ++)
		for(int j = i + 1 ; j <= m ; j ++)
			if(M[i].cost > M[j].cost)
				swap(M[i] , M[j]);
	for(int i = 1 ; i <= n ; i ++)
		P[i] = i;
	double S = 0;
	for(int i = 1 ; i <= m ; i ++)
		if(P[M[i].i] != P[M[i].j])
		{
			cout << M[i].i << " " << M[i].j << " " << M[i].cost << endl;
			S += M[i].cost;
			int ai = P[M[i].i];
			int aj = P[M[i].j];
			for(int i = 1; i <= n ; i ++)
				if(P[i] == aj)
					P[i] = ai;
		}
	fout << setprecision(4) << fixed << S << endl;
    return 0;
}