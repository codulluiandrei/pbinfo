#include <iostream>
using namespace std;
int main() {
    int nrd = -1, maxim, minim;
    int val, a, b, temp, nr;
    cin >> a >> b;
    if (a % 2 == 1) a++;
    for (int i = a; i <= b; i = i + 2) {
        nr = 0;
        int aux = 0, j = i;
        while (j % 2 == 0) j = j / 2, aux++;
        for (val = 1; val * val < j; val = val + 2) 
            if (i % val == 0)
                nr = nr + 2;
        if (val * val == i) nr ++;
        nr = nr * aux;
        if (nr > nrd) {
            nrd = nr;
            minim = maxim = i;
            temp = 1;
        }
        else if (nr == nrd) {
            maxim = i;
            temp++;
        }
    } cout << nrd << " " << minim << " " << maxim;
    return 0;
}