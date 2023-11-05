#include <iostream>

using namespace std;

short n, l1, c1, l2, c2, add;
int a[501][501], mars[501][501], q;

int main(){

    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    
    cin >> q;
    for(int i = 1; i <= q; i++){
        cin >> l1 >> c1 >> l2 >> c2 >> add;
        mars[l1][c1] += add;
        mars[l1][c2 + 1] -= add;
        mars[l2 + 1][c1] -= add;
        mars[l2 + 1][c2 + 1] += add;
    } 


    int x = 0, last = 0;

    for(int i = 1; i <= n; i++){
        
        x = 0, last = 0;
        
        for(int j = 1; j <= n; j++){
            mars[i][j] += mars[i - 1][j]; // mars pe coloana
            x = mars[i][j] + last; // mars pe linie
            last = x;
            cout << a[i][j] + x << " ";
        }        

        cout << "\n";
    }


}