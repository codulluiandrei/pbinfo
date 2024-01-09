#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
using namespace std;
#define NN 10005

ifstream fin("pachete.in");
ofstream fout("pachete.out");

int n, spatiu[NN], unde[NN], liber ,M;

struct manevra{
	int sursa,dest;
	manevra(){sursa = 0, dest = 0;}
	manevra(int i,int j){sursa = i, dest = j;}
	friend ostream& operator << (ostream &os, manevra x)
	{
		os << x.sursa << " " << x.dest;
		return os;
	}
};

manevra v[2*NN+10];

void muta(int i){
	v[++M] = manevra(i,liber);
	spatiu[liber] = spatiu[i];
	unde[spatiu[i]] = liber;
	spatiu[i] = 0;
	liber = i;
}

int main(){
	assert(fin >> n );
	for(int i=1 ; i<=n ; ++i)
		assert(fin >> spatiu[i]), unde[spatiu[i]] = i;
	liber = n+1;
	for(int i=1 ; i<=n ; ++i)
		if(spatiu[i]!=i)
		{
			//vad unde este pachetul i
			if(spatiu[i]!=0) //spatiul i este ocupat, il eliberez
				muta(i);
			muta(unde[i]);
		}
	fout << M << "
";
	for(int i=1;i<=M;++i)
		fout << v[i] << "
";
	return 0;
}
