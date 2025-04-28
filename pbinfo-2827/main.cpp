#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;
ifstream fin("sir12.in");
ofstream fout("sir12.out");
int main(){
	int max1 = -1, max2 = -2, x, cnt = 0;
    while(fin >> x)
        if(x % 2 == 1)
            cnt ++;
        else
            if(cnt == 3)
                if(x > max1)
                    max2 = max1, max1 = x;
                else
                    if(x > max2)
                        max2 = x;
    if(max2 > 0)
        fout << max2 << " " << max1 << "\n";
    else
        fout << "Nu exista\n";
    fin.close();
    fout.close();
	return 0;
}