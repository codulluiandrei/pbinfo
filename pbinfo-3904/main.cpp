#include <bits/stdc++.h>
using namespace std;
char s[2000001], st[2000001];
char ch;
int N, K, L, top, NAfterCuts;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K >> L;
    cin >> (s + 1);
    if(K == 0 || L == 0) {
        cout << (s + 1);
        return 0;
    }
    NAfterCuts = N - K * L;
    for(int i = 1;i <= N;i++) {
        while(K > 0 && top >= L && st[top - L + 1] > s[i])
            top -= L, K--;
        st[++top] = s[i];
    }
    st[NAfterCuts + 1] = '\0';
    cout << (st + 1);
    return 0;
}