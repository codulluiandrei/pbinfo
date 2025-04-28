#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("parimpar1.in");
ofstream fout("parimpar1.out");
int main(){
	int x, s1p = 0, s2p = 0, s1i = 0, s2i = 0, n;
    fin >> n;
    for(int i = 1 ; i <= n ; i ++)
    {
        fin >> x;
        if(x % 2 == 0)
            s1p += x;
        else
            s1i += x;
    }
    for(int i = 1 ; i <= n ; i ++)
    {
        fin >> x;
        if(x % 2 == 0)
            s2p += x;
        else
            s2i += x;
    }
    fout << s1p * s2i + s1i * s2p << endl;
    fin.close();
    fout.close();
    return 0;
}