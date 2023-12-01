# include <bits/stdc++.h>
# define NMax 100001
using namespace std;

ifstream f("nrmaxinterv.in");
ofstream g("nrmaxinterv.out");

int A[NMax], B[NMax];
int n;

int main()
{
    f >> n;
    for(int i=0; i<n; ++i) {
        f >> A[i] >> B[i];
        assert(A[i] < B[i]);
    }

    sort(A, A+n);
    sort(B, B+n);

    int k = 1, Max = 1;
    int i = 1, j = 0;
    while (i < n && j < n) {
        if (A[i] <= B[j]){
            ++k; /// se deschide un nou interval
            if (k > Max){
                Max = k;
            }
            ++i;
        }
        else {
            --k;
            ++j;
        }
    }

    g << Max << '\n';

    return 0;
}
