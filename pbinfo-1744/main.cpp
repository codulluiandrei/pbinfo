#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("nrlipsa2.in");
ofstream fout("nrlipsa2.out");
int x[201], * p;
int main()
{
    p = x + 100;
    int x;
    while(fin >> x){
        if(x >= -100 && x <= 100)
            p[x] = 1;
    }
    x = -100;
    while(x <= 100 && p[x] == 1)
        x ++;
    if(x == 101)
        fout << "nu exista";
    else
        fout << x;
    return 0;
}