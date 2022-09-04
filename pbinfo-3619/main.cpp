#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    for (int i = 1000; i < 10000; i++) {
        if (i / 1000 % 10 >= a)
            if (i / 10 % 10 <= b)
                if ((i % 10 == i / 100 % 10) && i % 2 == 0)
                    cout << i << "\n";
    } return 0;
}