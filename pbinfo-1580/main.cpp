#include <fstream>
#include <cstring>
using namespace std;
ifstream f("schimb.in");
ofstream g("schimb.out");
char s[2001];
int n, k, p, i, j;
int main()
{
    f>>n>>k>>p;
    for (i=1; i<=n; i++) {
        f.get();
        f.get(s,2001);
        if (strlen(s)<k) {
            for (j=strlen(s)-1; j>=0; j--) g<<s[j];
            g<<'\n';
        }
        else {
            s[k-1]=96+p;
            g<<s<<'\n';
        }
    }
    return 0;
}