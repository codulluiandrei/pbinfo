#include <iostream>
using namespace std;
int main()
{
	char c;
	while(cin.get(c))
	{
		if(c >= 'A')
		{
			if(c >= 'a')
				c = (c - 'a' + 13) % 26 + 'a';
			else
				c = (c - 'A' + 13) % 26 + 'A';
		}
		cout.put(c);
	}
	return 0;
}