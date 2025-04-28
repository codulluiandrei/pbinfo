#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("secventapara.in");
ofstream fout("secventapara.out");
int main(){
	int x, lgmax = -1, lg = 0, cntmax = 0;
	while(fin>>x)
        if(x % 2 == 1)
            lg = 0;
        else
        {
            lg ++;
        	if(lg >= 2)
            {
                if(lg > lgmax)
                    lgmax = lg, cntmax = 1;
                else
                    if(lg == lgmax)
                        cntmax ++;
            }
        }
    fout << cntmax;
	return 0;
}