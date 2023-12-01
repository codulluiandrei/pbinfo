#include <iostream>

using namespace std;

int main(){
	int N , r, plus = 0;
    cin >> N >> r;
    if(r == 1)
    {
    	if(N % 10 >= 5)
            plus = 10;
        N = N / 10 * 10 + plus;
    }
    else
    {
        if(N % 100 >= 50)
            plus = 100;
        N = N / 100 * 100 + plus;
    }
    cout << N;
    return 0;
}