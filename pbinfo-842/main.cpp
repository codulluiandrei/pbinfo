#include <iostream>
using namespace std;

void fierastrau(int n)
{
	if(n > 0)
	{
		fierastrau(n-1);
		cout << n << " ";
		fierastrau(n-1);
	}
}

int main(){
	int n;
	cin >> n ;
	fierastrau(n);
	return 0;
}
