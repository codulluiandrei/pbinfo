# include <iostream>
using namespace std;
int x, crt, ant, p_ind, u_ind;
int main()
{
    ///ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> x;
    p_ind = u_ind = -1;
    while ( cin >> crt )
    {
        if (ant % 10000 == x && crt % 10000 == x)
        {
            p_ind = ant / 10000;
            u_ind = crt / 10000;
        }
        ant = crt;
    }
    if (p_ind == -1) cout << "nu exista";
                else cout << p_ind << " " << u_ind;
    return 0;
}