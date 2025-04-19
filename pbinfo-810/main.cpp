#include <iostream>
#include <cstring>
using namespace std;
int main(){
	char s[71];
	cin.getline(s , 71);
	char * p;
	int cnt = 0;
	p = strtok(s, " ");
	while(p)
	{
		if(strchr(p,'a'))
			cnt ++;
		p = strtok(NULL, " ");
	}
	cout << cnt;
	return 0;
}