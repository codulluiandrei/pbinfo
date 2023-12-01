#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;

int main(){
	int n, a, b, c, S,P;
	cin >> a >> b >> c >> n;
	S = -b/a, P = c/a;
	int S2 = S, S1 = 1 + 1, S3;
	if(n==1)
		cout << S2;
	else
	{
		for(int i=2 ; i<=n ; ++i)
		{
			S3 = S*S2 - P * S1;
			S1 = S2;
			S2 = S3;
		}
		cout << S3;
		
	}
	return 0;
}
