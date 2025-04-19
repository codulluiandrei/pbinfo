#include <iostream>
using namespace std;
int n , a[1005] , b[1005];
int main()
{
    cin >> n;
    for(int i =1 ; i <= n ; i ++)
        cin >> a[i];
    for(int i =1 ; i <= n ; i ++)
        cin >> b[i];
    int cnt1 = 0, cnt2 = 0;
    for(int i = 1 ; i <= n ; ++i)
        if(a[i] != b[i])
            if(a[i] == 1)
                cnt1 ++;
            else
                cnt2 ++;
    if(cnt1 > cnt2)
        cout << cnt1;
    else
        cout << cnt2;
    return 0;
}