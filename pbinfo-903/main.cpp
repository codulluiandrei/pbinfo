#include <iostream>
#include <cstring>
using namespace std;
char s[256];
int n;
char dep[100];
int main()
{
	cin.getline(s , 256);
	cin >> n;
	for(int i = 0 ; i < 26;i++)
		dep[i] = dep[i+26] = i+'a';
	for(int i = 0; s[i] ; i ++)
		if(s[i] >= 'a' && s[i] <='z')
			s[i] = dep[s[i] - 'a' + n];
	cout << s;
	return 0;
}