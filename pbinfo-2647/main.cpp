#include <string.h>
int freq[2000002];
long long SecvBiti(char v[]) {
    int lungime = strlen(v);
    freq[lungime] = 1;
    long long int contor = 0;
    for (int i = 0 ; i < lungime; ++i)
        if (v[i] == '1') contor++ , freq[lungime + contor]++;
    else contor--, freq[lungime + contor]++;
    contor = 0;
    for (int i = 0 ; i < 2 * lungime; ++i)
        contor = contor + freq[i] * (freq[i] - 1LL) / 2;
    return contor;
}