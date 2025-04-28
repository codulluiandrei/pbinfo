#include <iostream>
#include <cstring>
using namespace std;
char s[256] , t[256];
bool anagrame(char * s , char * t)
{
	char a[256] , b[256];
	strcpy(a , s);
	strcpy(b , t);
	if(strlen(a) != strlen(b))
		return false;
	if(strcmp(a , b) == 0)
		return false;
	for(int i = strlen(b) - 1 ; i >= 0 ; i --)
	{
		char * p = strchr(a , b[i]);
		if( ! p )
			return false;
		strcpy(p , p + 1);
	}
	return true;
}
int main()
{
	cin.getline(s , 256);
	strcpy(t , s);
	char * p = strtok(t , " ") , * u;
	while(p)
	{
		u = p;
		p = strtok(NULL , " ");
	}
	strcpy(t , s);
	int cnt = 0;
	p = strtok(t , " ");
	while(p)
	{
		if(anagrame( p , u))
			cnt ++;
		p = strtok(NULL , " ");
	}
	cout << cnt;
	return 0;
}