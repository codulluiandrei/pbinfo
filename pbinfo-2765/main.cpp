#include <iostream>
using namespace std;
int main() {
    int R, G, B, minim, maxim;
    cin >> R >> G >> B;    
    minim = R;
    if (minim > G) minim = G;
    if (minim > B) minim = B; 
    maxim = R;
    if (maxim < G) maxim = G;
    if (maxim < B) maxim = B;    
    if (minim >= 0 && maxim <= 255) {
        if (maxim - minim <= 10) cout << "GRI";
        else cout << "CULOARE";
    } else cout << "NU E CULOARE";
    return 0;
}