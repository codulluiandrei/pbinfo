#include <iostream>
#include <cstring>
using namespace std;
bool Vocala(char x)
{
	if( x == 'a' || x == 'e' || x== 'i' || x == 'o' || x=='u')
		return true;
	return false;
}
int main(){
	char s[256];
	cin.getline(s , 256);
	int st = 1 , dr = 0;
	for(int i = 0 ; s[i] ; i ++)
		if(!Vocala(s[i]))
		{
			int j = i + 1;
			while(s[j] && ! Vocala(s[j]))
				j ++;
			if(j - i >= dr - st + 1)
				dr = j - 1, st = i;
		}
	s[dr + 1] = 0;
	cout << s + st;
	return 0;
}