#include <iostream>
using namespace std;
int main(){
    int n;
    long long S = 0;
    cin >> n;
    for(int i = 1; i <= n ; i ++)
		S += i * i * i;
	cout << S << endl;
    return 0;
}