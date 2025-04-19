#include <fstream>
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;
ifstream fin("anagrame1.in");
ofstream fout("anagrame1.out");
char s[10];
int x[10],uz[10],n;
void afis(int k){
	for(int i=1;i<=n;++i)
		fout<<s[x[i]];
	fout << endl;
}
void back(int k){
	for(int i=0;i<n;++i)
		if(uz[i]==0){
			uz[i] = 1;
			x[k]=i;
			if(k==n)
				afis(k);
			else
				back(k+1);
			uz[i] = 0;
		}
}
int main(){
	fin >> s;
	n = strlen(s);
	for(int i=0;i<n;++i)
		for(int j=i+1; j<n;j++)
			if(s[i]>s[j]){
				char aux = s[i];
				s[i] = s[j];
				s[j] = aux;
			}
	back(1);
	return 0;
}