#include <fstream>
#define DIM 1000002
using namespace std;
ifstream fin("codat.in");
ofstream fout("codat.out");
int v[DIM], s[DIM], L[DIM], R[DIM], minim, k, n, i, maxim, pminim;
int main() {
    fin>>n;
    for (i=1;i<=n;i++) {
        fin>>v[i];
        if (v[i] > maxim)
            maxim = v[i];
        while (k!=0 && v[i] >= v[s[k]]) {
            k--;
        }
        L[i] = s[k];
        s[++k] = i;
    }
    k = 0;
    s[k] = n+1;
    for (i=n;i>=1;i--) {
        while (k!=0 && v[i] >= v[s[k]]) {
            k--;
        }
        R[i] = s[k];
        s[++k] = i;
    }
    for (i=1;i<=n;i++) {
        if (v[i] == maxim) {
            v[i] = -1;
            continue;
        }
        minim = n+2;
        if (L[i] != 0 && i-L[i]<minim) {
            minim = i-L[i];
            pminim = L[i];
        }
        if (R[i]!=n+1 && R[i]-i <= minim) {
            minim = R[i]-i;
            pminim = R[i];
        }
        v[i] = pminim;
    }
    for(i=1;i<=n;i++)
        fout<<v[i]<<" ";
    return 0;
}