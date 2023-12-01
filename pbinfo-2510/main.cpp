#include <bits/stdc++.h>
#define MAXN 1100010
#define bsize (1<<16)

using namespace std;

FILE* in = fopen("vsecvente.in", "r");
FILE* out = fopen("vsecvente.out", "w");

int Answer[MAXN];
int A[5];
int N, Q, Query, pos;
char s[bsize + 1];

void read (int &x){
    x=0;
    while( !isdigit(s[pos])){
        pos++;
        if(pos==bsize){
            fread(s, 1, bsize, in);
            pos=0;
        }
    }
    while( isdigit(s[pos])){
        x = x*10 + s[pos]-'0';
        pos++;
        if(pos==bsize){
            fread(s, 1, bsize, in);
            pos=0;
        }
    }

}

int main()
{

    pos=0;
    fread(s, 1, bsize, in);
	read(N);
	read(A[0]);
//	assert(A[0]<=550000 && A[0]>0);
	A[2] = INT_MAX; // A[-1] = INF
	for (int i = 0; i < N; ++i) {
		if (i == N - 1)
			A[(i + 1) % 3] = INT_MAX;
		else {
			read( A[(i + 1) % 3]);
          ///  assert(A[(i + 1)%3]<=550000 && A[(i + 1)%3]>0);
		}
		++Answer[A[i % 3]];
		if (A[(i + 2) % 3] <= A[i % 3])
			--Answer[A[i % 3]];
		if (A[(i + 1) % 3] < A[i % 3])
			--Answer[A[i % 3]];
	}
	for (int i = 0; i < MAXN; ++i)
		Answer[i] += Answer[i - 1];

	read(Q);
	for (int i = 0; i < Q; ++i) {
		read(Query);
		fprintf(out, "%d\n", Answer[Query]);
	}

	return 0;
}
