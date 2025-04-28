#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("secventeneuniforme.in");
ofstream fout("secventeneuniforme.out");
int main(){
	int a , b ,c, lg = 0, lgmax = 0;;
    fin >> a >> b;
    while(fin >> c)
    {
        if(a != b && b != c && c != a)
            lg ++;
        else
            lg = 0;
        if(lg > lgmax)
            lgmax = lg;
        a = b;
        b = c;
    }
    fout << lgmax + 2;
    fin.close();
    fout.close();
	return 0;
}