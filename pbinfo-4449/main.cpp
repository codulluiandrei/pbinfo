#include <fstream>
using namespace std;
const int VMAX = 81;
int nr_a[1 + VMAX], nr_f[1 + VMAX], nr_b[1 + VMAX];
int main()
{
    ifstream in("patinaj.in");
    ofstream out("patinaj.out");
    int c, n;
    in >> c >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        in >> x;
        int sc = 0;
        do
        {
            sc += x % 10;
            x /= 10;
        }
        while (x != 0);
        nr_a[sc]++;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        in >> x;
        int sc = 0;
        do
        {
            sc += x % 10;
            x /= 10;
        }
        while (x != 0);
        nr_b[sc]++;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        in >> x;
        int sc = 0;
        do
        {
            sc += x % 10;
            x /= 10;
        }
        while (x != 0);
        nr_f[sc]++;
    }
    if (c == 1)
    {
        int nr = 0;
        for (int i = 0; i < VMAX; i++)
        {
            int minim = min(nr_a[i] + nr_a[i+1], nr_f[i] + nr_f[i+1]);
            minim = min(minim, nr_b[i] + nr_b[i+1]);
            nr += minim;
            if (minim > nr_a[i])
            {
                nr_a[i+1] -= min(nr_a[i+1], minim - nr_a[i]);
            }
            if (minim > nr_f[i])
            {
                nr_f[i+1] -= min(nr_f[i+1], minim - nr_f[i]);
            }
            if (minim > nr_b[i])
            {
                nr_b[i+1] -= min(nr_b[i+1], minim - nr_b[i]);
            }
        }
        nr += min(nr_a[VMAX], min(nr_f[VMAX], nr_b[VMAX]));
        out << nr << "\n";
    }
    else
    {
        int v_max_a = -1;
        long long nr_var = 0;
        for (int i = 0; i <= VMAX; i++)
        {
            if (nr_a[i] == 0)
            {
                continue;
            }
            bool exista_st = false, exista_dr = false;
            long long nr_st = 0, nr_dr = 0;
            if (i > 0 && nr_f[i] + nr_f[i-1] != 0 && nr_b[i] + nr_b[i-1] != 0)
            {
                exista_st = true;
                nr_st = (long long)(nr_f[i] + nr_f[i-1]) * (nr_b[i] + nr_b[i-1]);
            }
            if (i < VMAX && nr_f[i] + nr_f[i+1] != 0 && nr_b[i] + nr_b[i+1] != 0)
            {
                exista_dr = true;
                nr_dr = (long long)(nr_f[i] + nr_f[i+1]) * (nr_b[i] + nr_b[i+1]);
            }
            if (exista_st || exista_dr || (nr_f[i] != 0 && nr_b[i] != 0))
            {
                v_max_a = i;
                nr_var = (nr_st + nr_dr) * nr_a[i] - (long long)nr_a[i] * nr_f[i] * nr_b[i];
            }
        }
        out << v_max_a;
        if (v_max_a != -1)
        {
            out << " " << nr_var;
        }
        out << "\n";
    }
    in.close();
    out.close();
    return 0;
} 