#include <iostream>
using namespace std;
int main(){
    int n , k , x , S = 0, cnt = 0;
    cin >> n >> k;
    for(int i =1 ; i <= n ; i ++)
    {
		cin >> x;
		if(x % k == 0)
			S += x;
		if(x % 2 == 0)
			cnt ++;
	}
	cout << S << " " << cnt << endl;
    return 0;
}