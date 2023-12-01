#include <iostream>
using namespace std;

int n , v[1005];

int main() {
    cin >> n;
    for (int i = 1; i <= n-2; ++i)
        cin >> v[i];
    
    n -= 2;
    
    for(int i = 1 ; i < n ; ++i)
		for(int j = i + 1 ; j <= n ; ++j)
			if(v[i] > v[j])
			{
				int aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
	
	int x = -1, y = -1;
    
    if(n == 3 && v[2] - v[1] == v[3] - v[2] && (v[2] - v[1]) % 2 == 0)
    {
        int r = (v[2]-v[1]) / 2;
        x = v[1] + r; 
        y = v[2] + r;
    }
    else
        if(n == 2)
        {
            int r = (v[2]-v[1]) / 3;
            x = v[1] + r; 
            y = v[1] + 2 * r;
        }
        else
        {
            int r = v[n] - v[1];
            for(int i = 1; i < n ; ++i)
                if( r > v[i+1] - v[i] )
                    r = v[i+1] - v[i];
            
            for(int i = 1 ; i < n && y == -1 ; i ++)
                if(v[i+1] - v[i] != r)
                {
                    if(x == -1)
                    {
                        x = v[i] + r;
                        if(x + r < v[i+1])
                            y = x + r;
                    }
                    else
                        y = v[i] + r;
                }
        }
	cout << x << " " << y << endl;
	return 0;
}
