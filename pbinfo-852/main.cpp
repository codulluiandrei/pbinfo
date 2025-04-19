#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("paranteze3.in");
ofstream fout("paranteze3.out");
int n;
char s[256];
char stiva[256];
int main()
{
	fin >> n;
	for(int k = 1 ; k <= n ; k ++)
	{
		fin >> s;
		int ok = 1;
		int nivel = 0;
		for(int i = 0 ; s[i] && ok ; i ++)
			if(s[i] == '(')
				stiva[++nivel]='(';
			else
				if(s[i] == '[')
					stiva[++nivel]='[';
				else
					if(nivel > 0)
					{
						if(s[i] == ')')
							if(stiva[nivel] == '(')
								nivel --;
							else
								ok = 0;
						else
							if(stiva[nivel] == '[')
								nivel --;
							else
								ok = 0;
					}
					else
						ok = 0;
		if(nivel > 0)
			ok = 0;
		fout << ok << "\n";
	}
}