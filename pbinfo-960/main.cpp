#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int k, gr, p, cif;
    cin >> k;
    gr = sqrt(k);
    if(gr * gr != k)
		gr ++;
    p = k - (gr - 1)*(gr - 1); //pozitia in grupa
    if(p <= gr)
		cif = gr + 1 - p;
    else
		cif = p - gr + 1;
    cout << cif << endl;
    return 0;
}
