#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    switch (n % 4) {
        case 1:
            cout << '+';
            break;
        case 2:
        	cout << "---+"; 
        	break;
        case 3:
        	cout << "-+";   
        	break;
    } for (int i = n / 4 - 1; i >= 0; --i)
        cout << "+--+";
    return 0;
}