#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;
ifstream fin("numere25.in");
ofstream fout("numere25.out");
int main(){
	int n , x , y, gasit = 0;
    fin >> n;
    x = 0;
    while(fin >> y)
    {
        for(int i = x + 1 ; i < y ; i ++)
            fout << i << " ", gasit = 1;
        x = y;
    }
    y = n + 1;
    for(int i = x + 1 ; i < y ; i ++)
        fout << i << " ", gasit = 1;
    if(! gasit)
        fout << "Nu exista";
    fout << "\n";
    fin.close();
    fout.close();
	return 0;
}