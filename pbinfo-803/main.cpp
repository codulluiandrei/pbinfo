#include <fstream>
using namespace std;

ifstream fin("nrsufix.in");
ofstream fout("nrsufix.out");

int main(){
	int x , y = -1 , z , p = 1;
	fin >> x;
	int cp = x;
	while(cp)
		cp /= 10, p *= 10;
	while(fin >> z)
		if(z % p == x)
			y = z;
	if(y == -1)
		fout << "nu exista";
	else
		fout << y;
	return 0;
}
