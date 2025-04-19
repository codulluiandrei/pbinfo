#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;
#define MAX1 20
#define MAX2 1 << 20
#define INFINIT 1E20
ifstream fin("smin.in");
ofstream fout("smin.out");
double s[MAX2];
int i, j, k, l, m, n, z; 
double tr;
struct Punct {
    int x, y;
} p[MAX1];
// dublul ariei triunghiului  
double Aria(Punct p1, Punct p2, Punct p3)
{
  return (p1.x - p2.x) * (p1.y + p2.y) + 
  	     (p2.x - p3.x) * (p2.y + p3.y) + 
         (p3.x - p1.x) * (p3.y + p1.y);
}
int main()
{
    fin >> n;
    for ( i = 0; i < n; i++ )
        fin >> p[i].x >> p[i].y; 
    m = 1 << n;
    s[0] = 0.0;
    for (i = 1; i < m; i++)
        s[i] = INFINIT;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            for (k = j + 1; k < n; k++)
                for (l = k + 1; l < n; l++)
                {
                    z = i | (1 << j) | (1 << k) | (1 << l);
                    tr = fabs (Aria(p[j], p[k], p[l]));
                    if (s[z] > s[i] + tr)
                      s[z] = s[i] + tr;
                }
   // fout << fixed << setprecision(3) << s[m-1] * 0.5 << '\n';
   fout << s[m-1] * 0.5 << '\n';
    fin.close();
    fout.close();  
    return 0;
}