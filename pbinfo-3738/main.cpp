#include<fstream>
using namespace std;
ifstream cin("nyk.in");
ofstream cout("nyk.out");
bool verifprim(int nr)
{
    if(nr < 2)
        return false;
    if(nr == 2)
        return true;
    if(nr % 2 == 0)
        return false;
    for(int d = 3; d * d <= nr; d += 2)
        if(nr % d == 0)
            return false;
    return true;
}
int main()
{
    int n, x, y;
    int blmax = -1;
    int cmmdcmax = 0;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int a, b, r, m, bmax = -1, cnt;
        cin>>m;
        cin>>a;
        if(bmax <= a && verifprim(a))
        {
            bmax = a;
            cnt = 1;
        }
        for(int j=1; j<m; j++)
        {
            cin>>b;
            if(bmax <= b && verifprim(b))
            {
                bmax = b;
                cnt = j + 1;
            }
            while(b != 0)
            {
                r = a % b;
                a = b;
                b = r;
            }
        }
        if(a > cmmdcmax)
        {
            cmmdcmax = a;
            blmax = bmax;
            x = cnt;
            y = i;
        }
        else if(a == cmmdcmax && blmax <= bmax)
        {
            cmmdcmax = a;
            blmax = bmax;
            x = cnt;
            y = i;
        }
    }
    if(blmax==-1)
        cout<<"Nu am gasit casa!";
    else
        cout<<y<<" "<<x<<'\n'<<blmax;
    return 0;
}