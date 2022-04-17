#include <bits/stdc++.h>
using namespace std;
ifstream in("sort2.in");
ofstream out("sort2.out");
int v[105], n;
int main() {
    int x;
    while (in >> x)
        if (x < 100) v[n++] = x;
    if (!n) out << "NU EXISTA";
    else {
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (v[i] > v[j]){
                    int temp = v[i];
                    v[i] = v[j];
                    v[j] = temp;
                }
        for (int i = 0; i < n; i++) out << v[i] << " ";
    } return 0;
}