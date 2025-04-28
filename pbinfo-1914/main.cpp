#include <fstream>
using namespace std;
ifstream cin("rica.in");
ofstream cout("rica.out");
int lg[10], v[10][100000], i, x, c_x;
void muta(int in_cn, int din_cn)
{
    int i;
    for(i=1; i <= lg[din_cn]; i++)
        v[in_cn][i] = v[din_cn][i];
    lg[in_cn] = lg[din_cn];
}
void suma()
{
    int i;
    for(i=1; i <= lg[3]; i++)
    {
        v[4][i] = v[3][i] + v[2][i] + v[1][i];
    }
    for(i=1; i <= lg[3] || v[4][i] != 0; i++)
    {
        v[4][i+1] += v[4][i] / 10;
        v[4][i] %= 10;
    }
    lg[4] = i-1;
}
void fa(int x)
{
    int i;
    for(i=4; i <= x; i++)
    {
        suma();
        muta(1, 2);
        muta(2, 3);
        muta(3, 4);
    }
    for(i=lg[4]; i > 0; i--)
    {
        cout << v[4][i];
    }
    cout << "\n";
}
int main()
{
    cin >> x;
    c_x = x;
    if(x == 1 || x == 2)
    {
        cout << 1;
        return 0;
    }
    if(x == 3)
    {
        cout << 2;
        return 0;
    }
    v[1][1] = 1;
    v[2][1] = 1;
    v[3][1] = 2;
    lg[1] = 1;
    lg[2] = 1;
    lg[3] = 1;
    fa(x);
}