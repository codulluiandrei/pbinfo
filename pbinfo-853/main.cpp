#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
ifstream fin("cadouri.in");
ofstream fout("cadouri.out");
int n, cantitate[505];
char denumire[505][21];
bool cifra(char X)
{
	return X >= '0' && X <= '9';
}
bool litera_mica(char X)
{
	return X >= 'a' && X <= 'z';
}
int main()
{
	int m;
	char email[256];
	char p[21];
	fin >> m;
	fin.getline(email , 256);
	for( ; m ; m --)
	{
		fin.getline(email , 256);
		int lg = strlen(email); //vom distruge sirul
		for(int i = 0 ; i < lg ; i ++)
			if( cifra( email[i]) )
			{
				int cnt = 0;
				while(cifra(email[i]))
				{
					cnt = 10 * cnt + email[i] - '0';
					i ++;
				}
				while(email[i] == ' ')
					i ++;
				int j = i;
				while(litera_mica(email[i]))
					i ++;
				email[i] = 0;
				strcpy(p , email + j);
				int poz = -1;
				for(int i = 0 ; i < n && poz == -1 ; i ++)
					if(strcmp(denumire[i] , p) == 0)
						poz = i;
				if(poz != -1)
					cantitate[poz] += cnt;
				else
				{
					strcpy(denumire[n] , p);
					cantitate[n] = cnt;
					n ++;
				}
			}
	}
	for (int i = 0 ; i < n - 1 ; i ++)
		for(int j = i + 1 ; j < n ; j ++)
			if(cantitate[i] < cantitate[j])
			{
				int aux = cantitate[i]; cantitate[i] = cantitate[j] ; cantitate[j] = aux;
				strcpy(p , denumire[i]); strcpy(denumire[i], denumire[j]); strcpy(denumire[j] , p);
			}
			else
				if(cantitate[i] == cantitate[j])
					if(strcmp(denumire[i] , denumire[j]) > 0)
					{
						strcpy(p , denumire[i]); strcpy(denumire[i], denumire[j]); strcpy(denumire[j] , p);
					}
	fout << n << "\n";
	for(int i = 0 ; i < n ; i ++)
		fout << denumire[i] << " " << cantitate[i] << "\n";
	return 0;
}