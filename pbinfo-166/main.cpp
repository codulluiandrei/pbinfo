#include <iostream>
#include <fstream>
using namespace std;
int n, v[10005];
ifstream fin("secvmax.in");
ofstream fout("secvmax.out");
int main(){
	fin >> n;
	for(int i=1;i<=n;++i)
		fin >> v[i];
	int st=0,dr=0, smax =0, lgmax = 0;
	for(int i=1;i<=n;++i)
		if(v[i]%2==0){
			int s = v[i], j=i+1;
			while(j<=n && v[j]%2==0)
				s += v[j++];
			if(j-i>lgmax)
				lgmax = j-i, smax = s, st = i, dr = j-1;
			else
				if(j-i == lgmax && s>smax)
					smax = s, st = i, dr = j-1;
			i = j;
		}
	fout << st << " " << dr ;
	fin.close();
	fout.close();
	return 0;
}