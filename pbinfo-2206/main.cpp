#include <bits/stdc++.h>
using namespace std;
string S;
bool isBigger = false;
int main()
{
    cin >> S;
    for(auto it : S)
    {
        int c = it - '0';
        if(isBigger)
        {
            cout << 1;
            continue;
        }
        int nextc = c + !(c % 2);
        if(nextc > c)
            isBigger = true;
        cout << nextc;
    }
    cout << "\n";
    return 0;
}