#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
int main(){
	char s[51], t[51];
	cin.getline(s , 51);
	for(int i=0 ; s[i] ; )
		if(!isalpha(s[i]))
    	{
      		strcpy(t , s + i + 1);
			strcpy(s + i, t);
    	}
		else
			i++;
	cout << s;
	return 0;
}