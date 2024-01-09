#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
using namespace std;
#define NN 105
#define SS 105*100+10

ifstream fin("bete.in");
ofstream fout("bete.out");

int n, S, B[NN], v[SS], last[SS], smax;

void determinare(int i, int contor)
{
	if(i==0)
		fout << contor << "
";
	else
	{
		determinare(i-B[last[i]], contor+1);
		fout << last[i] << " ";
	}
		
}

int main(){
	assert(fin >> n >> S );
	for(int i=1 ; i<=n ; ++i)
		assert(fin >> B[i]), assert(B[i]<100), smax += B[i];
	if(S > smax)
	{
		fout << "NU";
		return 0;
	}
		
	v[0] = 1;
	for(int i=1;i<=n;++i)
		for(int j=smax ; j>=0 ; --j)
			if(v[j] && !v[j+B[i]])
				v[j+B[i]] = 1, last[j+B[i]] = i;
	//for(int i=0; i<=smax; ++i)
	//	cout << i << " " << v[i] << " " << last[i] << endl;
	
	
	if(!v[S])
		fout << "NU
";
	else
	{
		fout << "DA
";
		determinare(S, 0);
	}
	
	return 0;
}
