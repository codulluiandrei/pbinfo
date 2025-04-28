#include <fstream>
#include <iomanip>
#include <cmath>
#define PI 3.141592
using namespace std;
ifstream f("ceas.in");
ofstream g("ceas.out");
int r,hr,mn;
double xz, yz, x, y;
int main()
{
    f >> r >> hr >> mn;
    x = 0; y = r;
    mn = mn + hr * 60;
    double rad = 1.0 * 2 * mn * PI / 720;
    xz = x * cos(rad) + y * sin(rad);
    yz = -x * sin(rad) + y * cos(rad);
    g << fixed << setprecision(3) << xz << ' ' << yz << '\n';
    return 0;
}