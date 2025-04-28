// Mihai Enache
#include <iostream>
#include <fstream>
using namespace std;
const int MAX_N = 1002;
int N, M, xs, ys;
int A[MAX_N][MAX_N], cx[MAX_N], cy[MAX_N], startX[MAX_N], endX[MAX_N], startY[MAX_N], endY[MAX_N];
void computeCostForCoordinate(int n, int c[], int startHere[], int endHere[]) {
    int toRight = 0;
    int toLeft = 0;
    for(int i = 2; i <= n; ++i) {
        c[1] += (i - 1) * startHere[i];
        toRight += startHere[i];
    }
    for(int i = 2; i <= n; ++i) {
        toLeft += endHere[i - 1];
        c[i] = c[i - 1] - toRight + toLeft;
        toRight -= startHere[i];
    }
}
int main() {
	ifstream cin("arhipelag.in");
    ofstream cout("arhipelag.out");
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= M; ++j) {
            cin >> A[i][j];
        }
    }
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= M; ++j) {
            if(A[i][j] == 1) {
                int xl = i;
                int xr = i;
                while(A[xr + 1][j]) {
                    ++xr;
                }
                int yl = j;
                int yr = j;
                while(A[i][yr + 1]) {
                    ++yr;
                }
                for(int k = xl; k <= xr; ++k) {
                    for(int h = yl; h <= yr; ++h) {
                        A[k][h] = -1;
                    }
                }
                ++startX[xl];
                ++endX[xr];
                ++startY[yl];
                ++endY[yr];
            }
        }
    }
    computeCostForCoordinate(N, cx, startX, endX);
    computeCostForCoordinate(M, cy, startY, endY);
    int bestTotalDistance = 0x3f3f3f3f;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= M; ++j) {
            if(!A[i][j] && cx[i] + cy[j] < bestTotalDistance) {
                bestTotalDistance = cx[i] + cy[j];
                xs = i;
                ys = j;
            }
        }
    }
    cout << xs << " " << ys << "\n";
    // printf("Best total disance = %d
", bestTotalDistance);
    return 0;
}