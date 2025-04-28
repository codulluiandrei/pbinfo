/* Ionut Dobricean
 * Arbori + Parsare
 * 100 puncte
*/
#include <cstdio>
using namespace std;
const int Dim = 100001;
int Tree[Dim * 4], n,O,A[Dim],s;
void Get (int &x);
void Update(int node, int le,int ri,int pos ,int val);
void Query(int node , int le , int ri , int a , int b);
int main() {
	freopen("bogdan.in","r",stdin);
	freopen("bogdan.out","w", stdout);
	Get(n);
	for ( int i = 1; i <= n; ++i) {
		Get(A[i]);
		if( A[i] < A[i-1] )
			Update(1,1,n,i,1);
		else
			Update(1,1,n,i,0);
		}
	Get(O);
	int type, x, y;
	for ( int i = 1; i <= O; ++i) {
		Get(type), Get(x), Get(y);
		if ( type == 1) {
			A[x] = y;
			{
            if ( A[x] < A[x-1])
				Update(1,1,n,x,1);
			else
				Update(1,1,n,x,0);
            }
			if( A[x+1] < A[x] )
				Update(1,1,n,x+1,1);
			else
				Update(1,1,n,x+1,0);
		}
		else {
			s = 0;
			Query(1,1,n,x + 1,y);
			if ( s == 0 )
				printf("DA\n");
			else
				printf("NU\n");
			}
		}
	return 0;
}
void Update(int node, int le,int ri,int pos ,int val) {
	if(le == ri) {
		Tree[node] = val;
		return ;
	}
	int mj = (le + ri) / 2;
	if( pos <= mj)
		Update(node * 2, le, mj , pos , val);
	else
		Update(node * 2 + 1 , mj + 1 , ri , pos , val);
	Tree[node] = Tree[node * 2]  + Tree[node * 2 + 1];
}
void Query(int node , int le , int ri , int a , int b){
    if(a <= le and b >= ri) {
        s += Tree[node];
    return ;
    }
	int mj = (le + ri) / 2;
	if(a <= mj)
		Query(2 * node, le , mj, a , b);
	if(b > mj)
		Query(2 * node + 1, mj + 1 , ri ,a , b);
}
const int Lim = 1000001;
int u =  Lim - 1;
char S[Lim];
void Next () {
    if (++u == Lim)
        std::fread(S, 1, Lim, stdin), u = 0;
}
void Get (int &x) {
	for (; S[u] < '0' || S[u] > '9'; Next());
	for (x = 0; S[u] >= '0' and S[u] <= '9'; Next())
		x = x * 10 + S[u] - '0';
}