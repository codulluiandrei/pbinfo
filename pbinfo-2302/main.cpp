///by Matei - 100pnct
#include <fstream>
using namespace std;
ifstream cin("memory009.in");
ofstream cout("memory009.out");
int main()
{
	int n, m;
	cin >> n >> m;
	int rez1 = 0;
    for(int i = 1; i <= n; ++i){
		int x;
		cin >> x;
        rez1 = rez1 |(1 << x);
    }
	int rez2 = 0;
	for(int i = 1; i <= m; ++i){
		int x;
		cin >> x;
        rez2 = rez2 | (1 << x);
    }
    int rezF = rez1 & rez2;
    for(int i = 1; i <= 30; ++i){
        int aux = (1 << i);
        aux = aux & rezF;
		if(aux != 0){
            cout << i << ' ';
		}
    }
    cout << '\n';
    return 0;
}