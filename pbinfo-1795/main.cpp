#include <fstream>
#include <queue>
using namespace std;
bool okay (unsigned short int i, unsigned short int j);
unsigned short int N, M, K;
unsigned short int X1, Y1, X2, Y2;
unsigned short int XY, YY, XB, YB;
unsigned short int X[14001], Y[14001];
queue < pair <unsigned short int, unsigned short int> > Q;
const short int dx[] = {-1, -1,  0,  1,  1,  1,  0, -1};
const short int dy[] = { 0,  1,  1,  1,  0, -1, -1, -1};
short int matrix[1001][1001];
unsigned short int i, j, k, nextI, nextJ;
unsigned short int D;
int main ()
{
    ifstream fin ("gigelajungeacasa.in");
    fin >> N >> M >> K;
    fin >> X1 >> Y1 >> X2 >> Y2;
    fin >> XY >> YY >> XB >> YB;
    for (i=1; i<=K; i++)
        fin >> X[i] >> Y[i];
    fin.close();
    matrix[XY][YY] = -1;
    matrix[XB][YB] = -1;
    for (i=1; i<=K; i++)
        matrix[X[i]][Y[i]] = -1;
    Q.push(make_pair(X2,Y2));
    while (!Q.empty())
    {
        i = Q.front().first;
        j = Q.front().second;
        Q.pop();
        for (k=0; k<8; k++)
        {
            nextI = i + dx[k];
            nextJ = j + dy[k];
            if (okay(nextI,nextJ) == 1 && matrix[nextI][nextJ] == 0)
            {
                matrix[nextI][nextJ] = matrix[i][j] + 1;
                Q.push(make_pair(nextI,nextJ));
            }
        }
    }
    D = matrix[X1][Y1];
    ofstream fout ("gigelajungeacasa.out");
    fout << D;
    fout.close();
    return 0;
}
bool okay (unsigned short int i, unsigned short int j)
{
    if (i<1 || j<1 || i>N || j>M)
        return 0;
    return 1;
}