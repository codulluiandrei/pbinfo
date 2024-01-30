#include <iostream>
#include <cstring>
using namespace std;

void eliminare(char * s , int poz)
{
	char t[256];
	strcpy(t , s + poz + 1);
	strcpy(s + poz , t);
}

int main(){
	char s[256];
	cin.getline(s , 256);
	while(s[0] == )
		eliminare(s , 0);
	int n = strlen(s);
	while(s[n - 1] == )
	{	
		eliminare(s , n - 1);
		n --;
	}
	for(int i = 0 ; s[i]; )
		if(s[i] ==  && s[i + 1] == )
			eliminare(s , i + 1);
		else
			i ++;
	cout << s ;
	return 0;
}
