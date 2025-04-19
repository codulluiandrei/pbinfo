#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
#define NN 1005
struct obiect{
    int greutate, valoare;
};
int n, Gmax;
obiect O[NN];
bool fcmp(obiect A, obiect B)
{
    return A.valoare * B.greutate > A.greutate * B.valoare;
}
int main(){
	assert(cin >> n >> Gmax );
	for(int i=1 ; i<=n ; ++i)
		assert(cin >> O[i].greutate >> O[i].valoare);
	sort (O + 1 , O + n + 1, fcmp);
    int G = 0;
    double V = 0;
    int i = 1;
    while( i <= n)
    {
        if(G + O[i].greutate <= Gmax)
        {
            G += O[i].greutate;
            V += O[i].valoare;
            i ++;
        }
        else
            if(Gmax - G > 0)
            {
                int x = Gmax - G;
                double factor = 1.0 * x / O[i].greutate;
                G = Gmax;
                V += factor * O[i].valoare;
                i++;
            }
            else
                i = n + 1;
    }
    cout << V;
	return 0;
}