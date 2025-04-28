#include <iostream>
#include <cstring>
using namespace std;
char s[2560];
char v[100][16] , * t;
int f[100] , x[100] , n;
int main()
{
	cin.getline(s , 2560);
	t = strtok(s , " ");
	while(t)
	{
		int poz = -1;
		for(int i = 0 ; i < n && poz == -1 ; i ++)
			if(strcmp(t , v[i]) == 0)
				poz = i;
		if(poz == -1)
		{
			strcpy(v[n] , t);
			f[n] = 1;
			x[n] = n;
			n ++;
		}
		else
			f[poz] ++;
		t = strtok(NULL , " ");
	}
	for(int i = 0 ; i < n ; i ++)
		for(int j = i + 1 ; j < n ; j ++)
			if(strcmp(v[x[i]] , v[x[j]]) > 0)
			{
				int aux = x[i] ;
				x[i]  =x[j];
				x[j] = aux;
			}
	for(int i = 0 ; i < n ; i ++)
		cout << v[x[i]] << " " << f[x[i]] << "\n";
	return 0;
}