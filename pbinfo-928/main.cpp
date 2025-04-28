#include <fstream>
#include <iomanip>
using namespace std;
int det(int X1, int Y1, int X2, int Y2, int X3, int Y3) {
    return (X2-X1)*(Y3-Y1) - (X3-X1)*(Y2-Y1);
}
ifstream fin("ariatriunghi.in");
ofstream fout("ariatriunghi.out");
int X1, Y1, X2, Y2, X3, Y3;
double modul(double x) {
    return x > 0 ? x : -x;
}
int main() {
    fin>>X1>>Y1>>X2>>Y2>>X3>>Y3;
    int t = det(X1, Y1, X2, Y2, X3, Y3);
    fout<<setprecision(1)<<fixed<<modul(t/2.0)<<"\n";
    return 0;
}