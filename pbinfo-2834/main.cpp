#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("sir13.in");
ofstream fout("sir13.out");
int main(){
	int ok = 1, p = -1, i = 1000000001, x;
    while(fin >> x)
        if(x % 2 == 0)
        {
            if(x < p)
                ok = 0;
            p = x;
        }
        else
        {
            if(x > i)
                ok = 0;
            i = x;
        }
    if(ok)
        fout << "DA
";
    else
        fout << "NU
";
    return 0;
}