#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;


int countWays(int n) {
    int ret = 0;
    int N = n * 2;
    for (int m = 2; m * m <= 2 * n; m++) {
        if (m % 2 == 0) {
            // n/m + 1/2 integer
            if ((N + m) % (m * 2) == 0) {
                ret++;
            }
        } else {
            // n / m integer
            if (n % m == 0) {
                ret++;
            }
        }
    }
    return ret;
}

vector<int> getWays(int n) {
    vector<int> ret;
    int N = n * 2;
    for (int m = 2; m * m <= 2 * n; m++) {
        if (m % 2 == 0) {
            // n/m + 1/2 integer
            if ((N + m) % (m * 2) == 0) {
                ret.push_back(m);
            }
        } else {
            // n / m integer
            if (n % m == 0) {
                ret.push_back(m);
            }
        }
    }
    return ret;
}

pair<int, vector<int> > solve(int n) {
    const int amax = int(1e6);
    for (int i = 1; i <= amax; i++) {
        int num = countWays(i);
        if (num == n) {
            return make_pair(i, getWays(i));
        }
    }
    return make_pair(-1, vector<int>());
}


int main() {
    ifstream cin("consecutive.in");
    ofstream cout("consecutive.out");
    int n;
    cin >> n;
    pair<int, vector<int> > ans = solve(n);
    cout << ans.first << "\n";
    for (int& x : ans.second) {
        cout << x << "\n";
    }
    return 0;
}

