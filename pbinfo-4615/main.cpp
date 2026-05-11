#include <bits/stdc++.h>
using namespace std;
const int C_MAX = 10;
const int N_MAX = 10000;
struct Participant {
    char country[C_MAX + 5];
    char id[C_MAX + 5];
    int len;
};
int N;
char host[C_MAX + 5];
Participant P[N_MAX + 5];
Participant hosts[N_MAX + 5], rest[N_MAX + 5];
bool cmp(Participant a, Participant b) {
    int x = strcmp(a.country, b.country);
    int y = strcmp(a.id, b.id);
    if(x < 0) {
        return true;
    }
    if(x > 0) {
        return false;
    }
    if(y < 0) {
        return true;
    }
    return false;
}
bool cmp_str(Participant a, Participant b) {
    return strcmp(a.id, b.id) < 0;
}
int main() {
#ifndef LOCAL
    freopen("mun.in", "r", stdin);
    freopen("mun.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int task;
    cin >> task >> N;
    for(int i = 1; i <= N; i++) {
        cin >> P[i].id;
        strcpy(P[i].country, P[i].id);
        P[i].len = strlen(P[i].id);
        sort(P[i].country, P[i].country + P[i].len);
    }
    sort(P + 1, P + N + 1, cmp);
    int mx_freq = 0, curr_freq = 1;
    int countries = 1;
    strcpy(host, P[1].country);
    for(int i = 2; i <= N; i++) {
        if(strcmp(P[i].country, P[i - 1].country) == 0) {
            curr_freq++;
        }
        else {
            countries++;
            curr_freq = 1;
        }
        if(mx_freq < curr_freq) {
            mx_freq = curr_freq;
            strcpy(host, P[i].country);
        }
    }
    if(task == 1) {
        cout << countries << "\n";
        return 0;
    }
    if(task == 2) {
        cout << N - 2 * (N - mx_freq) << " " << 2 * (N - mx_freq) << "\n";
        return 0;
    }
    int n_hosts = 0, n_rest = 0;
    for(int i = 1; i <= N; i++) {
        if(strcmp(P[i].country, host) == 0) {
            hosts[++n_hosts] = P[i];
        }
        else {
            rest[++n_rest] = P[i];
        }
    }
    sort(hosts + 1, hosts + n_hosts + 1, cmp_str);
    sort(rest + 1, rest + n_rest + 1, cmp_str);
    if(strcmp(hosts[1].id, rest[1].id) < 0) {
        for(int i = 1; i <= n_hosts && i <= n_rest; i++) {
            cout << hosts[i].id << " " << rest[i].id << " ";
        }
    }
    else {
        for(int i = 1; i <= n_hosts && i <= n_rest; i++) {
            cout << rest[i].id << " " << hosts[i].id << " ";
        }
    }
    return 0;
}