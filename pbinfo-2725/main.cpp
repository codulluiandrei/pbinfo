/**
Solutie O(n log n) - arbori indexati binar
*/
#include <iostream>
using namespace std;
int aib[100005], n;
void Update(int i)
{
    for ( ; i <= n; i = i + (i & (-i)))
        aib[i]++;
}
int Query(int i)
{
    int s;
    for (s = 0; i > 0; i = i - (i & (-i)))
        s += aib[i];
    return s;
}
int main()
{
    int i, x;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> x;
        cout << Query(x - 1) << " ";
        Update(x);
    }
    return 0;
}