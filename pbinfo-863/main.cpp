#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
ifstream fin("parole.in");
ofstream fout("parole.out");
bool cifra(char X)
{
	return X >= '0' && X <= '9';
}
bool litera_mica(char X)
{
	return X >= 'a' && X <= 'z';
}
bool litera_mare(char X)
{
	return X >= 'A' && X <= 'Z';
}
bool caracter(char X)
{
	return strchr(".,?!;:_!#@" , X) != NULL;
}
int main()
{
	int n , cnt = 0;
	char s[51];
	fin >> n;
	fin.getline(s , 51);
	for(int i = 1 ; i <= n ; i ++)
	{
		fin.getline(s , 51);
		bool lungime = strlen(s) >=8 , litmari = false, litmici = false, cifre = false, caractere = false;
		for(int i = 0 ; s[i] ; i ++)
		{
			if ( litera_mare(s[i]) )
				litmari = true;
			if ( litera_mica(s[i]) )
				litmici = true;
			if ( cifra(s[i]) )
				cifre = true;
			if ( caracter(s[i]) )
				caractere = true;
		}
		if(lungime && litmari && litmici && cifre && caractere)
			cnt ++;
	}
	fout << cnt;
	return 0;
}