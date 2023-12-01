#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdlib>
using namespace std;

char operatie[25];
int n , S[1005] , nrS = 0, X;

int main()
{
	cin >> n;
	for(int i =1 ; i <= n ; i ++)
	{
		assert(cin >> operatie);
		if(strcmp(operatie,"push") == 0)
		{
			assert(cin >> X);
			if(nrS < 1000)
				S[++nrS] = X;
			else
			{
				//aceasta situatie nu se intampla niciodata.
				cerr << "Prea multe elemente pe stiva";
				exit(1);
			}
		}
		if(strcmp(operatie,"pop") == 0)
			if(nrS > 0)
				nrS --;
		if(strcmp(operatie,"top") == 0)
			if(nrS > 0)
				cout << S[nrS] << "
";
		
	}
	return 0;
}
