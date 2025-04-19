#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int P = 0, I = 0;;
    do
    {
        if(n % 2 == 0)
            P ++;
        else
            I ++;
        n /= 10;
    }
    while(n != 0);
    cout << P << " " << I << endl;
    return 0;
}