#include <iostream>
using namespace std;
int main() {
    int n, x, y, p, temp1, temp2;
    int totaly = 0, totalx = 0;
    cin >> n >> x >> y >> p;
    if (p == 1) {
        for (int i = 1; i <= n; i++) {
            cin >> temp1 >> temp2;
            totalx = totalx + temp1;
            totaly = totaly + temp2;
        } cout << totalx << " " << totaly << " " << totalx - totaly;
    } else {
        int total = 0;
        bool adv;
        for (int i = 1; i <= n; i++) {
            if (i == x) {
                if (total >= y) { adv = false; break; }
                else { adv = true; break; }
            } cin >> temp1 >> temp2;
            total = total + (temp1 - temp2);
        } if (adv) cout << "NU";
        else cout << "DA";
    } return 0;
}