#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;
ifstream fin ("distantapunctsegment.in");
ofstream fout("distantapunctsegment.out");
int X1, Y1, X2, Y2, X3, Y3;
int det(int X1, int Y1, int X2, int Y2, int X3, int Y3) {
    return (X2-X1)*(Y3-Y1) - (X3-X1)*(Y2-Y1);
}
int distantaPuncte(int X1, int Y1, int X2, int Y2) {
    return (X1-X2)*(X1-X2) + (Y1-Y2)*(Y1-Y2);
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
int main() {
    fin>>X1>>Y1>>X2>>Y2>>X3>>Y3;
    int a = det(X1, Y1, X2, Y2, X3, Y3);
    if (a == 0) {
        if (punctPeSegment(X3, Y3, X2, Y2, X1, Y1)) {
            fout<<setprecision(2)<<fixed<< 0.0;
        } else {
            int d1 = distantaPuncte(X1, Y1, X2, Y2);
            int d2 = distantaPuncte(X1, Y1, X3, Y3);
            if (d1 < d2)
                fout<<setprecision(2)<<fixed<< (int)(sqrt(d1)*100)/100.0;
            else
                fout<<setprecision(2)<<fixed<< (int)(sqrt(d2)*100)/100.0;
        }
        return 0;
    }
    if (a < 0)
        a = -a;
    int d1 = distantaPuncte(X2, Y2, X3, Y3);
    int d2 = distantaPuncte(X1, Y1, X3, Y3);
    int d3 = distantaPuncte(X2, Y2, X1, Y1);
    if (d2 < d1 + d3 && d3 < d1 + d2) {
        double h = a/sqrt(d1);
        fout<<setprecision(2)<<fixed<< (int)(h*100)/100.0;
    } else {
        int d1 = distantaPuncte(X1, Y1, X2, Y2);
        int d2 = distantaPuncte(X1, Y1, X3, Y3);
        if (d1 < d2)
            fout<<setprecision(2)<<fixed<< (int)(sqrt(d1)*100)/100.0;
        else
            fout<<setprecision(2)<<fixed<< (int)(sqrt(d2)*100)/100.0;
    }
    return 0;
}