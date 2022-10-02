#include <iostream>
using namespace std;
bool pre(int n) {
    int ptr = n * n, cub = n * n * n;
    int a[11] = {0}, b[11] = {0};
    while (ptr > 0) {
        a[ptr % 10] = 1;
        ptr = ptr / 10;
    } while (cub > 0) {
        b[cub % 10] = 1;
        cub = cub / 10;
    } for (int i = 0; i <= 9; i++)
        if (a[i] == 1 && b[i] == 1)
            return false;
    return true;
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        if (pre(i))
            cout << i << " ";
    return 0;
}