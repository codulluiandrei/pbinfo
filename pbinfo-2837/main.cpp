#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("intervale5.in");
ofstream fout("intervale5.out");
int v[101];
int main(){
	int x, y;
    while(fin >> x)
        v[x] = 1;
	x = 0;
    while(v[x] == 0)
        x ++;
    int gasit = 0;
    for(y = x + 1; y <= 100 ; y ++)
        if(v[y] == 1)
        {
            if(y -x >= 2)
                fout << x << " " << y << "\n", gasit = 1;
            x = y;
        }
    if(! gasit)
        fout << "nu exista\n";
    fin.close();
    fout.close();
    return 0;
}