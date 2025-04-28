#include <fstream>
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
ifstream fin("cuvinte3.in");
ofstream fout("cuvinte3.out");
int n;
char lista[505][256];
void to_lower(char * p)
{
	for(int i = 0 ; p[i] ; i++)
		p[i] = tolower(p[i]);
}
bool OK(char * p)
{
	char t[256];
	strcpy(t , p);
	to_lower(t);
	if( strstr(t , "ate") )
		return true;
	return false;
}
bool egale(char * s , char * t)
{
	char ss[256], tt[256];
	strcpy(ss , s);
	strcpy(tt , t);
	to_lower(ss); to_lower(tt);
	if(strcmp(ss , tt) == 0)
		return true;
	return false;
}
int main()
{
	char linie[256], sep[]=".,;:-?! ";
	while( fin.getline(linie , 256) )
	{
		char * p = strtok(linie , sep);
		while(p)
		{
			if(OK(p))
			{
				bool gasit = false;
				for(int i = 1 ; i <= n && ! gasit ; i++)
					if( egale(p , lista[i]) )
						gasit = true;
				if(! gasit)
				{
					n ++;
					strcpy(lista[n] , p);
				}
			}
			p = strtok( NULL , sep);
		}
	}
	for(int i = 1 ; i <= n ; i ++)
		fout << lista[i] << "\n";
	return 0;	
}