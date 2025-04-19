#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("repetare.in");
ofstream fout("repetare.out");
int n , m , a[1005], b[1005];
int main()
{
	fin >> n;
	for(int i = 1 ; i <= n ; i ++)
		fin >> a[i];
	fin >> m;
	for(int i = 1 ; i <= m ; ++ i)
		fin >> b[i];
	int cnt = 1;
	bool ok = true;
	int i = 1 , j = 1;
	while(j <= m && ok)
	{
		int ivechi = i;
		bool marit = false;
		while(i <= n && a[i] != b[j])
			i ++;
		if(i == n + 1)
		{
			i = 1;
			cnt ++;
			marit = true;
			while(i < ivechi && a[i] != b[j])
				i ++;
		}
		if(i == ivechi && marit)
		{
			// nu l-am gasi pe b[j] in a[], nu se poate 
			ok = false;
		}
		else
			i ++, j ++;
	}
	if(ok)
		fout << cnt;
	else
		fout << "IMPOSIBIL";
}