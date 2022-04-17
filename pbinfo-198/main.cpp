#include <fstream>
using namespace std;
ifstream in("submultimi.in");
ofstream out("submultimi.out");
int x[10], n;
void back(int k) {
    for (int i = x[k - 1] + 1; i <= n; ++i) {
        x[k] = i;
        for (int i = 1; i <= k; ++i)
        	out << x[i] << " ";
    	out << "\n";
        back(k + 1);
    }
} int main() {
    in >> n;
    back(1);
    return 0;
}
