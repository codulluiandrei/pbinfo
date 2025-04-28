// Problema Mewtwo - solutie in O(N*M) folosind BFS pe grid - 100 puncte
#include <iostream>
#include <queue>
#include <utility>
// x, y = N, M
// i_ash, j_ash = coordonatele lui Ash
// i_mew2, j_mew2 = coordonatele lui Mewtwo
// i_gary, j_gary = coordonatele lui Gary
// arr = matricea
// dist1[i][j] = distanta de la punctul lui Ash pana la punctul (i, j) + 1
// dist2[i][j] = distanta de la punctul lui Mewtwo pana la punctul (i, j) + 1
int x, y;
int i_ash, j_ash;
int i_mew2, j_mew2;
int i_gary, j_gary;
char arr[1005][1005];
int dist1[1005][1005];
int dist2[1005][1005];
// Vectorii de directie
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
// Verificam daca (i, j) este in matrice
bool in_mat(int i, int j) {
	return !(i<1||i>x||j<1||j>y);
}
// Aceasta functie afla distanta minima de la punctul (is, js) la punctul (ie, je)
// folosind un BFS pe grid (sau Lee)
int bfs(int dist[][1005], int is, int js, int ie, int je) {
	// Bagam punctul de start in coada
	std::queue<std::pair<int,int>> q;
	q.emplace(std::pair<int,int>(is,js));
	// Setam distanta initiala 1, punctele cu distanta 0 fiind nevizitate
	dist[is][js] = 1;
	int i, j;
	while (!q.empty()) {
		// Scoatem punctul din coada
		i = q.front().first;
		j = q.front().second;
		q.pop();
		// Daca am ajuns la destinatie, nu mai are rost sa continuam algoritmul
		if (i==ie&&j==je) break;
		// Incercam sa intram in toate camerele vecine posibile
		for (int k = 0; k < 4; k++) {
			int inou = i+dx[k];
			int jnou = j+dy[k];
			// Verificam daca (inou, jnou) este in matrice, daca nu este vizitat si daca nu este camera blocata
			if (in_mat(inou,jnou)&&!dist[inou][jnou]&&arr[inou][jnou]!='#') {
				dist[inou][jnou] = dist[i][j]+1;
				q.emplace(std::pair<int,int>(inou,jnou));
			}
		}
	}
	// Returnam dist[ie][je]-1 deoarece consideram ca distanta de la punctul de start pana la el insusi este 1, dar defapt este 0
	return dist[ie][je]-1;
}
int main() {
	// Citim matricea
	std::cin >> x >> y;
	for (int i = 1; i <= x; i++) {
		std::cin >> (arr[i]+1);
	}
	// Aflam coordonatele lui Ash, Mewtwo si Gary
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			if (arr[i][j]=='A') {
				i_ash = i;
				j_ash = j;
			}
			if (arr[i][j]=='M') {
				i_mew2 = i;
				j_mew2 = j;
			}
			if (arr[i][j]=='G') {
				i_gary = i;
				j_gary = j;
			}
		}
	}
	// Afisam numarul minim de secunde cerut
	std::cout << bfs(dist1,i_ash,j_ash,i_mew2,j_mew2) + bfs(dist2,i_mew2,j_mew2,i_gary,j_gary) << "\n";
}