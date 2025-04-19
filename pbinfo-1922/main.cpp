#include <fstream>
using namespace std;
#define ll long long
ll x, ind, a[100002], nr;
char s[100002];
int main()
{
    ifstream cin("nmod25.in");
    ofstream cout("nmod25.out");
    cin >> x;
    ll aux = x, d2 = 1 << x, d5 = 1;
    while (aux)
        d5 *= 5, aux--;
    while (cin >> s[++ind])
        a[ind] = s[ind] - 48;
    cin.close();
    for (int i = ind - x; i < ind; i++)
        nr = nr * 10 + a[i];
    if (nr % d2)
        cout << "NU\n";
        else cout << "DA\n";
    if (nr % d5)
        cout << "NU\n";
        else cout << "DA\n";
    cout.close();
    return 0;
}