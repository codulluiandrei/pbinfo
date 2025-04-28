#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;
ifstream fin ("distantapunctdreapta.in");
ofstream fout("distantapunctdreapta.out");
int X1, Y1, X2, Y2, X3, Y3;
int det(int X1, int Y1, int X2, int Y2, int X3, int Y3) {
    return (X2-X1)*(Y3-Y1) - (X3-X1)*(Y2-Y1);
}
int distantaPuncte(int X1, int Y1, int X2, int Y2) {
    return (X1-X2)*(X1-X2) + (Y1-Y2)*(Y1-Y2);
}
int main() {
    fin>>X1>>Y1>>X2>>Y2>>X3>>Y3;
    int a = det(X1, Y1, X2, Y2, X3, Y3);
    if (a < 0)
        a = -a;
    int d = distantaPuncte(X2, Y2, X3, Y3);
    double h = a/sqrt(d);
    fout<<setprecision(2)<<fixed<< (int)(h*100)/100.0;
    return 0;
}