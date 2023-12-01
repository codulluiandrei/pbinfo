#include <iostream>

using namespace std;

int main()
{
    int n, v[200001], currpos = 0, i, j, x;
    bool stiva[200001]{};

    cin >> n;
    for(i = 0; i < n; ++i)
        cin >> v[i];

    for(i = 0; i < n; ++i)
    {
        cin >> x; j = currpos;

        if(!stiva[x])
        {
            j = currpos;
            while(v[j] != x) { stiva[v[j]] = true; ++j; }
            cout << j - currpos + 1;
            currpos = j + 1;
        }
        else cout.put('0');

        cout.put(' ');
    }
    return 0;
}
