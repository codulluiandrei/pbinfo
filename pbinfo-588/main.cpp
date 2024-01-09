#include <iostream>

#include <fstream>

#define INFINIT 1000000000

using namespace std;



ifstream fin("dijkstra.in");

ofstream fout("dijkstra.out");



int n , a[105][105], v[105], d[105], t[105];



int main()

{

    int i , j , c , p;

    fin >> n >> p;

    

    for(i =1 ; i <= n ; ++i)

		for(j = 1 ; j <= n ; ++j)

			a[i][j] = INFINIT;

	

    while( fin >> i >> j >> c )

    	a[i][j] = c;

	

	for(i =1 ; i <= n ; i ++ )

	{

		v[i] = 0;

		d[i] = a[p][i];

		t[i] = p;

	}

	v[p] = 1, t[p] = 0, d[p] = 0;

	d[0] = INFINIT;

	for(int k = 1 ; k < n ; ++k)

	{

		int pmax = 0;

		for(i = 1 ; i <= n ; ++i)

			if(v[i] == 0 && d[i] < d[pmax])

				pmax = i;

		if(pmax > -1)

		{

			v[pmax] = 1;

			for(i = 1; i <= n ; ++i)

				if(v[i] == 0 && d[i] > d[pmax] + a[pmax][i])

					d[i] = d[pmax] + a[pmax][i], t[i] = pmax;

		}

	}

	

	for(i = 1 ;i <= n ; ++i)

		fout << (d[i] != INFINIT ? d[i] : -1) << " ";

	

    return 0;

}

