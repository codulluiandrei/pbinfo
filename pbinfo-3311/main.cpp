#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ifstream f("nrreg.in");
ofstream g("nrreg.out");
ull x, y, z, a = 2, b = 3, c = 5, ultim = 1;
ull mini(ull x, ull y, ull z)
{
    ull m=x;
    if(y<m)
        m=y;
    if(z<m)
        m=z;
    return m;
}
ull minim(ull n)
{
	ull k = 0, rez = 1;
	while (n%2 == 0)
	{
		k++;
		n /= 2;
	}
	if (k%2!=0)
		rez = rez * 2;
	for (ull i = 3; i * i <= n; i = i + 2)
	{
		k = 0;
		while (n%i == 0)
		{
			k++;
			n /= i;
		}
		if (k%2!=0)
			rez = rez * i;
	}
	if (n > 2)
		rez = rez * n;
	return rez;
}
int main()
{
    int n;
    f>>n;
    ull reg[n];
    reg[0] = 1;
    for (int i=1; i<n; i++)
    {
       ultim = mini(a, b, c);
       reg[i] = ultim;
       if (ultim == a)
           x++, a = reg[x]*2;
       if (ultim == b)
           y++, b = reg[y]*3;
       if (ultim == c)
           z++, c = reg[z]*5;
    }
    ull y=minim(ultim);
    g<<ultim<<' '<<y<<' '<<ultim/y;
    /*for(int i=1;i<n;i++)
        {
            g<<reg[i]<<' ';
            if(i%5==0)
                g<<endl;
        }*/
    return 0;
}