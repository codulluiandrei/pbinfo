#include <iostream>
using namespace std;
int h[100003], k;
void Coboara(int p) /// O(log n)
{
    int fiu;
    while (p <= k / 2)
    {
        fiu = 2 * p;
        if (fiu + 1 <= k && h[fiu + 1] < h[fiu])
            fiu++;
        if (h[p] <= h[fiu]) return;
        swap(h[p], h[fiu]);
        p = fiu;
    }
}
/// Functie care organizeaza vectorul h[]
/// ca un min-heap
void MakeHeap()
{
    for (int i = k / 2; i >= 1; i--)
        Coboara(i);
}
void Citire()
{
    int i, n, A, B, C, D;
    cin >> n >> k >> A >> B >> C >> D;
    h[1] = A;
    for (i = 2; i <= k; i++)
    {
        A = (1LL * B * A + C) % D;
        h[i] = A;
    }
    MakeHeap();
    for (i = k + 1; i <= n; i++)
    {
        A = (1LL * B * A + C) % D;
        if (A > h[1])
        {
            h[1] = A;
            Coboara(1);
        }
    }
}
void Afisare()
{
    while (k > 1)
    {
        cout << h[1] << " ";
        h[1] = h[k];
        k--;
        Coboara(1);
    }
    cout << h[1] << "\n";
}
int main()
{
    Citire();
    Afisare();
    return 0;
}