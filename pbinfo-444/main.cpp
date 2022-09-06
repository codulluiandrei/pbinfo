#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int  i = 0; i <= 9; i++) {
        bool adv = false;
        int temp = n;
        while (temp && !adv) {
            if (temp % 10 == i)
                adv = true;
            temp = temp / 10;
        } if (adv)
            cout << i << " ";
    } return 0;
}