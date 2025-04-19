#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;
ifstream fin("ciclul.in");
ofstream fout("ciclul.out");
int n , A[21][21], L , x[21], uz[21], gasit = false;
bool OK(int k)
{
	if(k == 1)
		return true;
	if(A[x[k-1]][x[k]] == 0)
		return false;
	return true;
}
void Back(int k)
{
	for(int i = 1; i <= n && ! gasit; i ++)
		if(uz[i] == 0)
		{
			uz[i] = 1;
			x[k] = i;
			if(OK(k))
			{
				if(k == L)
				{
					if(A[x[k]][x[1]] == 1)
					{
						for(int i = 1; i <= k ; i ++)
							fout << x[i] << " ";
						fout << x[1] << '\n';
						gasit = true;
					}
				}
				else
					Back(k + 1);
			}
			uz[i] = 0;
		}
}
int main()
{
    int i , j, m;
    fin >> n >> m;
    while(m > 0)
    {
		fin >> i >> j;
		if(A[i][j] == 1)
			cout << i << " " << j << endl;;
        A[i][j] = A[j][i] = 1;
        m --;
    }
    fin >> L;
	Back(1);
    return 0;
}