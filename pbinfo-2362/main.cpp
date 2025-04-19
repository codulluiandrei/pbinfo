#include <fstream>
using namespace std;
ifstream fin("balmascat.in");
ofstream fout("balmascat.out");
int n,i,uc,nr_cutii,p;
int main()
{
    fin>>n>>p;
    nr_cutii=n/p;
    if(n%p!=0)
        nr_cutii++;
    uc=nr_cutii%10;
    if(uc==9)
    {
        for(i=1; i<=p-1; i++)
            fout<<uc-1<<uc;
        fout<<uc-1;
    }
    else
    {
        for(i=1; i<=p-1; i++)
            fout<<uc+1<<uc;
        fout<<uc+1;
    }
    fin.close();
    fout.close();
    return 0;
}