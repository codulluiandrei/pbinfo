#include <fstream>
using namespace std;
fstream in("kcifra.in");
ofstream out("kcifra.out");
int main() {
    int k;
    in >> k;
    int c, nrcif = 0, nr;
    if (k <= 18)
        c = (k + 1) / 2;
    else if (k <= 288) {
            nr = 9; nrcif = 18;
            while (nrcif + 3 <= k) {
                    nrcif = nrcif + 3;
                nr++;
			} if (nrcif == k)
                c = nr % 10;
            else {
                nr++;
                if (nrcif + 1 == k) c = nr / 10;
                else c = nr % 10;
            }
        } else if (k <= 3888) {
                nr = 99; nrcif = 288;
                while (nrcif + 4 <= k) {
                    nrcif = nrcif + 4;
                    nr++;
                } if (nrcif == k)
                    c = nr % 10;
                else {
                    if (nrcif + 1 == k) c = nr / 100;
                    else c = nr / 10 % 10;
                }
            }
        else if (k <= 48888) {
                nr = 999; nrcif = 3888;
                while (nrcif + 5 <= k) {
                    nrcif = nrcif + 5;
                    nr++;
                } if (nrcif == k)
                    c = nr % 10;
                else {
                    if (nrcif + 1 == k)
                        c = nr / 1000;
                    else if (nrcif + 2 == k)
                        c = nr / 100 % 10;
                        else if (nrcif + 3 == k) 
                        	c = nr / 10 % 10;
                        else c = nr / 10 % 10;
                }
            }
    else {
        nr = 9999; nrcif = 48888;
        while (nrcif + 6 <= k) {
            nrcif = nrcif + 6;
            nr++;
        } if (nrcif == k)
            c = nr % 10;
        else {
            if (nrcif + 1 == k)
                c = nr / 10000;
            else if (nrcif + 2 == k)
                c = nr / 1000 % 10;
                else if (nrcif + 3 == k)
                	c = nr / 100 % 10;
                else if (nrcif + 4 == k)
                	c = nr / 10 % 10;
                else c = nr / 10 % 10;
		}
	} out << c << endl;
    return 0;
}