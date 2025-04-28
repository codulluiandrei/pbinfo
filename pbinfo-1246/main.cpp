/*
	prof. Constantin Galatan
	O(m * log m)
	100 puncte
*/
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("dispozitiv.in");
ofstream fout("dispozitiv.out");
struct Entry { // capat de interval (stanga sau dreapta)
    int x;
    int sgn;  // +1 capat stanga, -1 capat dreapta
    bool operator < (const Entry& p) const {
        return x < p.x || (x == p.x && sgn > p.sgn);
    }
};
int n;
std::vector<Entry> X, Y;
int main()
{
	int x1, y1, x2, y2, x3, y3, xmin, xmax, ymin, ymax, px, py;
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        fin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        xmin = min(x1, min(x2, x3));
        xmax = max(x1, max(x2, x3));
		X.push_back({xmin, +1});
        X.push_back({xmax, -1});
        ymin = min(y1, min(y2, y3));
        ymax = max(y1, max(y2, y3));
        Y.push_back({ymin, +1});
        Y.push_back({ymax, -1});
    }
    sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
    int cnt(0), cmax1(0), cmax2(0);
    for (const auto& p : X)
    {
		cnt += p.sgn;
        if (p.sgn == 1 && cnt > cmax1)
        {
			cmax1 = cnt;
			px = p.x;
		}
    }
    cnt = 0;
    for (const auto& p : Y)
    {
		cnt += p.sgn;
        if (p.sgn == 1 && cnt > cmax2)
        {
			cmax2 = cnt;
			py = p.x;
		}
    }
	fout << px << ' ' << py << '\n';
    fin.close();
    fout.close();
    return 0;
}