#include <iostream>
#include <cstring>
using namespace std;
bool Cifra(char X)
{
	return X >='0' && X<='9';
}
int main()
{
	char s[256];
	cin.getline(s , 256);
	int coefX = 0 , coefY = 0, coefZ = 0;
	bool apareX = false, apareY = false , apareZ = false;
	int semn = 1 , coef = 0;
	bool amCoef = false;
	int n = strlen(s);
	for(int i = 0 ; i < n ; i ++)
	{
		if(s[i] == '+')
			semn = 1;
		if(s[i] == '-')
			semn = -1;
		if(Cifra(s[i]))
		{
			coef = 0, amCoef = true;
			while(Cifra(s[i]))
				coef = 10 * coef + s[i] - '0' , i ++;
		}
		if(s[i] == 'x' || s[i] == 'y' || s[i] == 'z')
		{
			if(!amCoef)
				coef = 1;
			if(s[i] == 'x')
				apareX = true, coefX += semn * coef;
			if(s[i] == 'y')
				apareY = true, coefY += semn * coef;
			if(s[i] == 'z')
				apareZ = true, coefZ += semn * coef;
			semn = 1, coef = 0, amCoef = false;
		}
	}
	int cf[4]={-2000000001 , coefX, coefY, coefZ}, apare[4]={0 , apareX,apareY,apareZ};
	int pozMax = 0;
	for(int i = 1; i <= 3 ; i ++)
		if(apare[i])
			if(cf[i] > cf[pozMax])
				pozMax = i;
	if(pozMax == 1)
		cout << cf[pozMax] << "x";
	if(pozMax == 2)
		cout << cf[pozMax] << "y";
	if(pozMax == 3)
		cout << cf[pozMax] << "z";
	return 0;
}