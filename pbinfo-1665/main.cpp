#include<iostream>

using namespace std;

int main() {
    int nr_elem, nr, gasit = 0, pozitie = 0, nr_cautat;

    cin >> nr_elem >> nr_cautat;

    for(int i = 1; i <= nr_elem; i++) {
        cin >> nr;

        if(nr == nr_cautat)
            gasit = 1;
        else
            if(nr_cautat < nr)
                pozitie++;
    }

    if(gasit == 0)
        cout << -1;
    else
        cout << pozitie + 1;

    return 0;
}
