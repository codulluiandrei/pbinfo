#include <fstream>
using namespace std;
int n, temp, minim = 2000000001, maxim = -2000000001, inc, sf;
long long S;
ifstream in("memory002.in");
ofstream out("memory002.out");
ifstream in2("memory002.in");
int main() {
    in >> n;
    for (int i = 1; i <= n; i++) {
        in >> temp;
        if (temp < minim) {
            inc = i;
            minim = temp;
        } if(temp > maxim) {
            sf = i;
        	maxim = temp;
        }
    } in2 >> n;
    if (inc > sf) {
    	temp = inc;
    	inc = sf;
    	sf = temp;
    } for (int i = 1; i < inc; ++i)
        in2 >> temp;
    for (int i = inc; i <= sf; ++i) {
        in2 >> temp;
        S = S + temp;
    } out << S;
    return 0;

}
