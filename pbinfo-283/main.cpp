#include <fstream>
using namespace std;
ifstream in("secventa.in");
ofstream out("secventa.out");
int main() {
    int n, v[100001], maxim, S, lungime = 1, temp = 1, inc = 1, sf = 1;
    in >> n;
    for (int i = 1; i <= n; ++i)
        in >> v[i];
    maxim = v[1], S = v[1];
    for (int i = 2; i <= n; ++i) {
        if (v[i] % 2 != v[i - 1] % 2) {
        	temp++;
            S = S + v[i];
        } else {
            if (temp > lungime) {
            	inc = i - temp;
            	sf = i - 1;
            	maxim = S;
            	lungime = temp;
            } else if (temp == lungime)
                if (S >= maxim) {
                	inc = i - temp;
                	sf = i - 1;
                	maxim = S;
                } temp = 1, S = v[i];
        }
    } if (temp > lungime) {
    	inc = n - temp + 1;
    	sf = n;
    	lungime = temp;
    	maxim = S;
    } else if (temp == lungime)
        if (S >= maxim) {
        	inc = n - temp + 1;
        	sf = n;
        	maxim = S;
        } out << inc << " " << sf;
    return 0;
}
