#include <iostream>
using namespace std;

struct data{
	int an , luna , zi;
};

int data_cmp(data x, data y)
{
	//returneaza  0 daca datele sunt egale
	//			  1 daca x > y
	//			 -1 daca x < y
	if(x.an < y.an)
		return -1;
	if(x.an > y.an)
		return 1;
	if(x.luna < y.luna)
		return -1;
	if(x.luna > y.luna)
		return 1;
	if(x.zi < y.zi)
		return -1;
	if(x.zi > y.zi)
		return 1;
	return 0;
}

void citire(data & d)
{
	cin >> d.an >> d.luna >> d.zi;
}

int main()
{
	int n, p, q;
	data dmin, dmax, d;
	cin >> n;
	citire(d);
	dmin = dmax = d;
	p = q = 1;
	for(int i = 2 ; i <= n ; i ++)
	{
		citire(d);
		if(data_cmp(d, dmin) < 0)
			dmin = d, q = i;
		if(data_cmp(d, dmax) > 0)
			dmax = d, p = i;
	}
	cout << p << " " << q;
	return 0;
}
