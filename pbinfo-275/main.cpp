#include <iostream>
#include <fstream>
#include <cstring>
#include <cassert>
using namespace std;
ifstream fin("perechivocale1.in");
ofstream fout("perechivocale1.out");
int a[26][26];
int main(){
	char s,t;
	s=fin.get();
	while((t = fin.get())!=EOF){
		if( strchr("aeiou",s) && strchr("aeiou",t) )
			a[s-'a'][t-'a']++;
		s = t;
	}
	int Max = a[0][0];
	for(int i=0 ; i<26 ; ++i)
		for(int j=0 ; j<26 ; ++j)
			if( a[i][j] > Max)
				Max = a[i][j];
	for(int i=0 ; i<26 ; ++i)
		for(int j=0 ; j<26 ; ++j)
			if( a[i][j] == Max)
				fout << (char)(i+'a') << (char)(j+'a') << " ";
	return 0;
}