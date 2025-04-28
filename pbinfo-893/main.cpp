#include <iostream>
#include <cstring>
using namespace std;
char s[2560], v[100][16] , * t;
int n;
int main()
{
	cin.getline(s , 2560);
	t = strtok(s , " ");
	while(t)
	{
		int poz = -1;
		for(int i = 0 ; i < n && poz == -1 ; i ++)
			if(strcmp(t , v[i]) == 0)
				poz = i;
		if(poz == -1)
		{
			strcpy(v[n] , t);
			n ++;
		}
		t = strtok(NULL , " ");
	}
	for(int i = 0 ; i < n ; i ++)
		for(int j = i + 1 ; j < n ; j ++)
			if(strcmp(v[i] , v[j]) > 0)
			{
				strcpy(s , v[i]);
				strcpy(v[i] , v[j]);
				strcpy(v[j] , s);
			}
	for(int i = 0 ; i < n ; i ++)
		cout << v[i] << "\n";
	return 0;
}