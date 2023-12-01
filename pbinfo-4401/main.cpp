/*
    Problema: Hibrid
    Autor: Stud. Andrei Onut, Universitatea Yale, S.U.A.
*/

#include <fstream>

using namespace std;

ifstream f("hibrid.in");
ofstream g("hibrid.out");

using ll = long long;

typedef pair<int, int> Segment;
typedef pair<Segment, int> Road;

const int PMAX = 1e5;
const int VMAX = 3e5;

int C, P, N;
Road A[(PMAX + 10)];

int V[((VMAX + 1 + VMAX) + 10)];

void Read()
{
    f >> C >> P >> N;

    for (int i = 1; i <= P; ++i)
        f >> A[i].first.first >> A[i].first.second >> A[i].second;

    return;
}

int my_min(int a, int b)
{
    return ((a < b) ? a : b);
}
int my_max(int a, int b)
{
    return ((a > b) ? a : b);
}

void Solve()
{
    int last_X = 0, X = 0;

    for (int i = 1; i <= N; ++i)
    {
        f >> X;

        if (i > 1)
        {
            int l = my_min(last_X, X);
            int r = my_max(last_X, X);

            l = my_max(-VMAX, l), r = my_min(VMAX, r);

            if (l <= r)
                ++V[(l + VMAX)], --V[((r + 1) + VMAX)];
        }

        last_X = X;
    }

    for (int i = (-VMAX + 1); i <= VMAX; ++i)
        V[(i + VMAX)] += V[((i - 1) + VMAX)];

    return;
}

int main()
{
    Read();

    Solve();

    int ans_1 = -1;
    ll ans_2 = 0;

    for (int i = 1; i <= P; ++i)
    {
        int X = (A[i].first.first + VMAX);

        if (V[X] > 0)
        {
            if (ans_1 == -1)
                ans_1 = i;
            else if (V[X] > V[(A[ans_1].first.first + VMAX)])
                ans_1 = i;

            ans_2 += 1LL * V[X] * A[i].second;
        }
    }

    if (C == 1)
        g << ans_1;
    else
        g << ans_2;
    g << '\n';

    return 0;
} 