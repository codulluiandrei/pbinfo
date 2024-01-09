#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("bomboane.in");
ofstream fout("bomboane.out");

int n , x[1005], I[1005], S[1005], D[1005], B[1005], nrM=0;

bool MaiMic(int i, int j)
{
	return x[i]<x[j];
}

int main(){
	fin >> n;
	int s = 0;
	for(int i=1 ; i<=n ; ++i)
		fin >> x[i], I[i] = i, s += x[i];
	if(s % n !=0)
		fout << -1;
	else{
		int q = s / n;
		sort(I+1, I+n+1, MaiMic);
		int i=1,j=n;
		while(i<j)
		{
			int necesar = q-x[I[i]], surplus = x[I[j]] - q;
			if(necesar==0)
				i++;
			else
				if(surplus==0)
					j--;
				else
					if(necesar <= surplus)
					{
						x[I[i]] += necesar;
						x[I[j]] -= necesar;
						nrM++;
						S[nrM] = I[j], D[nrM] = I[i], B[nrM] = necesar;
						int p = I[j], k = j;
						while(x[I[k-1]]> x[p])
							I[k] = I[k-1], k--;
						I[k] = p;
						p = I[i];
						k = i;
						while(x[I[k+1]]<x[p])
							I[k] = I[k+1], k++;
						I[k] = p;
					}
					else
					{
						x[I[i]] += surplus;
						x[I[j]] -= surplus;
						nrM++;
						S[nrM] = I[j], D[nrM] = I[i], B[nrM] = surplus;
						int p = I[j] , k = j;
						while(x[I[k-1]]> x[p])
							I[k] = I[k-1], k--;
						I[k] = p;
						p = I[i];
						k = i;
						while(x[I[k+1]]<x[p])
							I[k] = I[k+1], k++;
						I[k] = p;
					}
		}
		fout << nrM << "
";
		for(int i=1 ; i<=nrM ; ++i)
			fout << S[i] << " " << D[i] << " " << B[i] << "
";
	}
	return 0;
}
