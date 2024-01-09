#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("graf_complet.in");
ofstream fout("graf_complet.out");

int G, n , a[105][105];

int main()
{
    fin >> G;
    for( ; G ; G--)
    {
		fin >> n;
		for(int i = 1 ; i <= n ; ++i)
			for(int j = 1 ; j <= n ; ++j)
				fin >> a[i][j];
		
		bool complet = true;
		for(int i = 1 ; i < n ; ++i)
			for(int j = i + 1 ; j <= n ; ++j)
				if(a[i][j] == 0 || a[j][i] == 0)
					complet = false;
		if(complet)
			fout << "DA
";
		else
			fout << "NU
";
	}

    return 0;
}
