#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("crescator1.in");
ofstream fout("crescator1.out");
int main(){
	int x, y, cnt = 0, gasit = 0;
    fin >> x;
    cnt = 1;
	while(!gasit && fin>>y)
        if(x == y)
            cnt ++;
        else
        {
            if(cnt % 2 == 1)
                gasit = 1;
            else
            {
                x = y, cnt = 1;
            }
        }
    if(! gasit)
        if(cnt % 2 == 1) // tratam ultima secventa
            gasit = 1;
    if(gasit)
        fout << x;
    else
        fout << "nu exista";
	return 0;
}