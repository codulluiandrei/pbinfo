#include <fstream>
#define MAXX 2000010
#define MAXN 100010
using namespace std;
ifstream f("ozn.in");
ofstream g("ozn.out");
int A[MAXX];
int N,K;
int X1,Y1,X2,Y2,nr,i;
int main()
{
    f>>N>>K;
	for (i=1; i <= N; ++i){
		f>>X1>>Y2>>X2>>Y2>>nr;
		A[X1]+=nr;
		A[X2+1]-=nr;
	}
	for (i = 1; i < MAXX; ++i)
		A[i] += A[i-1];
	for (i = 1; i <= K; ++i){
		f>>X1;
		g<<A[X1]<<'\n';
	}
	g.close(); f.close();
	return 0;
}