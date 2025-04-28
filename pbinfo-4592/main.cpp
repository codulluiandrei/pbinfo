#include <fstream>
using namespace std;
ifstream fin ("fotbal.in");
ofstream fout ("fotbal.out");
int n, p, c, e, maxi, mini=10001, punctaj, i;
int main()
{
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>c>>p>>e;
        punctaj=c*3+e;
        if(punctaj>maxi) maxi=punctaj;
        if(p<mini && p!=0) mini=p;
    }
    if(n%2==0) fout<<maxi;
    else fout<<mini;
    fin.close();
    fout.close();
    return 0;
}