#include <iostream>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    n%=24;  // pentru ca sirul se repeta din 24 in 24
    int i=1;
    int j=1;
    for (int contor=3; contor<=n; contor++)
    {
        int k = i + j;
        i = j;
        j = k;
    }
    cout << (j % 9? j % 9 : 9); 
    return 0;
}