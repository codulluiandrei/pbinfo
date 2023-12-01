#include <iostream>

using namespace std;

int n, m, a[100002];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    cin >> m;
    for(int i = 1; i <= m; i++){
        int x;
        cin >> x;
        if(x < a[1] or x > a[n]) cout << "0 ";
        else{
            int l = 1, r = n, R = 0, L = 0;
            while(l <= r){
                int mid = l + (r - l) / 2;
                if(a[mid] <= x){
                    R = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }

            l = 1; r = n;
            while(l <= r){
                int mid = l + (r - l) / 2;
                if(a[mid] >= x){
                    L = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            if(a[L] == x) cout << 1LL * x * (R - L + 1) << " ";
            else cout << "0 ";
        }
    }
    return 0;
}
