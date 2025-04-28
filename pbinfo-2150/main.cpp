#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;
#define N_MAX 10005
ifstream f("credite.in");
ofstream g("credite.out");
struct problema {
	int c, t;
	/// suprascriem operatorul < pentru compararea dupa nr de credite a elementelor din coada de prioritati
	/*bool operator<(problema const& p) const
	{
		return c < p.c;
	}*/
};
bool Compare(problema a, problema b) /// functie pentru compararea dupa nr de credite a elementelor din coada de prioritati
{
    return a.c < b.c;
}
bool sort_by_t(problema const& a, problema const& b) /// functie care sorteaza descrescator dupa deadline
{
	return a.t > b.t;
}
problema v[N_MAX];
int main() {
	int n;
	f>>n;
	for (int i = 0; i < n; i++)
		f>>v[i].c>>v[i].t;
	sort(v, v + n, sort_by_t); /// sortam descrescator dupa deadline
	/// Indexul problemei care a devenit disponibila (cand time scade
	/// sub timpul limita t al unei probleme, spunem ca problema a devenit disponibila)
	int curpb = 0;
	/// Totalul de credite obtinute
	int total = 0;
	/// Retine problemele disponibile care n-au fost inca programate
	priority_queue<problema, vector<problema>,bool (*)(problema,problema)> q(Compare);
	for (int time = 10000; time >= 1; time--)
    {
		/// Gasim toate problemele care devin disponibile la timpul time si le punem intr-o coada
		while (curpb < n && time <= v[curpb].t)
        {
			q.push(v[curpb]);
			curpb++;
		}
		/// Daca o problema e disponibila o luam pe cea mai buna si o rezolvam la timpul time
		/// adaug numarul de credite la total
		if (q.size() > 0)
        {
			total += q.top().c;
			q.pop();
		}
	}
	g<<total;
}