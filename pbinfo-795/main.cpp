#include <iostream>
using namespace std;

int fete[105],baieti[105], nrf = 0, nrb = 0, n;

int main(){
	cin  >> n;
	char s;	
	int H;
	for(int i = 1 ; i <= n ; ++i)
	{
		cin >> s >> H;
		if(s == 'B')
			baieti[++nrb] = H;
		else
			fete[++nrf]   = H;
	}
	int fmax = fete[1], bmin = baieti[1];
	for(int i = 1 ; i <= nrf ; i ++)
		if(fmax < fete[i])
			fmax = fete[i];
	for(int i = 1 ; i <= nrb ; i ++)
		if(bmin > baieti[i])
			bmin = baieti[i];
	int A = 0 , B = 0;
	for(int i = 1 ; i <= nrf ; i ++)
		if(fete[i] < bmin)
			A ++;
	for(int i = 1 ; i <= nrb ; i ++)
		if(baieti[i] > fmax)
			B ++;
	cout << A << " " << B << endl;
	return 0;
}
