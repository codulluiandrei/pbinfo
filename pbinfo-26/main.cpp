#include <bits/stdc++.h>
int cmmnr(int n) {
    long long int v[10], o = 0, p = 0, temp = 0;
    while (n) {
        if (n % 10 == 0) temp++;
        else {
            v[p] = n % 10;
            p++;
        } n = n / 10;
    } sort(v, v + p);
    int adv = 0;
    for (int i = 0; i < p; i++) {
        o = o * 10 + v[i];
        adv++;
        if (adv==1) {
            for (int i = 0; i < temp; i++) {
                o = o * 10;
            }
        }
    } return o;
}