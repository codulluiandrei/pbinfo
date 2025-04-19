#include <bits/stdc++.h>
void ReverseWords(char s[]) {
    int len = strlen(s);
    int st = 0;
    int sf = 0;
    while (sf < len) {
        if (s[sf] == ' ' || s[sf] == '\0') {
            int Cuvst = st;
            int Cuvsf = sf - 1;
            while (Cuvst < Cuvsf) {
                char temp = s[Cuvst];
                s[Cuvst] = s[Cuvsf];
                s[Cuvsf] = temp;
                Cuvst++;
                Cuvsf--;
            }
            st = sf + 1;
        }
        sf++;
    }
    int uCuvst = st;
    int uCuvsf = len - 1;
    while (uCuvst < uCuvsf) {
        char temp = s[uCuvst];
        s[uCuvst] = s[uCuvsf];
        s[uCuvsf] = temp;
        uCuvst++;
        uCuvsf--;
    }
    st = 0;
    sf = len - 1;
    while (st < sf) {
        char temp = s[st];
        s[st] = s[sf];
        s[sf] = temp;
        st++;
        sf--;
    }
}