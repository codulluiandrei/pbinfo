#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("baze1.in");
ofstream fout("baze1.out");
int to_dec(char * s , int b)
{
	int x = 0;
	for(int i = 0 ; s[i] ; i ++)
		x = b * x + s[i] - '0';
	return x;
}
int main()
{
	int b1 ,b2;
	char s[40], t[40];
	fin >> b1 >> b2 >> s >> t;
	fout << to_dec(s , b1) + to_dec(t , b2);
	return 0;
}