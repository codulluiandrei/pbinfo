#include <bits/stdc++.h>
using namespace std;
string prob = "tramvaie";
ifstream in(prob + ".in");
ofstream out(prob + ".out");
#define cin in
#define cout out
int N, euler[1000006];
int main() {
    for (int i = 1; i <= 1000006; ++i) euler[i] = i;
    for (int i = 2; i <= 1000006; ++i)
        if (euler[i] == i) {
            euler[i]--;
            for (int j = 2; j * i <= 1000006; ++j)
                euler[j * i] = euler[j * i] / i * (i - 1);
        }
    cin >> N;
    for (int n = 1; n <= N; ++n) {
        int temp; cin >> temp;
        cout << euler[temp] << " ";
    } return 0;
}
