#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int rez = 0 , p = 1;
    bool gasit = false;
    do
    {
		int c = n % 10;
		if(c <= 2 || c >= 6)
			rez += c * p, p *= 10, gasit = true;
		n /= 10;
	}
    while(n);
    if(gasit)
		cout << rez << endl;
	else
		cout << -1 << endl;
    return 0;
}