#include <iostream>
using namespace std;

int n , v[1005];

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
        cin >> v[i];
    for(int i = 1 ; i < n ; i ++)
        for(int j = i + 1 ; j <= n ; j ++)
            if(v[i] > v[j])
            {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
    int x = 0;
    if(v[1] != 1)
        x = 1;
    for(int i = 1 ; i < n && x == 0 ; ++i)
        if(v[i+1] > v[i] + 1)
            x = v[i] + 1;
    if (x == 0)
            x = v[n] + 1;
    cout << x;
    return 0;
}
