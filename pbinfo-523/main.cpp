#include <iostream>
using namespace std;
int main() {
    int n, x[1005];
    cin  >> n;  
    for (int i = 1 ; i <= n ; ++ i)
        cin >> x[i];
    int st = 0, dr = 0;
    for (int i = 1 ; i <= n ; ++i) {
        int j = i + 1;
        while (j <= n && x[j] == x[i])
            j ++;
        if (j - i >= dr - st + 1)
            st = i, dr = j - 1;
        i = j - 1;
    } cout << st << " " << dr;
    return 0;
}