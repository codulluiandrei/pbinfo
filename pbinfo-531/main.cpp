#include <iostream>
using namespace std;
int pct[55], concurenti[1005], n ,m;
double medii[1005];
int main(){
	cin  >> n >> m;	
	for(int i = 1 ; i <= n ; ++i)
	{
		for(int j = 1 ; j <= m ; ++j)
			cin >> pct[j];
		int Min = pct[1], Max = pct[1];
		for(int j = 1 ; j <= m ; ++j)
		{
			if(pct[j] < Min)
				Min = pct[j];
			if(pct[j] > Max)
				Max = pct[j];
		}
		int S = 0, cnt = 0;
		for(int j = 1 ; j <= m ; ++j)
			if(pct[j] > Min && pct[j] < Max)
				S += pct[j], cnt ++;
		medii[i] = 1.0 * S / cnt;
		concurenti[i] = i;
	}
	for(int i =1 ; i < n ;++i)
		for(int j = i+1 ; j <=n ; ++j)
			if(medii[i] < medii[j])
			{
				int aux = concurenti[i];
				concurenti[i] = concurenti[j];
				concurenti[j] = aux;
				double auxd = medii[i];
				medii[i] = medii[j];
				medii[j] = auxd;
			}
			else
				if(medii[i] == medii[j])
					if(concurenti[i] > concurenti[j])
					{
						int aux = concurenti[i];
						concurenti[i] = concurenti[j];
						concurenti[j] = aux;
					}
	for(int i = 1; i <= n ; ++i)
		cout << concurenti[i] << " ";
	return 0;
}