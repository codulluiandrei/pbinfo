#include <iostream>
#include <cstring>
using namespace std;
int v[26];
int main()
{
	char s[256];
	int mari = 0, mici = 0;
	cin.getline(s , 256);
	for(int i = 0 ; s[i] ; i ++)
		if(s[i] >='a' && s[i] <='z')
			mici ++ , v[s[i] - 'a'] = 1;
		else
			if(s[i] >='A' && s[i] <='Z')
				mari ++ , v[s[i] - 'A'] = 1;
	int pp = 0;
	cout << "{";
	for(int i = 0 ; i < 26 ; i ++)
		if(v[i])
		{
			if(pp)
				cout << ",";
			if(mari >= mici)
				cout << (char)('A'+i);
			else
				cout << (char)('a'+i);
			pp = 1;
		}
	cout << "}";
	return 0;
}