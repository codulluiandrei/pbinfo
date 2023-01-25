#include <fstream>
using namespace std;
ifstream cin("paritar.in");
ofstream cout("paritar.out");
int main() {
    int max_imp = 0, max_par = 0, min_imp = 1000001, min_par = 1000001;
	int n, temp;
	bool adv = false;
	cin >> n;
	for (int i = 1; i <= n; i++) {
	    cin >> temp;
	    if (temp % 2 == 0 && max_par < temp)
	        max_par = temp;
	    else if (temp % 2 == 1 && max_imp < temp)
	        max_imp = temp;
	}
	for (int i = n + 1; i <= 2 * n; i ++) {
	    cin >> temp;
	    if (temp % 2 == 0 && min_par > temp)
	        min_par = temp;
	    else if (temp % 2 == 1 && min_imp > temp)
	        min_imp = temp;
	}
    if (max_imp == 0 && min_imp == 1000001)
        cout << "DA";
    else if (max_par == 0 && min_par == 1000001)
        cout << "DA";
    else if (max_par < min_imp && max_imp < min_par)
        cout << "DA";
    else 
        cout << "NU";
	return 0;
}