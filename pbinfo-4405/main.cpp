/*
Raluca Costineanu, Colegiul National Stefan cel Mare Suceava
*/
#include <fstream>
using namespace std;
ifstream f("unificare.in");
ofstream g("unificare.out");
const int N = 100005;
int main()
{
    int C, n, k, i, x;
    f >> C >> n >> k;
    if (C == 1)
    {
        int mx = 0;
        for (i = 1; i <= n; i++)
        {
            f >> x;
            int cx = x, nrcif = 0;
            do
                nrcif++, cx /= 10;
            while (cx);
            if (x > mx && nrcif == k)
                mx = x;
        }
        g << mx << '\n';
    }
    else if (C == 2)
    {
        int y, cx, cy;
        long long nr, mx = 0;
        f >> x;
        for (int i = 2; i <= n; i++)
        {
            f >> y;
            nr = 0;
            for (int c = 9; c >= 0; c--)
            {
                bool okX = 0, okY = 0;
                cx = x; cy = y;
                do
                {
                    if (cx % 10 == c)
                    {
                        okX = 1; break;
                    }
                    cx /= 10;
                } while (cx);
                do
                {
                    if (cy % 10 == c)
                    {
                        okY = 1; break;
                    }
                    cy /= 10;
                } while (cy);
                if (okX)nr = nr * 10 + c;
                if (okY)nr = nr * 10 + c;
            }
            if (nr > mx)mx = nr;
            x = y;
        }
        g << mx << '\n';
    }
    else if (C == 3)
    {
        int v[N], frMx[10] = {}, frK[10] = {};
        for (i = 1; i <= n; i++)
            f >> v[i];
        for (i = 1; i <= k; i++)
        {
            int fr[10] = {}, x = v[i];
            do
                fr[x % 10] = 1, x /= 10;
            while (x);
            for (int c = 0; c <= 9; c++)
                frK[c] += fr[c];
        }
        for (int c = 0; c <= 9; c++)
            frMx[c] = frK[c];
        for (i = k + 1; i <= n; i++)
        {
            int fr[10] = {}, x = v[i];
            do
                fr[x % 10] = 1, x /= 10;
            while (x);
            for (int c = 0; c <= 9; c++)
                frK[c] += fr[c];
            int fri[10] = {}, y = v[i - k];
            do
                fri[y % 10] = 1, y /= 10;
            while (y);
            for (int c = 0; c <= 9; c++)
                frK[c] -= fri[c];
            int sMX = 0, sK = 0, cmp = 0;
            for (int c = 0; c <= 9; c++)
                sMX += frMx[c], sK += frK[c];
            if (sK > sMX) cmp = 1;
            else if (sK < sMX) cmp = -1;
            else
            {
                for (int c = 9; c >= 0; c--)
                    if (frK[c] > frMx[c])
                    {
                        cmp = 1; break;
                    }
                    else if (frK[c] < frMx[c])
                    {
                        cmp = -1; break;
                    }
            }
            if (cmp > 0)
                for (int c = 0; c <= 9; c++)
                    frMx[c] = frK[c];
        }
        for (int c = 9; c >= 0; c--)
            while (frMx[c])
                g << c, frMx[c]--;
        g<<'\n';
    }
    return 0;
}