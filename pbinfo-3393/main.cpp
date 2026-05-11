/**
  *  Worg
  */
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_set>
FILE *fin = freopen("toorcmmdc.in", "r", stdin);
FILE *fout = freopen("toorcmmdc.out", "w", stdout);
const int block_size = 500;
std::vector<int> multiset_gcd;
std::vector<std::unordered_multiset<int>> elements;
int gcd(int a, int b) {
    int r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
void append_new_multiset() {
    std::unordered_multiset<int> s;
    elements.push_back(s);
    multiset_gcd.push_back(0);
}
void add_element(int x) {
    if (elements.back().size() > block_size) {
        append_new_multiset();
    }
    elements.back().insert(x);
    //  Recalculam gcd-ul
    int bucket_gcd = 0;
    for (auto& elem : elements.back()) {
        bucket_gcd = gcd(bucket_gcd, elem);
    }
    multiset_gcd.back() = bucket_gcd;
}
void remove_element(int x) {
    for (int i = (int)elements.size() - 1; i >= 0; i--) {
        if (elements[i].find(x) != elements[i].end()) {
            elements[i].erase(elements[i].find(x));
            //  Recalculam gcd-ul
            int bucket_gcd = 0;
            for (auto& elem : elements[i]) {
                bucket_gcd = gcd(bucket_gcd, elem);
            }
            multiset_gcd[i] = bucket_gcd;
            break;
        }
    }
}
int compute_gcd() {
    int global_gcd = 0;
    for (auto& x : multiset_gcd) {
        global_gcd = gcd(global_gcd, x);
    }
    if (!global_gcd) {
        return 1;
    }
    return global_gcd;
}
int main() {
    int n; scanf("%d", &n);
    char op[2];
    append_new_multiset();
    for (int i = 1; i <= n; i++) {
        int value;
        scanf("%s%d", op, &value);
        if (op[0] == '+') {
            add_element(value);
        } else {
            remove_element(value);
        }
        printf("%d\n", compute_gcd());
    }
    return 0;
} 