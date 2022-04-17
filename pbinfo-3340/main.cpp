#include <fstream>
#include <math.h>
#include <algorithm>
using namespace std;
ifstream in("perfect1.in");
ofstream out("perfect1.out");
int main() {
    int pisi[5] = {0, 8128, 496, 28, 6};
    int n, v[101];
    in >> n;
    for (int i = 1; i <= n; i++)
        in >> v[i];
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
        	if (v[i] > v[j])
        		swap(v[i], v[j]);
    for (int k = 1; k <= 4; k++) {
        int temp = pisi[k];
        for (int j = n; j >= 1; j--) {
            int var = pisi[k];
            for (int i = j; i >= 1; i--)
                   if (v[i])
                if (var % v[i] == 0)
                    var = var / v[i];
            temp = min(var, temp);
        } if (temp == 1) {
            out << pisi[k];
            return 0;
        }
    } out << "NU";
}