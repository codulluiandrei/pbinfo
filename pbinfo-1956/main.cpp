#include <fstream>
using namespace std;
int main()
{
    long long  a = 1 , b = 1 , ra = 1 , rb , bb , nrd = 2 , c , d;
    int n , i , p;
    ifstream f("siruri2.in");
    ofstream g("siruri2.out");
    f >> p >> n;
    if (n == 1 || n == 2) g << 1 << ' ' << 1;
    else
    {
        if (p == 1)
            for (i = 3; i <= n; i++)
            {
                c = a + b;
                a = b;
                b = c;
            }
        else
            for (i = 3 ; i <= n ; i++)
            {
                rb = 0;
                bb = b;
                while (bb)
                {
                    rb = rb * 10 + bb % 10;
                    bb = bb / 10;
                }
                c = ra + rb;
                a = b;
                ra = rb;
                b = c;
            }
        for(d = 2; d * d < c; d++)
            if(c % d == 0) nrd += 2;
        if (d * d == c) nrd++;
        g << c << " " << nrd;
    }
    return 0;
}