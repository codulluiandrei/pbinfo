#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream f("sir147.in");
    ofstream g("sir147.out");
    int x;
    while(f>>x)
    if(x%3==1)
        g<<x<<" ";
    return 0;
}