#include <iostream>
using namespace std;
int main() {
    char carac;
    int rest, S = 0, temp, cat;
    cin >> temp;
    for (int i = 1; i <= temp; i++) {
        cin >> carac; 
        S = S + carac - '0';
    } rest = S % temp; cat = S / temp;
    for(int i = 1 ; i <= temp - rest; i++)
        cout << cat;
    cat++;
    for (int i = 1 ; i <= rest; i++)
        cout << cat;
    return 0;
}