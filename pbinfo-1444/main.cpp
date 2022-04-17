#include <fstream>
using namespace std;
ifstream in("memory001.in");
ofstream out("memory001.out");
long long v[1001], n, m, minim = 2000000000000, col, temp;
int main() {
    in >> m >> n ;
    for (int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++) {
        in >> temp;
        v[j] = v[j] + temp;
    } for (int i = 1; i <= n; i++)
        if (v[i] < minim) {
        	minim = v[i]; 
        	col = i;
    } out << col;
    return 0;
}