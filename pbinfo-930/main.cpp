#include <fstream>
#include <stdlib.h>
using namespace std;
ifstream fin ("intersectiesegmente.in");
ofstream fout("intersectiesegmente.out");
int X1, Y1, X2, Y2, X3, Y3, X4, Y4;
int d1, d2, d3, d4;
int det(int X1, int Y1, int X2, int Y2, int X3, int Y3) {
    return (X2-X1)*(Y3-Y1) - (X3-X1)*(Y2-Y1);
}
int punctPeSegment(int x1, int y1, int x2, int y2, int x3, int y3) {
    int d = det(x1, y1, x2, y2, x3, y3);
    if (d!=0)
        return 0;
    if (x1 == x3 && y1 == y3)
        return 1;
    if (x2 == x3 && y2 == y3)
        return 1;
    if ((x3-x1) * (x3-x2) < 0 || (y3-y1) * (y3-y2) < 0)
        return 1;
    else
        return 0;
}
void msgAndOut(char *msg) {
    fout<<msg;
    exit(0);
}
int main() {
    fin>>X1>>Y1>>X2>>Y2>>X3>>Y3>>X4>>Y4;
    if (punctPeSegment(X1, Y1, X2, Y2, X3, Y3)) {
        msgAndOut("DA
");
    }
    if (punctPeSegment(X1, Y1, X2, Y2, X4, Y4)) {
        msgAndOut("DA
");
    }
    if (punctPeSegment(X3, Y3, X4, Y4, X1, Y1)) {
        msgAndOut("DA
");
    }
    if (punctPeSegment(X3, Y3, X4, Y4, X2, Y2)) {
        msgAndOut("DA
");
    }
    d1 = det(X3, Y3, X4, Y4, X1, Y1);
    d2 = det(X3, Y3, X4, Y4, X2, Y2);
    d3 = det(X1, Y1, X2, Y2, X3, Y3);
    d4 = det(X1, Y1, X2, Y2, X4, Y4);
    if (d1 * d2 < 0 && d3 * d4 < 0)
        msgAndOut("DA
");
    else
        msgAndOut("NU
");
    return 0;
}