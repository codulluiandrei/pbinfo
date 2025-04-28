#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
int main() {
    ifstream cin("multisum.in");
    ofstream cout("multisum.out");
    int N, TYPE; cin >> N >> TYPE;
    vector< pair<int, int> > V(N);
    int maxB = 3;
    for (int i = 0; i < N; ++i) {
        cin >> V[i].first >> V[i].second;
        maxB = max(maxB, V[i].second);
    }
    vector<int> from(maxB + 1, 0), max_chain(maxB + 1, 0);
    vector<int> first(maxB + 1, 0);
    max_chain[1] = 1;
    from[1] = 1;
    first[1] = 1;
    int best = 0;
    for (int i = 1; i <= maxB; ++i) {
        if (max_chain[i] == 0)
            continue;
        for (int j = i * 2; j < maxB; j += i) {
            if (max_chain[i] + 1 >= max_chain[j + 1]) {
                max_chain[j + 1] = max_chain[i] + 1;
                from[j + 1] = j / i;
                first[j + 1] = 1;
            }
        }
    }
    for (int i = maxB; i > 0; --i) {
        best = max(best, max_chain[i]);
        for (int j = i * 2; j <= maxB; j += i) {
            if (max_chain[i] > max_chain[j]) {
                max_chain[j] = max_chain[i];
                from[j] = j / i;
                first[j] = j / i;
            }
        }
    }
    vector<int> index(maxB + 1, -1);
    index[1] = 0;
    index[2] = 1;
    for (int i = 2; i <= best; ++i) {
        vector<int> aux;
        for (int j = 1; j <= maxB; ++j)
            if (max_chain[j] == i)
                aux.push_back(j);
        sort(aux.begin(), aux.end(), [&](int pos1, int pos2) {
            if (first[pos1] != first[pos2])
                return first[pos1] < first[pos2];
            if (from[pos1] != from[pos2])
                return from[pos1] < from[pos2];
            return index[pos1 / from[pos1]] < index[pos2 / from[pos2]];
        });
        for (int i = 0; i < int(aux.size()); ++i)
            index[aux[i]] = i;
    }
    for (auto &q : V) {
        int a, b; tie(a, b) = q;
        int best = 0;
        int count = 0;
        int lexicographic_minimum = a;
        for (int i = a; i <= b; ++i) {
            if (max_chain[i] > best) {
                best = max_chain[i];
                count = 1;
                lexicographic_minimum = i;
            } else if (max_chain[i] == best) {
                ++count;
                if (index[i] < index[lexicographic_minimum])
                    lexicographic_minimum = i;
            }
        }
        if (TYPE == 1)
            cout << best << "\n";
        else if (TYPE == 2)
            cout << count << "\n";
        else
            cout << lexicographic_minimum << "\n";
    }
} 