//Algoritmul Moore-Hodgson: O(n^2)
//Autor: Patcas Csaba
#include <vector>
#include <algorithm> 
#include <iostream> 
using namespace std;
#define LL long long
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define X first
#define Y second
struct Task
{
	int id, len, deadline, start;
};
int n, sol = 0;
vector <Task> a;
vector <bool> chosen; //alese sa fie terminate inainte de termen
vector < pair <LL, LL> > cal; //calendarul de planificare
bool byDeadline(const Task& x, const Task& y)
{
	return x.deadline < y.deadline;
}
int main()
{
	freopen("bolovani.in", "r", stdin);
	freopen("bolovani.out", "w", stdout);
	//Citire
	cin >> n;
	a.resize(n + 1);
	FOR(i, 1, n)
	{
		cin >> a[i].len >> a[i].deadline;
		a[i].id = i;
	}
	sort(a.begin() + 1, a.end(), byDeadline);
	chosen.resize(n + 1);
	//Timpul total necesar pentru spargerea bolovanilor planificati
	LL t = 0; 
	FOR(i, 1, n)
		if (t + a[i].len <= a[i].deadline)
		{
			//Bolovanul i se poate planifica fara probleme
			chosen[i] = true;
			++sol;
			a[i].start = t + 1;
			t += a[i].len;
		}
		else
		{
			//Cautam cel mai lung ales
			int longest = -1;
			FOR(j, 1, n)
				if (chosen[j])
					if (longest == -1 || a[longest].len < a[j].len) longest = j;
			//Il scoatem daca este prea lung
			if (longest != -1 && a[longest].len > a[i].len)
			{
				chosen[longest] = false;
				t -= a[longest].len;
				a[i].start = t + 1;
				FOR(j, longest + 1, n)
					if (chosen[j]) a[j].start -= a[longest].len;
				chosen[i] = true;
				t += a[i].len;
			}
		}
	cal.resize(n + 1);
	//Cele alese se vor planifica inainte de termen
	FOR(i, 1, n)
		if (chosen[i]) cal[a[i].id] = {a[i].start, a[i].start + a[i].len - 1};
	//Restul se poate planifica oricum
	FOR(i, 1, n)
		if (!chosen[i])
		{
			cal[a[i].id] = {t + 1, t + a[i].len};
			t += a[i].len;
		}
	cout << sol << '\n';
	FOR(i, 1, n) cout << cal[i].X << " " << cal[i].Y << '\n';
	return 0;
}