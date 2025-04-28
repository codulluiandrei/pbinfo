/**
Solutie cu generare folosind inmultire de matrici
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <iterator>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#define x first
#define y second.first
#define z second.second
#define make_triple(a, b, c) make_pair(a, make_pair(b, c))
ifstream fin("agora.in");
ofstream fout("agora.out");
int x_1, y_1, x_0, y_0, ans;
int X, Y, K, i, j, xMax, yMax;
int mat[2500][2500];
vector<int> difX, difY;
vector<pair<int, int> > points;
queue<pair<int, pair<int, int> > > Q;
pair<int, pair<int, int> > crt, nxt;
bool isBounded(int a, int b) {
    if (abs(a) > X || abs(b) > Y)
        return false;
    return true;
}
int main()
{
    fin >> X >> Y >> K; /// Plane is 0 to X,Y
    Q.push(make_triple(3, 4, 5));
    while(!Q.empty()) {
        crt = Q.front(); Q.pop();
        if (crt.x <= X && crt.y <= Y) {
            points.push_back(make_pair(crt.x, crt.y));
            difX.push_back(crt.x);
            difY.push_back(crt.y);
        }
        if (crt.y <= X && crt.x <= Y) {
            points.push_back(make_pair(crt.y, crt.x));
            difX.push_back(crt.y);
            difY.push_back(crt.x);
        }
        nxt.x = -crt.x + 2 * crt.y + 2 * crt.z;
        nxt.y = -2 * crt.x + crt.y + 2 * crt.z;
        nxt.z = -2 * crt.x + 2 * crt.y + 3 * crt.z;
        if (isBounded(nxt.x, nxt.y)) {
            Q.push(nxt);
        }
        nxt.x = crt.x + 2 * crt.y + 2 * crt.z;
        nxt.y = 2 * crt.x + crt.y + 2 * crt.z;
        nxt.z = 2 * crt.x + 2 * crt.y + 3 * crt.z;
        if (isBounded(nxt.x, nxt.y)) {
            Q.push(nxt);
        }
        nxt.x = crt.x + -2 * crt.y + 2 * crt.z;
        nxt.y = 2 * crt.x + -crt.y + 2 * crt.z;
        nxt.z = 2 * crt.x + -2 * crt.y + 3 * crt.z;
        if (isBounded(nxt.x, nxt.y)) {
            Q.push(nxt);
        }
    }
    sort(difX.begin(), difX.end());
    sort(difY.begin(), difY.end());
    unique(difX.begin(), difX.end());
    unique(difY.begin(), difY.end());
    for(i = 0 ; i < points.size() ; i++) {
        mat[distance(difY.begin(), lower_bound(difY.begin(), difY.end(), points[i].second)) + 1][distance(difX.begin(), lower_bound(difX.begin(), difX.end(), points[i].first)) + 1] = 1;
    }
    xMax = difX.size();
    yMax = difY.size();
    for (i = 1 ; i <= xMax + 1 ; i++) {
        for (j = 1 ; j <= yMax + 1 ; j++) {
                mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
        }
    }
    for (i = 0 ; i < K ; i++) {
        fin >> x_1 >> y_1 >> x_0 >> y_0;
        x_1 = distance(difX.begin(), lower_bound(difX.begin(), difX.end(), x_1)) + 1;
        x_0 = distance(difX.begin(), upper_bound(difX.begin(), difX.end(), x_0));
        y_1 = distance(difY.begin(), upper_bound(difY.begin(), difY.end(), y_1));
        y_0 = distance(difY.begin(), lower_bound(difY.begin(), difY.end(), y_0)) + 1;
        ans = mat[x_0][y_1] - mat[x_0][y_0 - 1] - mat[x_1-1][y_1] + mat[x_1-1][y_0-1];
        fout << ans << '\n';
    }
    return 0;
}