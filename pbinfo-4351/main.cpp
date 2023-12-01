#include <fstream>
using namespace std;
ifstream fin("echipe.in");
ofstream fout("echipe.out");
int n, i;
long long s;
int main()
{
    fin>>n;
    s=0;i=0;
    while(s<n)
    {   
        i++;
        s=s+i;
    }
    i--;
    if (s==n) fout<<0;
    else fout <<n-(i+1)*i/2;
    return 0;
}
