#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("paranteze2.in");
ofstream fout("paranteze2.out");

int n;
char s[256];

int main()
{
	fin >> s;
	int ok = 1;
	int nivel = 0 , niv_max = 0;
	for(int i = 0 ; s[i] && ok ; i ++)
		if(s[i] == '(')
		{
			nivel ++;
			if(nivel > niv_max)
				niv_max = nivel;
		}
		else
			if(nivel > 0)
				nivel --;
			else
				ok = 0;
	if(nivel > 0)
			ok = 0;
	if(!ok)
		cerr << "Incorect";
	else
		fout << niv_max;
	
	return 0;
}
