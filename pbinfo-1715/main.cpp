/*
    Complexitate O(N log N)
*/
#include <fstream>
//#include <iostream>
#define inFile "inversiuni.in"
#define outFile "inversiuni.out"
using namespace std;
int n, a[200005];
inline void Update(int x)
{
    for(int i=x;i<=n;i+=(i&(-i)))
        a[i]++;
}
inline int Query(int x)
{
    int s=0;
    for(int i=x;i>0;i-=(i&(-i)))
        s+=a[i];
    return s;
}
int main()
{
    int i, mari, mici, x;
    long long cnt;
    ifstream fin(inFile);
    fin >> n;
    cnt = 0;
    for (i = 1; i <= n; ++i)
    {
        fin >> x;
        mici = Query(x);
        mari = i - mici - 1;
        //cout << i << " " << mici << " " << mari << "\n";
        if (mici < mari) cnt += mici;
        else cnt += mari;
        Update(x);
    }
    fin.close();
    ofstream fout(outFile);
    fout << cnt << "\n";
    fout.close();
    return 0;
}