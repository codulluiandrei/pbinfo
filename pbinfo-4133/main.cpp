#include <bits/stdc++.h>

#define INF (INT_MAX >> 2)
#define K_MAX 10
#define S_MAX (K_MAX * (K_MAX + 1) / 2)
#define C_MAX 100

using namespace std;

ifstream fin("microbuz.in");
ofstream fout("microbuz.out");

int T;
int N;
int C[K_MAX + 5];
pair <int, int> D[S_MAX + 5]; ///D[i] = perechea (cost, conf) unde cost reprezinta costul minim sa obtinem distanta i
                                                ///si conf reprezinta configuratia cu care acest cost a fost obtinut
bitset <C_MAX * K_MAX + 5> A[(1 << K_MAX) + 5];

pair <int, int> compute_conf(int conf) {
    int cost = 0;
    int dist = 0;
    for(int i = 0; i < K_MAX; i++) {
        if(conf & (1 << i)) {
            dist += i + 1;
            cost += C[i];
        }
    }
    return make_pair(cost, dist);
}

int main()
{
    fin >> T;
    for(int i = 0; i < K_MAX; i++) {
        fin >> C[i];
    }
    fin >> N;

    if(T <= 2) {
        for(int i = 1; i <= S_MAX; i++) {
            D[i].first = INF;
        }

        for(int conf = 0; conf < (1 << K_MAX); conf++) {
            int cost = 0, dist = 0;
            tie(cost, dist) = compute_conf(conf);
            if(D[dist].first > cost) {
                D[dist] = make_pair(cost, conf);
            }
        }

        int ans = INF;
        int ans_conf[4];
        for(int dist_1 = 0; dist_1 <= S_MAX; dist_1++) {
            for(int dist_2 = 0; dist_2 <= S_MAX && dist_1 + dist_2 <= N; dist_2++) {
                int dist_3 = N - dist_1 - dist_2;
                if(dist_3 > S_MAX) {
                    continue;
                }
                if(ans > D[dist_1].first + D[dist_2].first + D[dist_3].first) {
                    ans = D[dist_1].first + D[dist_2].first + D[dist_3].first;
                    ans_conf[1] = D[dist_1].second;
                    ans_conf[2] = D[dist_2].second;
                    ans_conf[3] = D[dist_3].second;
                }
            }
        }

        if(T == 1) {
            fout << ans << "\n";
        }
        else {
            for(int i = 1; i <= 3; i++) {
                for(int j = 0; j < K_MAX; j++) {
                    if(ans_conf[i] & (1 << j)) {
                        fout << j + 1 << " " << C[j] << "\n";
                    }
                }
            }
        }
    }
    else {
        for(int conf = 1; conf < (1 << K_MAX); conf++) {
            int cost = 0, dist = 0;
            tie(cost, dist) = compute_conf(conf);
            for(int i = 0; i < K_MAX; i++) {
                if(conf & (1 << i)) {
                    A[conf] |= A[conf ^ (1 << i)];
                }
            }
            A[conf][cost] = 1;
        }

        int ans = 0, ans_conf = 0;
        for(int conf = 1; conf < (1 << K_MAX) - 1; conf++) {
            int cost = 0, dist = 0;
            tie(cost, dist) = compute_conf(conf);
            int flip = ((1 << K_MAX) - 1) ^ conf;
            if(A[flip][cost]) {
                if(cost > ans) {
                    ans = cost;
                    ans_conf = conf;
                }
            }
        }

        fout << ans << "\n";
        for(int i = 0; i < K_MAX; i++) {
            if(ans_conf & (1 << i)) {
                fout << i + 1 << " ";
            }
        }
        fout << "\n";

        int flip = ((1 << K_MAX) - 1) ^ ans_conf;
        for(int conf = 1; conf <= flip; conf++) {
            if((conf & flip) == conf) { ///conf este submultime a lui flip
                int cost = 0, dist = 0;
                tie(cost, dist) = compute_conf(conf);
                if(cost == ans) {
                    for(int i = 0; i < K_MAX; i++) {
                        if(conf & (1 << i)) {
                            fout << i + 1 << " ";
                        }
                    }
                    return 0;
                }
            }
        }
    }
    return 0;
}
