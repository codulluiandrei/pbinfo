#include <iostream> 
using namespace std;
int main() {   
    int z, l, a; 
    cin >> z >> l >> a;
    if ((l == 1 || l == 3 || l == 5 || l == 7 || l == 8 || l == 10 || l == 12) && z <= 31) cout << "DA";  
    else if ((l == 4 || l == 6 || l == 9 || l == 11 ) && z <= 30) cout << "DA"; 
    else if (l == 2 && z <= 29 && a % 4 == 0 && (a % 100 != 0 || a % 400 == 0)) cout << "DA"; 
    else if (l == 2 && z <= 29 && a % 4 == 0 && (a % 400 !=0)) cout << "NU"; 
    else cout << "NU";
    return 0; 
}