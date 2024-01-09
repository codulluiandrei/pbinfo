
#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

ifstream fin("nrpits.in");
ofstream fout("nrpits.out");

int m, n, k, p, cnt, c;
int a[1000001];

stack<int> stk;
int poz1[1000001]; // poz1[i] = k poz cel mai apropiat k din stanga, pt care a[k] > a[i]
int poz2[1000001]; // // poz1[i] = k poz cel mai apropiat k din dreapta, pt care a[k] > a[i]

int main()
{
    fin >> n;
    for ( int i = 1; i <= n; ++i )
    {
        fin >> a[i];
        while (!stk.empty() && a[i] > a[stk.top()])
            stk.pop();
        if ( !stk.empty() ) poz1[i] = stk.top();
        stk.push(i);
    }
    while ( !stk.empty() ) stk.pop();

    for ( int i = n; i > 0; --i )
    {
        while (!stk.empty() && a[i] > a[stk.top()])
            stk.pop();
        if ( !stk.empty() ) poz2[i] = stk.top();
        stk.push(i);
    }
    int cnt = 0, k, p;
    for ( int i = 3; i <= n; ++i )
        if ( a[i] > a[i-1] )
        {
            k = poz1[i]; if ( k == 0 ) k = 1;
            while ( k < i - 1)
            {
                p = poz2[k];  if ( p == 0 ) p = i + 1;
                if ( p < i ) k = p;
                else k++, cnt++;
            }
        }
    fout << cnt << '\n';
    fin.close();
    fout.close();
    return 0;
}

