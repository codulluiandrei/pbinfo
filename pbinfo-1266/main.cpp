#include <fstream>
using namespace std;
ifstream in("cautanrinmatrice.in");
ofstream out("cautanrinmatrice.out");
int v[1000008], n, m, C, temp, li, co, prod, poz, mij;
int caut(int st, int dr) {
    if (st > dr) return 0 ;
    else {
    	mij = (st + dr) / 2 ;
    	if (v[mij] == temp) return mij ;
    	else if (v[mij] < temp) return caut (mij + 1, dr) ;
    	else return caut(st, mij - 1);
	 }
}
int main() {
    in >> n >> m ;
    prod = n * m ;
    for (int i = 1; i <= n; ++i)
       if (i % 2 == 1)
    	   for (int j = 1; j <= m; ++j)
    		   in >> v[(i - 1) * m + j] ;
		   else for (int j = 1; j <= m; ++j)
			   in >> v[i * m - j + 1];
    in >> C;
    for (int c = 1; c <= C; ++c) {
		in >> temp;
		poz = caut(1, prod) ;
		if (poz == 0)
			out << 0 << "\n" ;
		else {
			if (poz % m == 0) {
				li = poz / m; co = m;
			} else {
				li = poz / m + 1;
				co = poz % m;
			} if (li % 2 == 1)
				out << li << " " << co << "\n" ;
			else out << li << " " << m - co + 1 << "\n" ;
	    }
    } return 0 ;
}
