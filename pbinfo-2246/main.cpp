#include <iostream>
#include <string.h>
using namespace std;
int n, i, nr, nra, nrd, nro, nrb, nre;
char a[100001], cc[6];
int main() {
    cin >> a;
    n = strlen(a);
    while (n >= 5) {
        strcpy(cc, a + (n - 5));
        nra = nrd = nro = nrb = nre = 0;
        for (i = 0; i <= 4; i++) {
            if (cc[i] == 'a'||cc[i] == 'A') nra = 1;
            if (cc[i] == 'd'||cc[i] == 'D') nrd = 1;
            if (cc[i] == 'o'||cc[i] == 'O') nro = 1;
            if (cc[i] == 'b'||cc[i] == 'B') nrb = 1;
            if (cc[i] == 'e'||cc[i] == 'E') nre = 1;
        } for (i = 0; i <= 4; i++) {
            if (cc[i] == '+') {
                if (nrd == 0) nrd = 1;
                else if (nrb == 0) nrb = 1;
            } if (cc[i] == '-') {
                if (nra == 0)
                	nra = 1;
                else {
                    if (nro == 0)
                    	nro = 1;
                    else if(nre == 0)
                    	nre = 1;
                }
            }
        } for (i = 0; i <= 4; i++) {
            if (cc[i] == '*') {
                if (nra == 0)
                	nra = 1;
                else {
                    if (nrd == 0)
                    	nrd = 1;
                    else {
                        if (nro == 0)
                        	nro = 1;
                        else {
                            if (nrb == 0)
                            	nrb = 1;
                            else if (nre == 0)
                            	nre = 1;
                        }
                    }
                }
            }
        } if (nra && nrd && nro && nrb && nre)
        	nr++;
        a[n - 1] = 0;
        n--;
    } cout << nr;
    return 0;
}