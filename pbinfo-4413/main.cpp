#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("parcare.in", "r", stdin);
    freopen("parcare.out", "w", stdout);


    int N, M, T;
    cin >> N >> M >> T;

    list<int> liber;
    for(int i = 0; i < N; i++)
        liber.push_back(i);

    vector<int> events(T, 0);
    for(int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        events[x - 1] = x;
        if(y <= T)  events[y - 1] = -x;
    }

    vector<int> parcare(N, -1);
    vector<int> where(T, -1);
    for(int i = 0; i < T; i++) {
        if(events[i] == 0)  continue;
        if(events[i] > 0) {
            int x = events[i];
            if(liber.empty()) printf("-1\n");
            else {
                int p = liber.front();
                liber.pop_front();
                where[x - 1] = p;
                parcare[p] = x;
                printf("%d\n", p + 1);
            }
        } else {
            int x = -events[i];
            if(where[x - 1] != -1) {
                int p = where[x - 1];
                liber.push_back(p);
                parcare[p] = -1;
                where[x - 1] = -1;
            }
        }
    }

    for(int i = 0; i < N; i++)
        printf("%d ", parcare[i]);
    printf("\n");
    return 0;
}