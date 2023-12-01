#include <iostream>

using namespace std;

int main(){
    int n ,v[1000], k, s;
    cin >> n;
    for(int i = 0 ; i < n ; i ++)
        cin >> v[i];
    cin >> k;
    for(int i = 0 ; i < n - 1 ; i ++)
        for(int j = i + 1 ; j < n ; j ++)
            if(v[i] > v[j])
            {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
    for(int i = 0 ; i < k ; i ++)
        v[i] *= -1;
    s = 0;
    for(int i = 0 ; i < n ; i ++)
        s += v[i];
    cout << s << endl;
    return 0;
}
