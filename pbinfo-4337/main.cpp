#include <bits/stdc++.h>
using namespace std;
struct Triplet
{
    int val, ind, newval;
};
Triplet a[100002];
int n;
bool Compara1(Triplet A, Triplet B)
{
    return A.val < B.val;
}
bool Compara2(Triplet A, Triplet B)
{
    return A.ind < B.ind;
}
int main()
{
    int i;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i].val;
        a[i].ind = i;
    }
    sort(a + 1, a + n + 1, Compara1);
    a[1].newval = 1;
    for (i = 2; i <= n; i++)
        if (a[i].val == a[i - 1].val) a[i].newval = a[i - 1].newval;
        else a[i].newval = 1 + a[i - 1].newval;
    sort(a + 1, a + n + 1, Compara2);
    for (i = 1; i <= n; i++)
        cout << a[i].newval << " ";
    return 0;
}