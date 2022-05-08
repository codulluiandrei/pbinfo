#include<fstream>
#define MAXIM 1000000
using namespace std;
ifstream in("minimdoua.in");
ofstream out("minimdoua.out");
int main() {
    int n, minim1 = MAXIM + 10, minim2 = MAXIM + 10;
    in >> n;
    for (int i = 1; i <= n; i++) {
        int temp; in >> temp;
        if (temp >= 10 && temp % 10 == temp / 10 % 10) {
            if (temp < minim1) {
                minim2 = minim1;
                minim1 = temp;
            } else if (temp < minim2) {
                minim2 = temp;
            }
        }
    } if (minim2 <= MAXIM)  out << minim1 << " " << minim2;
   	else out << "numere insuficiente";
	return 0;
}
