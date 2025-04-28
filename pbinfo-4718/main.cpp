#include<iostream>
using namespace std;
int main()
{
	int L, C, r, q, S;
	cin>>L>>C ;
	S = (L - 1) * L / 2;
	r = S % 9;
	if (r == 0) r = 9;
	r++;
	if (r == 10) r = 1;
	q = C % 9;
	if (q == 0) q = 9;
	r += (q - 1);
	if (r > 9) r -= 9;
	cout << r << "\n";
	return 0 ;
}