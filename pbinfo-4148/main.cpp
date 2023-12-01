#include <fstream>
using namespace std;
ifstream fin("secv10.in");
ofstream fout("secv10.out");

int main()
{
    int n,x,l=0,lmax=0,c=0;
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>x;
        if(x%10==0)
        {
            l++;
            if(l>lmax)
            {
                lmax=l; c=1;
            }
            else if(l==lmax) c++;
        }
        else l=0;
    }
    fout<<lmax<<" "<<c;
    return 0;
}
