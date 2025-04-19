#include <fstream>
using namespace std;
ifstream f("twoop.in");
ofstream g("twoop.out");
#define NMAX 100010
int n, nrOp1, nrOp2, st, dr, val, poz;
long long v[NMAX], res[NMAX];
void op1()
{
    res[st] += val;
    res[dr + 1] -= val;
}
void precalc()
{
    int i;
    for (i = 1;i <= n;i++)
        res[i] += res[i - 1];
}
void op2()
{
    g<<res[poz] + v[poz]<<'\n';
}
int main()
{
    int i;
    f>>n>>nrOp1>>nrOp2;
    for (i = 1;i <= n;i++)
        f>>v[i];
    for (i = 1;i <= nrOp1;i++)
    {
        f>>st>>dr>>val;
        op1();
    }
    precalc();
    for (i = 1;i <= nrOp2;i++)
    {
        f>>poz;
        op2();
    }
}