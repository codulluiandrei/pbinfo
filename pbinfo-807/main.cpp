#include <iostream>
#include <cstring>
using namespace std;
int main(){
	char s[256] , t[256];
	cin.getline(s , 256);
	char * p;
	for(int i = 0 ; s[i] ; i ++)
	{
		if(s[i] >= 'a' && s[i] <= 'z' && (i == 0 || s[i-1] == ' '))
		{
			p = strchr(s+i, ' ');
			if(p)
				if(p - (s + i) == 3)
				{
					s[i] = '*';
					strcpy(t , s + i + 3);
					strcpy(s + i + 1 , t);
				}
				else;
			else
				if(strlen(s) - i == 3)
				{
					s[i] = '*';
					strcpy(t , s + i + 3);
					strcpy(s + i + 1 , t);
				}
		}
	}
	cout << s ;
	return 0;
}