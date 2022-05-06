#include <iostream>
using namespace std;
int main() {
    float a, b, c;
    cin >> a >> b >> c;
    if (a + b > c && a + c > b && b + c > a)
        if ((a == b && a != c) or (a == c && a != b) || (b == c && b != a)) cout << "Formeaza triunghi isoscel" << endl;
        else cout << "Nu formeaza triunghi isoscel" << endl;
    else cout << "Nu formeaza triunghi" << endl;
    return 0;
}