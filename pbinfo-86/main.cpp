#include <bits/stdc++.h>
using namespace std;

ifstream in("halfsort.in");
ofstream out("halfsort.out");

int main() {
    int n, vec[105]; in >> n;
    for (int i = 1; i <= n; i++) in >> vec[i];
    for (int i = 1; i < n / 2; i++)
        for (int j = i + 1; j <= n / 2; j++)
            if (vec[i] > vec[j]) {
                int temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
    for (int i = n / 2 + 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            if (vec[i] < vec[j]) {
                int temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
    for(int i = 1; i <= n; i++)
        out << vec[i] << " ";
    out << endl;
    return 0;
}