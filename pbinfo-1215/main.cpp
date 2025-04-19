#include <fstream>
#include <cctype>
using namespace std;
ifstream in("mesaj.in");
ofstream out("mesaj.out");
int majCounts[256];
int minCounts[256];
int maxCost[256];
int maxCostCounts[256];
int main() {
    int P;
    in >> P;
    int N;
    in >> N;
    int numSecvente = 0;
    int numSecventeCuCuvinte = 0;
    char ch = '#';
    int countCh = 1;
    char majCh = '#';
    char minCh = '#';
    for (int i = 0; i <= N; ++ i) {
        char peekCh;
        if (i < N) {
            in >> peekCh;
        } else {
            peekCh = '#';
        }
        if (ch == peekCh) {
            countCh ++;
        } else {
            switch (countCh) {
                case 1:
                    switch (P) {
                        case 1:
                            if (isupper(ch) && majCh == '#') majCh = ch;
                            if (islower(ch)) minCh = ch;
                            break;
                        case 2:
                            if (isupper(ch) && majCh == '#') majCh = ch;
                            if (islower(ch)) minCh = ch;
                            break;
                        case 3:
                            if (isupper(ch) && majCh == '#') majCh = ch;
                            if (islower(ch)) minCh = ch;
                            if (isupper(ch)) majCounts[ch] ++;
                            if (islower(ch)) minCounts[ch] ++;
                            break;
                    }
                    break;
                case 2:
                    switch(P) {
                        case 1:
                            numSecvente ++;
                            if (majCh != '#' && minCh != '#') numSecventeCuCuvinte ++;
                            majCh = minCh = '#';
                            break;
                        case 2:
                            if (majCh != '#' && minCh != '#') {
                                out << majCh << minCh << '\n';
                            }
                            majCh = minCh = '#';
                            break;
                        case 3:
                            if (isupper(ch)) majCounts[ch] += 2;
                            if (islower(ch)) minCounts[ch] += 2;
                            if (majCh != '#' && minCh != '#') {
                                int cost = majCounts[majCh] + minCounts[minCh];
                                if (cost > maxCost[majCh]) {
                                    maxCost[majCh] = cost;
                                    maxCostCounts[majCh] = 1;
                                } else if (cost == maxCost[majCh]) {
                                    maxCostCounts[majCh] ++;
                                }
                            }
                            majCh = minCh = '#';
                            for(int ii=0; ii<256;ii++) majCounts[ii]=0;
                            for(int ii=0; ii<256;ii++) minCounts[ii]=0;
                            break;
                    }
                    break;
                default:
                    switch (P) {
                        case 1:
                            numSecvente ++;
                            majCh = minCh = '#';
                            break;
                        case 2:
                            majCh = minCh = '#';
                            break;
                        case 3:
                            majCh = minCh = '#';
                            for(int ii=0; ii<256;ii++) majCounts[ii]=0;
                            for(int ii=0; ii<256;ii++) minCounts[ii]=0;
                            break;
                    }
            }
            countCh = 1;
            ch = peekCh;
        }
    }
    switch(P) {
        case 1:
            out << numSecvente - numSecventeCuCuvinte << '\n';
            break;
        case 3:
            for (char ch = 'A'; ch != 'Z'; ++ ch) {
                if (maxCost[ch]) {
                    out << ch << ' ' << maxCostCounts[ch] << '\n';
                }
            }
            break;
    }
    return 0;
}