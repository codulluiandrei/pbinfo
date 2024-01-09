#include <iostream>
#include <algorithm>

using namespace std;

struct Magazin{
	int pret , cantitate;
};

int n , m;
Magazin V[101];

bool fcmp(Magazin A, Magazin B)
{
	if(A.pret < B.pret)
		return true;
	return false;
}

int main()
{
	cin >> n >> m;
	int k = 0;
	for(int i = 1; i <= m ; i ++)
	{
		cin >> V[i].pret >> V[i].cantitate;
		k += V[i].cantitate;
	}
	if(n > k)
		cout << "imposibil\n";
	else
	{
		sort(V + 1 , V + m + 1 , fcmp);
		int S = 0;
		for(int i = 1 ; i <= m && n > 0 ; i ++)
			if(V[i].cantitate <= n)
			{
				S += V[i].pret * V[i].cantitate, n -= V[i].cantitate;
			}
			else
				S += n * V[i].pret, n = 0;
			
		cout << S << endl;
	}
	return 0;
}
