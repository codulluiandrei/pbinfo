#include <fstream>
#include <vector>
#define M 2500000000000000000
#define P 1000009
#define ll long long
using namespace std;
ifstream f("fibonacci3.in");
ofstream g("fibonacci3.out");
ll r, n, i, j, sol, suma, nr, t;
ll d[30], e[30];
vector<ll> ha[P];
void adaug_in_hash(ll x)
{
     r = x % P;
    ha[r].push_back(x);
}
void fibo_generator()
{
    ll a, b, c;
    a = 0;
    b = 1;
    adaug_in_hash(a);
    while(a + b <= M)
    {
        c = a + b;
        a = b;
        b = c;
        adaug_in_hash(c);
    }
}
int main()
{
    fibo_generator();
    f >> n;
    for(i = 1; i <= n; i++)
        f >> d[i];
    //calculez numarul submultimilor nevide
    nr = (1 << n) - 1;
    sol = 0;
    suma = 0;
    e[1] = 0;
    //generez submultimile si calculez dinamic suma elementelor
    for(i = 1; i <= nr; i++)
    {
        //adun 1 la nr binar din sirul e
        t = 1;
        j = 1;
        while(t == 1)
        {
            if(e[j]==1)
            {
                suma -= d[j];
                e[j] = 0;
            }
            else
            {
                e[j] = 1;
                suma += d[j];
                t = 0;
            }
            j++;
        }
        r = suma % P;
        for(j = 0; j < ha[r].size(); j++)
            if(suma == ha[r][j]) sol++;
    }
    g << sol;
    return 0;
}