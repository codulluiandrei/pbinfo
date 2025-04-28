#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int C = 0;
    long long S = 0;
    for(int i = 1 ; i <= n ; i ++)
    {
		int x, cx;
		cin >> x;
		cx = x;
		bool p2 = false, p5 = false;
		while(x)
		{
			if(x % 10 == 2)
				p2 = true;
			if(x % 10 == 5)
				p5 = true;
			x /= 10;
		}
		if(p2 && !p5)
			C ++;
		if(!p2 && p5)
			S += cx;
	}
    cout << C << " " << S << endl;
    return 0;
}