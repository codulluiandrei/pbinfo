#include <iostream>
#include <fstream>
using namespace std;


int n , a[105][105], gi[105];

int main()
{
    int i , j , m;
    cin >> n >> m;
    while( m )
    {
    	cin >> i >> j;
    	a[i][j] = 1;
    	m --;
    }

    for(int i = 1 ;  i <= n ; i++){
        gi[i]  = 0;
        for(int j = 1; j <= n ; ++j){
            if(a[j][i] == 1)
				gi[i] ++;
				
		}
    }
    
    int gmax = gi[1];
    for(int i = 2 ;  i <= n ; i++)
        if(gi[i] > gmax)
                gmax = gi[i];

    for(int i = 1 ;  i <= n ; i++)
        if(gi[i] == gmax)
            cout << i << " ";

    return 0;
}
