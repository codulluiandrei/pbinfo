#include <iostream>
#include <cstring>
using namespace std;
int main(){
	char s[256],t[256], aux[256];
	cin.getline(s,256);
	cin.getline(t,256);
	char *p = strstr(s,t);
	while(p){
      	strcpy(aux , p+strlen(t));
      	strcpy(p,aux);
		p = strstr(s,t);
	}
	cout << s << endl;
	return 0;
}