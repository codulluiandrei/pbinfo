#include <bits/stdc++.h>
using namespace std;
ifstream in("seism.in");
ofstream out("seism.out");
bool v[100001];
int N, C, s;
int ds, cate_seisme, dmax;
int main() {
    int temp, is, ss;
    in >> C >> N;
    for (temp = 1; temp <= N; temp++) in >> v[temp];
    if (C != 3) {
        temp = 1;
        while (v[temp] != 0) temp++;
        while (temp <= N - 2) {
            while (v[temp] == 0 && temp <= N - 2) temp++;
            is = temp;
            while (v[temp] && temp <= N - 2) temp++;
            ss = temp - 1;
            if (is - 2 >= 1 && v[is - 1] == 0 && v[is - 2] == 0)
                if (v[ss + 1]==0 && v[ss + 2] == 0 && ss + 2 <= N) {
                    cate_seisme++;
                    ds = ss - is + 1;
                    if (ds > dmax) dmax = ds;
                } temp++;
        } if (C == 1) out << dmax << endl;
    else if (C == 2) out << cate_seisme << endl;
    } else {
        int inc, sf, temp1, temp2;
        temp = 1, ds = 0, dmax = 0;
        while (v[temp] != 0) temp++;
        while (temp <= N - 2) {
            if (temp != 1) inc = temp;
            else inc = 3;
            while (v[temp] == 0 && temp <= N - 2) temp++;
            sf = temp - 1;
            for (int val = inc; val <= sf; val++) v[val] = 1;
            if (sf - inc >= 5) {
                ds = (sf - inc + 1) - 4;
                if (ds > dmax) dmax = ds;
            } ds = sf - inc + 1;
            temp1 = inc - 1;
            while (v[temp1] && temp1 >= 3) temp1--;
            temp1++;
            temp2 = sf + 1;
            while (v[temp2] && temp2 <= N - 2) temp2++;
            temp2--;
            if (temp1 - 2 >= 1 && temp2 + 2 <= N)
                if (v[temp1 - 1] == 0 && v[temp1 - 2] == 0 && v[temp2 + 1] == 0 && v[temp2 + 2] == 0) {
                    ds = temp2 - temp1 + 1;
                    if (ds > dmax) dmax = ds;
                } for (int val = inc; val <= sf; val++)
                v[val] = 0;
            while (v[temp] && temp <= N - 2) temp++;
        } out << dmax << endl;
    } return 0;
}
