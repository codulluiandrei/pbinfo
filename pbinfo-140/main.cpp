#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("putere.in");
ofstream fout("putere.out");
int main()
{
    int p , m , n , x , y , a , b;
    long long s = 0;
    fin >> m >> n;
    a = m % 10;
    b = n % 10;
    if(a == 0 && b == 0)
        p = 0;
    else
        p = pow((double)a,b);
    fout << p << endl;
    while(m != 0 && n != 0)
    {
        x = m % 10;
        y = n % 10;
        s = s + pow((double)x,y);
        m = m / 10;
        n = n / 10;
    }
    fout << s;
    fin.close();
    fout.close();
    return 0;
}