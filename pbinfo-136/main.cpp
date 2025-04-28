#include <iostream>
#include <cstring>
using namespace std;
char s[151];
int main(){
	cin.getline(s,151);
	char *p = strtok(s," ");
	int c = 0;
	while(p){
		if(strchr("aeiouAEIOU",p[0]) && strchr("aeiouAEIOU",p[strlen(p)-1]))
			c++;
		p = strtok(NULL," ");
	}
	cout << c << endl;
	return 0;
}