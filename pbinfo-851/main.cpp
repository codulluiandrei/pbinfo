#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
ifstream fin("email.in");
ofstream fout("email.out");
int n, frecv[205];
char domenii[205][51];
int main()
{
	char email [51], * p;
	while(fin >> email)
	{
		p = strchr(email , '@') + 1;
		int poz = -1;
		for(int i = 0 ; i < n  && poz == -1 ; i ++)
			if(strcmp(domenii[i] , p) == 0)
				poz = i;
		if(poz == -1)
		{
			strcpy (domenii[n] , p);
			frecv[n] = 1;
			n ++;
		}
		else
			frecv[poz] ++;
	}
	p = email;
	for (int i = 0 ; i < n - 1 ; i ++)
		for(int j = i + 1 ; j < n ; j ++)
			if(frecv[i] < frecv[j])
			{
				int aux = frecv[i]; frecv[i] = frecv[j] ; frecv[j] = aux;
				strcpy(p , domenii[i]); strcpy(domenii[i], domenii[j]); strcpy(domenii[j] , p);
			}
			else
				if(frecv[i] == frecv[j])
					if(strcmp(domenii[i] , domenii[j]) > 0)
					{
						strcpy(p , domenii[i]); strcpy(domenii[i], domenii[j]); strcpy(domenii[j] , p);
					}
	fout << n << "\n";
	for(int i = 0 ; i < n ; i ++)
		fout << domenii[i] << " " << frecv[i] << "\n";
	return 0;
}