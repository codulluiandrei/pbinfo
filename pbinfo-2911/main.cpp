#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int n;
    cin >> n;
    int vec[11], temp = 0;
    while (n) {
        vec[temp++] = n % 10;
        n = n / 10;
    }
    for (int i = temp - 1 ; i >= 0 ; i--) {
        if (vec[i] == 1) {
            cout << "  @\n"; cout << " @@\n"; cout << "  @\n"; cout << "  @\n"; cout << "@@@@@\n"; cout << endl;
        }
        if (vec[i] == 2) {
            cout << "@@@@\n"; cout << "@  @\n"; cout << "  @\n"; cout << " @\n"; cout << "@@@@\n"; cout << endl;
        }
        if (vec[i] == 3) {
            cout << "@@@@@\n"; cout << "    @\n"; cout << "@@@@@\n"; cout << "    @\n"; cout << "@@@@@\n"; cout << endl;
        }
        if(vec[i] == 4) {
            cout << "@   @\n"; cout << "@   @\n"; cout << "@@@@@\n"; cout << "    @\n"; cout << "    @\n"; cout << endl;
        }
        if (vec[i] == 5) {
            cout << "@@@@@\n"; cout << "@    \n"; cout << "@@@@@\n"; cout << "    @\n"; cout << "@@@@@\n"; cout << endl;
        }
        if (vec[i] == 6) {
            cout << "@@@@@\n"; cout << "@    \n"; cout << "@@@@@\n"; cout << "@   @\n"; cout << "@@@@@\n";cout << endl;
        }
        if (vec[i] == 7) {
            cout << "@@@@\n"; cout << "   @\n"; cout << "  @@@\n"; cout << "   @\n"; cout << "   @\n"; cout << endl;
        }
        if (vec[i] == 8) {
            cout << "@@@@@\n"; cout << "@   @\n"; cout << "@@@@@\n"; cout << "@   @\n"; cout << "@@@@@\n"; cout << endl;
        }
        if (vec[i] == 9) {
            cout << "@@@@@\n"; cout << "@   @\n"; cout << "@@@@@\n"; cout << "    @\n"; cout << "    @\n"; cout << endl;
        }
        if (vec[i] == 0) {
            cout << "@@@@@\n"; cout << "@   @\n"; cout << "@   @\n"; cout << "@   @\n"; cout << "@@@@@\n"; cout << endl;
        }
    } return 0;
}