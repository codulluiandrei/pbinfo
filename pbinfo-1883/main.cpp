#include<iostream>

using namespace std;
int main()
 {
	int n  , v[1001];
    cin >> n;
    v[0] = -1;
    for(int i = 1 ; i <= n ; i ++)
        cin >> v[i];
    for(int i = 1; i <= n ; i ++)
    {
        int poz = 0;
        for(int j = i + 1 ; j <= n && poz == 0 ; j ++)
            if(v[i] < v[j])
                poz = j;
       cout << v[poz] << " " ;
    }
	return 0;
}
