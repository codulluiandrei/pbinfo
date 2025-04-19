#include <iostream>
using namespace std;
int n, x[100005];
int main(){
	cin  >> n;	
	for(int i = 0 ; i < n ; ++ i)
		cin >> x[i];
	int candidat = x[0], contor = 1;
	for(int  i = 1; i < n ; ++i)
	{
		if(x[i] == candidat)
			contor++;
		else
			contor --;
		if(contor == 0)
			candidat = x[i], contor = 1;
	}
	contor = 0;
	for(int i = 0 ; i < n ; ++ i)
		if(x[i] == candidat)
			contor ++;
	if(contor > n/2)
		cout << "DA " << candidat;
	else
		cout << "NU";
	return 0;
}