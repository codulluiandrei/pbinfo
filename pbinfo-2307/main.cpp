//Radu Costache
#include <fstream>
#include <cstring>
#include <math.h>
using namespace std;
char s[35];
ofstream g("dec2ord.out");
unsigned long long cmmdc(unsigned long long a,unsigned long long b);
void simplifica(unsigned long long & a,unsigned long long & b);
unsigned long long lipire(unsigned long long a, int b);
inline void read();
inline void solve(int in, int zec, int per);
int main()
{
    read();
    return 0;
}
inline void read(){
    ifstream f("dec2ord.in");
    unsigned long long n,p1,p2,p3;
    f >> p1 >> p2 >> p3;
    solve(p1,p2,p3);
}
inline void solve(int in, int zec, int per){
    unsigned long long i = 0,p1 = 0,pt = 0,nrf = 0,numitor = 0,nrp = 0;
    if(zec != -1)
		p1 = lipire(in,zec);
	else p1 = in;
	if(per != -1)
	pt = lipire(p1,per);
	else pt = p1;
	if(zec != -1)
	nrf = log10(zec) + 1;
	if(per != -1)
	nrp = log10(per) + 1;
	for(i = 0 ; i < nrp ; ++i)
		numitor = numitor * 10 + 9;
	if(numitor == 0)numitor = 1;
	for(i = 0 ; i < nrf ; ++i)
		numitor = numitor * 10;
	if(pt != p1)
		pt -= p1;
    simplifica(pt,numitor);
    g << pt << '/' << numitor << ' ';
}
void simplifica(unsigned long long & a,unsigned long long & b){
    unsigned long long c = cmmdc(a,b);
    a /= c;
    b /= c;
}
unsigned long long cmmdc(unsigned long long a,unsigned long long b){
    int r = a % b;
    while(a % b){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}
unsigned long long lipire(unsigned long long a, int b){
	int nrb = log10(b) + 1;
	for(int i = 0 ; i < nrb ; ++i)
        a *= 10;
	a += b;
	return a;
}