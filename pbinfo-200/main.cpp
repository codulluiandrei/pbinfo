#include <iostream>
#include <cstring>
using namespace std;
int main(){
	char s[256],t[256];
	cin.getline(s,256);
	cin.getline(t,256);
	char *p = strstr(s,t), *q = NULL;
	while(p){
		q = p;
		p = strstr(p+1,t);
	}
	if(q)
		strcpy(q,q+strlen(t));
	cout << s << endl;
	return 0;
}