#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("detdrum3.in");
ofstream fout("detdrum3.out");
int n , t[105], v[105];
void drum(int k)
{
	if(k != 0)
	{
		drum(t[k]);
		fout << k << " ";
	}
}
int cost_drum(int k)
{
	if(k == 0)
		return 0;
	else
		return v[k] + cost_drum(t[k]);
}
bool terminal(int k)
{
	for(int i = 1 ; i <= n ; ++i)
		if(t[i] == k)
			return false;
	return true;
}
int main()
{
	fin >> n;
	for(int i = 1 ; i <= n ; i ++)
		fin >> t[i];
	for(int i = 1 ; i <= n ; i ++)
		fin >> v[i];
	int cmax = 0, vmax;
	for(int i = 1 ; i <+ n ; ++i)
		if(terminal(i))
		{
			int cc = cost_drum(i);
			if(cc > cmax)
				cmax = cc , vmax = i;
		}
	fout << cmax << "\n";
	drum(vmax);
	return 0;
}