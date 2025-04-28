#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;
ifstream fin("inserare2.in");
ofstream fout("inserare2.out");
int main(){
	int n , m , x, y , p , u , poz = 0;
    fin >> n >> m;
    fin >> p;
    for(int i = 2 ; i <= n ; i ++)
        fin >> x;
    u = x;
    fin >> x;
    for(int i = 2 ; i <= m ; i ++)
    {
        assert(fin >> y);
        if(x < p && u < y)
            poz = i;
        x = y;
    }
    if(poz == 0)
        fout << "imposibil
";
    else
        fout << poz << endl;
    fin.close();
    fout.close();
	return 0;
}