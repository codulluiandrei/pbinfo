#include <bits/stdc++.h>
using namespace std;

class InParser
{

private:
    FILE *fin;
    char *buff;
    int sp;

    char read_ch()
    {
        ++sp;
        if (sp == 4096)
        {
            sp = 0;
            fread(buff, 1, 4096, fin);
        }
        return buff[sp];
    }

public:
    InParser(const char *nume)
    {
        fin = fopen(nume, "r");
        buff = new char[4096]();
        sp = 4095;
    }

    InParser &operator>>(int &n)
    {
        char c;
        while (!isdigit(c = read_ch()) && c != '-')
            ;
        int sgn = 1;
        if (c == '-')
        {
            n = 0;
            sgn = -1;
        }
        else
        {
            n = c - '0';
        }
        while (isdigit(c = read_ch()))
        {
            n = 10 * n + c - '0';
        }
        n *= sgn;
        return *this;
    }
};

const int NMAX = 1000005;

int N;
int aib[NMAX];

inline int lsb(int x)
{
    return x & (-x);
}

void update(int pos, int val)
{
    for (; pos <= N; pos += lsb(pos))
        aib[pos] += val;
}

int query(int pos)
{
    int r = 0;
    for (; pos; pos -= lsb(pos))
        r += aib[pos];
    return r;
}

int main()
{
    InParser cin("izi.in");
    ofstream cout("izi.out");

    int T;
    cin >> T;
    N = T + 2;
    int curr = N - 1;
    while (T--)
    {
        int op;
        cin >> op;
        if (op == 0)
        {
            int x;
            cin >> x;
            update(curr, x);
            update(curr + 1, -x);
            curr--;
            cout << x << '\n';
        }
        else if (op == 1)
        {
            int a, b, plus;
            cin >> a >> b >> plus;
            update(N - b, plus);
            update(N - a + 1, -plus);
            cout << query(curr + 1) << '\n';
        }
        else
        {
            int val = query(curr + 1);
            update(curr + 1, -val);
            update(curr + 2, val);
            curr += 1;
            cout << query(curr + 1) << '\n';
        }
    }

    return 0;
} 