/*
 Paul Diac
 solutile problema smallworld
 memorie: O(N)
 timp: O(N)
 idee: doua parcurgeri DFS/BFS din radacina aleasa nodul 1, in care calculez:
       hmax[i] = distanta maxima din subarborele i de la i pana la orice frunza
	           = 1 + maximul dintre hmax[] din fii
	   dtop[i] = distanta maxima plecand din i in sus macar o muchie si apoi eventual in jos
	           = max(dtop[parinte(i)] + 1, max(hmax[frate(i)]) - pentru orice frate/sibling)
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
#define NMax 100005
using namespace std;
int N;
vector<int> p[NMax]; // p[i] = prieteni lui i
int viz[NMax], t[NMax]; // t[i] = tatal lui i
int hmax[NMax]; // distanta maxima "in jos"
int dtop[NMax]; // distanta maxima "in sus" (si apoi eventual in jos)
int phm[NMax][2]; // hm[i] = cei doi prietenii-fii ai lui i care au hmax[] cel mai mare
void DFS_hmax(int a) {
	for (int i = 0; i < p[a].size(); i++) {
		if (!viz[p[a][i]]) {
			viz[p[a][i]] = 1;
			DFS_hmax(p[a][i]);
			t[p[a][i]] = a;
		}
	}
	for (int i = 0; i < p[a].size(); i++) {
		if (hmax[a] < hmax[p[a][i]] + 1) {
			hmax[a] = hmax[p[a][i]] + 1;
		}
	}
}
void DFS_dtop(int a) {
	if (t[a]) {
		if (dtop[a] < dtop[t[a]] + 1) { dtop[a] = dtop[t[a]] + 1; }
		// evit un worst case O(N^2) - atunci cand a are foarte multi frati
		// folosesc cei doi fii ai tatalui cu hmax[] maxim pre-calculati 
		// este nevoie de doi pentru ca unul ar putea fi chiar a			
		for (int j = 0; j < 2; j++) {
			int s = phm[t[a]][j];				
			if (s != 0 && s != a && dtop[a] < hmax[s] + 2) { dtop[a] = hmax[s] + 2; }
		}
	}
	for (int i = 0; i < p[a].size(); i++) {
		if (!viz[p[a][i]]) {
			viz[p[a][i]] = 1;
			DFS_dtop(p[a][i]);
		}
	}	
}
int main() {
	freopen("smallworld.in", "r", stdin);
	freopen("smallworld.out", "w", stdout);
	scanf("%d", &N);
	int a, b, dMax;
	for (int i = 0; i < N-1; i++) {
		scanf("%d %d", &a, &b);
		p[a].push_back(b);
		p[b].push_back(a);
	}
	viz[1] = 1;
	DFS_hmax(1);
	for (int i = 1; i <= N; i++) {
		hmax[i]--;
		viz[i] = 0;
	}
	for (int i = 1; i <= N; i++) {
		if (phm[t[i]][0] == 0 || hmax[phm[t[i]][0]] < hmax[i]) {
			phm[t[i]][1] = phm[t[i]][0];
			phm[t[i]][0] = i;
		} else if (phm[t[i]][1] == 0 || hmax[phm[t[i]][1]] < hmax[i]) {
			phm[t[i]][1] = i;
		}
	}
	DFS_dtop(1);
	dMax = 0;
	for (int i = 1; i <= N; i++) {
		if (hmax[i] < dtop[i]) {
			printf("%ld\n", dtop[i]);
		} else {
			printf("%ld\n", hmax[i]);
		}
	}	
	return 0;
}