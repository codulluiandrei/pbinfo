#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;
ifstream fin("concert.in");
ofstream fout("concert.out");
int n,T, v[105] , x[105];
int main(){
	fin >> n >> T;
	for(int i = 0 ; i < n ; ++i)
	{
		char s[10], *p;
		fin >> s;
		p = strchr(s,':');
		*p=0;
		v[i] = 60 * atoi(s) + atoi(p+1);
		x[i] = i;
	}
	for(int i=0 ; i < n-1 ; ++i)
		for(int j = i+1 ; j < n ; ++j)
			if(v[x[i]]>v[x[j]])
			{
				int aux = x[i];
				x[i] = x[j];
				x[j] = aux;
			}
	int  p = 0;
	while(p<n && v[x[p]]<=T)
		T -= v[x[p++]];
	fout << p << endl;
	for(int i=0;i<p;++i)
		fout << x[i]+1 << " ";
	return 0;
}