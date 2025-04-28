/// student Alexandru Turdean  
/// Universitatea Tehnica din Cluj-Napoca
#include<fstream>
#include<vector>
using namespace std;
ifstream fin("ateleport.in");
ofstream fout("ateleport.out");
struct muchie{
    int nod;
    int timp;
};
struct element{
    int nod;
    int timp;
    int muchii_teleportarea_curenta;
    int teleportari;
    bool operator<(const element &x) const
    {
        return timp < x.timp;
    }
};
struct min_heap{ /// pentru usurinta se poate folosi priority_queue
    element v[1000001];
    int size = 0;
    element top()
    {
        return v[1];
    }
    void push(element el)
    {
        size++;
        v[size] = el;
        int pos = size;
        while(pos != 1)
            if(v[pos] < v[pos/2])
                swap(v[pos/2],v[pos]), pos/=2;
            else
                break;
    }
    void pop()
    {
        if(size == 0)
            return;
        swap(v[1],v[size]);
        size--;
        int pos = 1;
        while(pos*2+1 <= size)
        {
            if(v[pos*2] < v[pos] && v[pos*2] < v[pos*2+1])
                swap(v[pos*2], v[pos]), pos = pos*2;
            else if(v[pos*2+1] < v[pos])
                swap(v[pos*2+1], v[pos]), pos = pos*2+1;
            else
                break;
        }
        if(pos*2 == size && v[pos*2] < v[pos])
            swap(v[pos*2], v[pos]);
    }
};
int n,m,p,l,k;
int timp_minim[10001][11][11]; /// timp_minim[x][y][z] = timpul minim pentru a ajunge in nodul x cu y teleportari si z muchii parcurse din teleportarea curenta
vector<muchie> muchii[10001];
min_heap myHeap;
void update(element &y)
{
    if(y.timp < timp_minim[y.nod][y.teleportari][y.muchii_teleportarea_curenta])
    {
        timp_minim[y.nod][y.teleportari][y.muchii_teleportarea_curenta] = y.timp;
        myHeap.push(y);
    }
}
int main()
{
    fin >> n >> m >> p >> l >> k;
    for(int i = 1; i <= m; i++)
    {
        int x,y,t;
        fin >> x >> y >> t;
        muchii[x].push_back(muchie{y,t});
        muchii[y].push_back(muchie{x,t});
    }
    for(int x = 0; x <= n; x++)
        for(int y = 0; y <= 10; y++)
            for(int z = 0; z <= 10; z++)
                timp_minim[x][y][z] = 2000000000;
    myHeap.push(element{1,0,0,0});
    timp_minim[1][0][0] = 0;
    while(myHeap.size > 0)
    {
        element x;
        x = myHeap.top();
        myHeap.pop();
        if(timp_minim[x.nod][x.teleportari][x.muchii_teleportarea_curenta] < x.timp)
            continue; /// am ajuns intr-o stare in care am mai fost cu un timp mai mic
        if(x.nod == n)
        {
            fout << x.timp;
            return 0;
        }
        for(int i = 0; i < muchii[x.nod].size(); i++)
        {
            element y;
            y.nod = muchii[x.nod][i].nod;
            if(x.teleportari < k) /// incepem teleportare noua
            {
                y.timp = x.timp + p;
                y.muchii_teleportarea_curenta = 1;
                y.teleportari = x.teleportari + 1;
                update(y);
            }
            if(x.muchii_teleportarea_curenta > 0 && x.muchii_teleportarea_curenta < l) /// continuam teleportarea
            {
                    y.timp = x.timp;
                    y.muchii_teleportarea_curenta = x.muchii_teleportarea_curenta + 1;
                    y.teleportari = x.teleportari;
                    update(y);
            }
            y.timp = x.timp + muchii[x.nod][i].timp; /// folosim canalul de transport
            y.teleportari = x.teleportari;
            y.muchii_teleportarea_curenta = 0;
            update(y);
        }
    }
    return 0;
}