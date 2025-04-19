#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
#define NN 100001
int main()
 {
	//code
	int n  , v[NN], rez[NN];
    int s[NN], ns = 0;
    cin >> n;
    v[n + 1] = -1;
    for(int i = 1 ; i <= n ; i ++)
        cin >> v[i];
    s[ns = 1] = 1;
    for(int i = 2; i <= n ; i ++)
    {
        while(ns > 0 && v[i] > v[s[ns]])
        {
            rez[s[ns--]] = v[i];
        }
        s[++ns] = i;
    }
    while(ns > 0)
    {
        rez[s[ns--]] = -1;
    }
    for(int i = 1; i <= n ; i ++)
        cout << rez[i] << " ";
    return 0;
}