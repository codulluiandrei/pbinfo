#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("cod3.in");
ofstream cout("cod3.out");
int n, temp, freq[100], v[90005], maxim = -100, minim = 1000;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> temp;
        freq[temp]++;
        if (temp < minim) minim = temp;
        else if (temp > maxim) maxim = temp;
    } temp = 0; 
    for (int i = minim; i <= maxim; ++i)
        if (freq[i] % 2 != 0)
         v[temp++] = i;
    sort(v, v + temp);
    for (int i = 0; i < temp; ++i) 
        cout << v[i];
}