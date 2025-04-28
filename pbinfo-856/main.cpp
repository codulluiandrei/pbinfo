#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
ifstream fin("valori.in");
ofstream fout("valori.out");
int valori[26];
int valoare_litera(char X)
{
	if(X>='a' && X <= 'z')
		return valori[X-'a'];
	if(X>='A' && X <= 'Z')
		return -valori[X-'A'];
	return 0;
}
int valoare_cuvant(char * X)
{
	int S = 0;
	for(int i = 0 ; X[i] ; i ++)
		S += valoare_litera(X[i]);
	return S;
}
int main()
{
	for(int i = 0 ; i < 26 ; i ++)
		fin >> valori[i];
	int n , nrt , vmax = -2000000000; ;
	char s[256] , t[1000][256];
	fin >> n;
	for(int i = 1 ; i <=  n ; i ++)
	{
		fin >> s;
		int val_curenta = valoare_cuvant(s);
		cout << s << " " << val_curenta << endl;
		if(val_curenta > vmax)
		{
			vmax = val_curenta;
			nrt = 1;
			strcpy(t[0] , s);
		}
		else
			if(val_curenta == vmax)
			{
				strcpy(t[nrt] , s);
				nrt ++;
			}
	}
	for(int i = 0 ; i < nrt ; i ++)
		fout << t[i] << "\n";
	return 0;
}