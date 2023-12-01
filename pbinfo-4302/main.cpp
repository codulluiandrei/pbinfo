#include <fstream>
#include <stack>

#define maxn 1000010

using namespace std;

ifstream fin ("status.in");
ofstream fout ("status.out");

char st[maxn];
string s;
int n,t;

int main ()
{
    fin>>n>>s;

    for (int i = 0; i < n; ++i)
    {
        if (t != 0 && st[t] == s[i])
            --t;
        else st[++t] = s[i];
    }

    for (int i = 1; i <= t; ++i)
        fout<<st[i];
}
