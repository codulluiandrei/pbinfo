#include <iostream>
#include <cstring>
#include  <cassert>
using namespace std;
int vocala(char c){
	return strchr("aeiou",c)!=0;
}
int main(){
	char x[35],y[35],s[35];
	cin >> x >> y;
	assert(strlen(x)==strlen(y));
	s[strlen(x)] = 0;
	for(int i=0;x[i];++i){
		if(vocala(x[i]) && vocala(y[i]))
			s[i]='*';
		else
			if(!vocala(x[i]) && !vocala(y[i]))
				s[i]='#';
			else
				s[i]='?';
	}
	cout << s;
	return 0;
}