#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
ifstream fin("rime.in");
ofstream fout("rime.out");
int n, v[505];
char s[505][21];
bool rimeaza(char * s , char * t)
{
	int nrv = 1;
	if(strchr("aeiou" , s[strlen( s ) - 1]))
		nrv = 2;
	int i = strlen(s) - 1, j = strlen(t) - 1;
	while(nrv)
		if(s[i]!=t[j])
			return false;
		else{
			if(strchr("aeiou", s[i]))
				nrv --;
			i-- , j --;
		}
	return true;
}
int main()
{
	int m = 0;
	char linie[256];
	char * p;
	fin >> n;
	fin.getline(linie , 256);
	while(fin.getline(linie , 256))
	{
		p = strtok( linie , " ;,");
		while(p)
		{
			strcpy(s[m] , p);
			m ++;
			p = strtok(NULL, " ;,");
		}
	}
	char t[21];
	for (int i = 0 ; i < n - 1 ; i ++)
		for(int j = i + 1 ; j < n ; j ++)
			if(strcmp(s[i] , s[j]) > 0)
			{
				strcpy(t , s[i]); strcpy(s[i], s[j]); strcpy(s[j] , t);
			}
	int c = 0;
	for(int i = 0 ; i < n ; i ++)
		if(v[i] == 0)
		{
			c ++;
			v[i] = c;
			for(int j = i + 1; j < n ; j ++)
				if(rimeaza(s[i] , s[j]))
					v[j] = c;
		}
	fout << c << "\n";
	for(int i = 1 ; i <= c ; i ++)
	{
		for(int j = 0 ; j < n ; j ++)
			if(v[j] == i)
				fout << s[j] << " ";
		fout << "\n";
	}
	return 0;
}