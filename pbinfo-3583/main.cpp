#include <fstream>
using namespace std;
ifstream in("jetoane.in");
ofstream out("jetoane.out");
int N, M, minim, maxim;
int contor1, contor2;
int nr1[50002], nr2[50002];
int freq1[50002], freq2[50002];
bool adv = true;
int main () {
    in >> N >> M;
    for (int i = 0; i < N; i ++) {
        in >> nr1[i];
        freq1[nr1[i]] ++;
    } for (int i = 0; i < M; i ++) {
        in >> nr2[i];
        freq2[nr2[i]] ++;
    } for (int i = 0; i <= 50001; i ++)
        if (freq1[i] && freq2[i]) {
            if (adv == true) {
                adv = false;
                minim = i;
            } maxim = i;
    } out << minim << " " << maxim << " ";
    for (int i = 0; i < N; i ++)
        if (nr1[i] < minim || nr1[i] > maxim) contor1++;
        for (int i = 0; i < M; i ++)
        	if (nr2[i] < minim || nr2[i] > maxim) contor2++;
        if (contor1 > contor2) out << "1";
        else if (contor2 > contor1) out << "2";
        else out << "0";
	return 0;
}