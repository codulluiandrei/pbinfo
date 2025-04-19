#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll nines[] = {9,99,999,9999,99999,999999,9999999,99999999,999999999};
bool exista(ll x){
    for(int i=0; i<9;i++){
        if (nines[i] == x)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    ifstream cin("vecine.in");
    ofstream cout("vecine.out");
    string s;
    int p, n,k=0;
    char c;
    cin >> p >> n;
    for(int i=0;i<n;i++){
        cin >> c;
        s += c;
    }
    // CERINTA 1
    if (p==1)
    {
        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i-1]+1){
                // cout << i << " " << (int)s[i] << endl;
                k++;
            }
        }
        cout << k;
    }
    // CERINTA 2
    else{
        int maxx = 0;
        // cout << s;
        for(int m=1;m<=10;m++){
            for(int i=0;i<n-m;i++){
                // cout << s.substr(i+1,m+1);
                ll x = stoll(s.substr(i,m), nullptr, 10);
                ll y;
                if (exista(x))
                {
                    y = stoll(s.substr(i+m,m+1), nullptr, 10);
                }
                else {
                    y = stoll(s.substr(i+m,m), nullptr, 10);
                }
                // cout << x << " " << y << endl;
                if (x==y-1){
                    // cout << "!";
                    // k++;
                    if (maxx < x)
                    {
                        maxx = x;
                    }
                }
            }
            // cout << "----\n";
        }
        cout << maxx;
    }
    return 0;
}