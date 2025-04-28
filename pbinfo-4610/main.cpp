//100, Gabor Ioana
#include <bits/stdc++.h>
#define NMAX 1000
#define MOD 1000000007
using namespace std;
ifstream fi("poseidon.in");
ofstream fo("poseidon.out");
int N, M, mat[NMAX+2][NMAX+2];
bool viz[NMAX+2][NMAX+2];
int task;
queue<pair<int,int>> q;
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
int derangements[NMAX*NMAX+1];
int perm[11], used[11];
void read() {
    fi>>task;
    fi>>N>>M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            fi>>mat[i][j];
        }   
    }
}
void computeDerangements() { //precalcularea numarului de permutari fara puncte fixe
    derangements[0] = 1;
    derangements[1] = 0;
    for(int i=2;i<=N*M;i++) {
        derangements[i] = (1LL*(i-1) * (derangements[i-1] + derangements[i-2]))%MOD;
    }
}
void initialize() {
    for(int i=0;i<=N+1;i++) {
        viz[i][0] = viz[i][M+1] = 1;
    }
    for(int i=0;i<=M+1;i++) {
        viz[0][i] = viz[N+1][i] = 1;
    }
    computeDerangements();
}
int getNumberOfTreasuresFromIsland(int xStart, int yStart) { // flood fill
    int countTreasures = 0;
    q.push({xStart, yStart});
    viz[xStart][yStart] = 1;
    int xC, yC, xN, yN;
    while(!q.empty()) {
        xC = q.front().first;
        yC = q.front().second;
        if (mat[xC][yC]>0) {
            countTreasures++;
        }
        q.pop();
        for(int d=0;d<4;d++) {
            xN = xC+dx[d];
            yN = yC+dy[d];
            if (!viz[xN][yN] &&mat[xN][yN] !=-1) {
                viz[xN][yN] = 1;
                q.push({xN, yN});
            }
        }
    }
    return countTreasures;
}
void solveTask1() {
    int xStart, yStart;
    fi>>xStart>>yStart;
    fo<<getNumberOfTreasuresFromIsland(xStart, yStart)<<'\n';
}
void solveTask2() {
    int sol = 1;
    int currentNbOfTreasures;
    int maxnb = 0;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if (!viz[i][j] && mat[i][j]!=-1) {
                currentNbOfTreasures = getNumberOfTreasuresFromIsland(i,j);
                maxnb = max(maxnb, currentNbOfTreasures);
                sol = (1LL * sol * derangements[currentNbOfTreasures]) % MOD;
            }
        }   
    }    
    fo<<sol<<'\n';
}
int main() {
    read();
    initialize();
    if (task == 1) {
        solveTask1();
    } else {
        solveTask2();
    }
    fi.close();
    fo.close();
} 