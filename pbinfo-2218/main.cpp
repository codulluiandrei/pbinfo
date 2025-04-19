/// O(N log N)
#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int N, x, y, op;
    set<int> s;
    set<int>::iterator it, A, B;
    ifstream  fin("set.in");
    ofstream fout("set.out");
    fin >> N;
    while (N--)
    {
        fin >> op;
        if (op == 1)
        {
            fin >> x;
            s.insert(x);
        }
        else if (op == 2)
        {
            fin >> x;
            if (s.empty()) {fout << "-1\n"; continue;}
            it = s.lower_bound(x);
            if (it == s.end()) fout << "-1\n";
            else fout << *it << "\n";
        }
        else
        {
            fin >> x >> y;
            if (s.empty()) continue;
            A = s.lower_bound(x);
            B = s.lower_bound(y + 1);
            s.erase(A, B);
        }
    }
    fin.close();
    fout.close();
    return 0;
}