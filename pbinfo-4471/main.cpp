#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[100002];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
            cin >> a[i];
            a[i] = a[i] + a[i - 1];
    }

    cin >> m;
    for(int i = 1; i <= m; i++){
        int x;
        cin >> x;
        if(x <= a[1]) cout << "1 ";
        else {
            int l = 1, r = n, pos = 0;
            while(l <= r){
                int mid = l + (r - l) / 2;
                if(x <= a[mid]){
                    pos = mid; r = mid - 1;
                }
                else l = mid + 1;
            }
            cout << pos << " ";
        }
    }
    return 0;
}

