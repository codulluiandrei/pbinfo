#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("magie.in");
ofstream fout("magie.out");
int main()
{
    int n, an, can, nr, nrmax=0, ind=0;
    fin>>n;
    while(fin>>an)
    {
        can=an;
        nr=0;
        //se calculeaza cate persoane au 12 ani
        if(an==2005)
           ind++;
        //se calculeaza suma cifrelor
        while(can)
        {
            nr+=can%10;
            can/=10;
        }
        //se determina cea mai mare suma a cifrelor
        if(nr>nrmax)
            nrmax=nr;
    }
    fout<<ind<<endl;
    fout<<nrmax;
    fin.close();
    fout.close();
    return 0;
}