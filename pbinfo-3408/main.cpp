#include <fstream>
using namespace std;
ifstream in("joc2020.in");
ofstream out("joc2020.out");
int v[1000002];
int main() {
    int n, temp;
    v[1] = 1;
    for (int i = 2; i <= 1000000; i++) {
    	v[i] = 2;
    } for (int i = 2; i * i <= 1000000; i++) {
    	v[i * i]++;
        for (int j = i + 1; j * i <= 1000000; j++) {
        	v[i * j] = v[i * j] + 2;
        }
    } in >> n;
    for (int i = 1; i <= n; i++) {
        in >> temp;
        out << v[temp] << " ";
    } return 0;
}
