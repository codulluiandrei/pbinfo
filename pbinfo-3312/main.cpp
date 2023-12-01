#include <fstream>
#include <bitset>
using namespace std;
ifstream f("eratostene1.in");
ofstream g("eratostene1.out");
int i,j,x,n,k;
bitset<500001> p;

int main()
{
    p[0] = 1;
    for(i = 3; i <= 999999; i=i+2)
        if(p[i/2]==0)
    {
        j = i+i+i;
        while(j <= 999999)
        {
            p[j/2] = 1;
            j = j + i + i;
        }
    }
    f >> n;
    k=0;
    for(i = 1; i <= n; i++)
    {
        f >> x;
        if(x % 2 == 0)
        {
            if(x == 2)k++;
        }
        else
        {
            if(p[x/2] == 0)k++;
        }
    }
    g << k;
    return 0;
}
