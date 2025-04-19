// Stelian Ciurea
#include <fstream>
#define nmax 1000001
using bigint = long long int;
using namespace std;
bigint  v[nmax], first[nmax], last[nmax], ct[nmax], sumpartiala[nmax], sumperest[nmax];
bigint c, n, ctmultipliin, summax;
bool eprima[nmax];
int main()
{
	ifstream in("secvente5.in");
	ofstream out("secvente5.out");
	in >> c>> n;
	for (int i = 1; i <= n; i++)
		in >> v[i];
	int lungmax = -(n + 1), pozmax, lungcrt;
	fill(first, first + n + 10, -1);
	fill(last, last + n + 10, -1);
	bigint sum = 0, restsum;
	first[0] = 0;
	eprima[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		sum = sum + v[i];
		sumpartiala[i] = sum;
		restsum = sum % n;
		if (restsum < 0)
			restsum = restsum + n;
		ct[restsum]++;
		if (first[restsum] < 0)
			first[restsum] = i;
		last[restsum] = i;
		if (v[i] % n == 0)
			ctmultipliin++;
		if (restsum != 0)
			lungcrt = last[restsum] - first[restsum];
		else
			lungcrt = last[restsum];
		if (lungcrt > lungmax)
		{
			lungmax = lungcrt;
			pozmax = restsum;
		}
		bigint sumcrt = sumpartiala[last[restsum]] - sumperest[restsum];
		if (eprima[restsum] == 0)
		{
			eprima[restsum] = 1;
			sumperest[restsum] = sumcrt;
		}
		else
		{
			if (sumcrt < 0)
				sumperest[restsum] = sumpartiala[last[restsum]];
			if (sumcrt > summax)
				summax = sumcrt;
		}
	}
	bigint nrsecvente = 0;
	for (int i = 0; i < n; i++)
		nrsecvente += (ct[i] * (ct[i] - 1) / 2);
	nrsecvente += ct[0] - ctmultipliin;
	if (c == 2)
	{
		out << lungmax << endl;
	}
	if (c == 1)
	{
		out << nrsecvente << endl;
	}
	if (c == 3)
	{
		out << summax << endl;
	}
	return 0;
}