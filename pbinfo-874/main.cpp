#include <iostream>
#include <cstring>
using namespace std;
char s[256];
int A[1000] , B[1000] , n , *v;
int main()
{
	cin >> s;
	n = 1;
	for(unsigned int i = 0 ; i < strlen(s) ; i ++)
		if(s[i] == '(')
			n++,A[n] = B[n] = 0;
		else
			if(s[i] == ')')
			{
				int x = 0;
				if(s[i+1]>='0' && s[i+1] <='9')
				{
					while(s[i+1]>='0' && s[i+1] <='9')
						x = 10 * x + s[i+1] - '0', i ++;
				}
				else
					x = 1;
				A[n-1] += A[n] * x, B[n-1] += B[n] * x , n --;
			}
			else
			{
				//este A sau B
				if(s[i] == 'A')
					v = A;
				else
					v = B;
				int x = 0;
				if(s[i+1]>='0' && s[i+1] <='9')
				{
					while(s[i+1]>='0' && s[i+1] <='9')
						x = 10 * x + s[i+1] - '0', i ++;
				}
				else
					x = 1;
				v[n] += x;
			}
	cout << A[1] << " " << B[1];
	return 0;
}