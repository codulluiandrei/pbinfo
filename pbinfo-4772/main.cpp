#include <fstream>
using namespace std;
ifstream fin("catshow.in");
ofstream fout("catshow.out");
int main()
{
    int n,i,x,cul,v, min;
    min=100;
    fin>>n;
    while(n)
    {
        fin>>x;
        if(x==1)
            v=15;
        else
            v=24+4*(x-2);
        cul=v/10;
        if(cul<min)
            min=cul;
        n--;
    }
    fout<<min;
    return 0;
}