#include <bits/stdc++.h>
using namespace std;
const string folderPath = "";
const string in_fileName = "findmin.in";
const string in_filePath = folderPath + in_fileName;
const string out_fileName = "findmin.out";
const string out_filePath = folderPath + out_fileName;
ifstream f(in_filePath);
ofstream g(out_filePath);
#define pb push_back
#define ll long long
#define mp make_pair
const int NMAX = 1000000;
const int nmax = 1e6 + 5;
int n, p[nmax], marcat[nmax], sol[nmax], pos[nmax];
int main() {
    f >> n;
    for (int i = 1; i <= n; ++i) {
        f >> p[i];
        pos[p[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        marcat[p[i]] = 1;
        for (int j = p[i] + 1; j <= n; ++j) {
            if (marcat[j]) {
                break;
            }
            sol[ pos[j] ] = i;
            marcat[ j ] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (sol[i] == 0) {
            sol[i] = -1;
        }
        g << sol[i] << " ";
    }
    g << "\n";
    return 0;
}