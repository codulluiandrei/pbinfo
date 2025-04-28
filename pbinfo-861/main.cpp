#include <iostream>
#include <cstring>
using namespace std;
char s[256];
int cnt(int n)
{
	if( n % 2 == 1 )
		return 0;
	for(int i = 0, j = n - 1 ; i < j ; i ++ , j --)
		if(s[i] != s[j])
			return 0;
	return 1 + cnt(n/2);
}
int main(){
	cin.getline(s , 256);
	cout << cnt(strlen(s));
	return 0;
}