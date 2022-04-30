#include <fstream>
#include <math.h>
using namespace std;
ifstream in("elempp.in");
ofstream out("elempp.out");
int main() {
	int n; in >> n;
    for (int i = 1; i <= n; ++i) {
    	int temp; in >> temp;
        int copie = temp;
        while (temp >= 100) temp = temp / 10;
        if (sqrt((int) temp) == (int) sqrt((int) temp))
            out << copie << " ";
    } return 0;
}