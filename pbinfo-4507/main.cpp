#include <iostream>
using namespace std;
int n,i,a,j;
long long v[1000003], nr;
int main()
{
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> a;
        v[a]++;
    }
    for(i = 1; i <= 1000000; i++)
    {
        nr += v[i]*(v[i]-1);
        j = i+i;
        while(j <= 1000000)
        {
            nr += v[i]*v[j];
            j = j+i;
        }
    }
    cout << nr;
    return 0;
}