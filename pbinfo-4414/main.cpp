#include <fstream>
using namespace std;
ifstream f("loto.in");
ofstream g("loto.out");
int cerinta, M, K, C, J;
int extrase[50], jucate[50], joc[50], cat[10];
int cat1(int joc[])
{
    int k = 0, i, j;
    for (i = 1; i <= K; ++i)
        for (j = 1; j <= K; ++j)
            if (joc[i] == extrase[j])
            {
                k++;
                break;
            }
    return k == K;
}
int cat2(int joc[])
{
    int k = 0, i, j;
    for (i = 1; i <= K; ++i)
        for (j = 1; j <= M; ++j)
            if (joc[i] == extrase[j])
            {
                k++;
                break;
            }
    return k == K;
}
int cat3(int joc[])
{
    int k = 0, i, j;
    for (i = 1; i <= K; ++i)
        for (j = 1; j <= K - 1; ++j)
            if (joc[i] == extrase[j])
            {
                k++;
                break;
            }
    return k == K - 1;
}
int cat4(int joc[])
{
    int k = 0, i, j;
    for (i = 1; i <= K; ++i)
        for (j = 1; j <= K; ++j)
            if (joc[i] == extrase[j])
            {
                k++;
                break;
            }
    return k == K - 1;
}
int cat5(int joc[])
{
    int k = 0, i, j;
    for (i = 1; i <= K; ++i)
        for (j = 1; j <= M; ++j)
            if (joc[i] == extrase[j])
            {
                k++;
                break;
            }
    return k == K - 1;
}
int cat6(int joc[])
{
    int k = 0, i, j;
    for (i = 1; i <= K; ++i)
        for (j = 1; j <= M; ++j)
            if (joc[i] == extrase[j])
            {
                k++;
                break;
            }
    return k == K - 2;
}
int categoria(int joc[])
{
    if (cat1(joc))return 1;
    if (cat2(joc))return 2;
    if (cat3(joc))return 3;
    if (cat4(joc))return 4;
    if (cat5(joc))return 5;
    if (cat6(joc))return 6;
    return 7;
}
int main()
{
    f >> cerinta >> M >> K >> C;
    for (int i = 1; i <= M; ++i) f >> extrase[i];
    f >> J;
    int i, j;
    if (cerinta == 2)
    {
        int x, i, mx = 0, j;
        for (i = 1; i <= J; ++i)
            for (j = 1; j <= K; ++j)
            {
                f >> x;
                jucate[x]++;
            }
        for (i = 1; i <= 49; ++i)
            mx = max(mx, jucate[i]);
        for (i = 1; i <= 49; ++i)
            if (mx == jucate[i])
                g << i << ' ';
        g << '\n';
    }
    else
    {
        for (i = 1; i <= J; ++i)
        {
            for (j = 1; j <= K; ++j)
            {
                f >> joc[j];
            }
            cat[categoria(joc)]++;
        }
        g << cat[C] << '\n';
    }
    return 0;
}