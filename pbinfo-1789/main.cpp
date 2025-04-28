#include <fstream>
using namespace std;
ifstream f("3secv.in");
ofstream g("3secv.out");
int n,r,R,RC,RN;
long long s[3],sol;
int main()
{
    f>>n>>r;
    s[0]=1;
    for(;n;n--)
    {
        f>>R;
        R%=3;
        RC=(RC+R)%3;
        RN=RC>=r?RC-r:RC-r+3;
        sol+=s[RN];
        s[RC]++;
    }
    g<<sol;
    return 0;
}