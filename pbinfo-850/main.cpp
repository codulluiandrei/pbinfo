#include <iostream>
#include <iostream>
#include <cstring>
using namespace std;
int n;
char s[256] , t[256];
int main()
{
	cin >> s;
	int n = strlen(s) , m = 0;
	for(int i = 0 ; i < n ; i++)
		if(s[i] >= 'a' && s[i] <= 'z')
			t[m ++] = s[i] , t[m] = 0;
		else
		{
			// este paranteza rotunda
			i ++;
			int st = i;
			while(s[i] != ')')
				i ++;
			int dr = i - 1;
			i ++;
			int x = 0;
			while(s[i] >='0' && s[i] <='9')
				x = 10 * x + s[i] -'0', i ++;
			s[dr + 1] = 0;
			//cout << s+ st << " " << x <<  endl;
			for(int j = 1 ; j <= x ; j ++)
				strcat(t , s+st);
			m = strlen(t);
			i -- ;
		}
	cout << t;
	return 0;
}