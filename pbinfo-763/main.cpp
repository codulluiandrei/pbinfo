#include <iostream>
using namespace std;

int a[101][101], n, m , k , p , L[101], C[101], X[101];

int main(){
    
    cin  >> n >> m >> k;
    for (int i = 1 ;i <= n ; ++i)
        for(int j = 1 ; j <= m ; ++j)
            cin >> a[i][j];
    
    for(int i = 1 ; i <= n ; i ++)
    {
        a[i][0] = 0;
        for(int j = 1 ; j <= m ; ++j)
            a[i][0] += a[i][j];
    }
    p = 0;
    if(k == n-1)
    {
        //este posibil ca toate liniile sa aibe sume diferite
        // determinam suma maxima SMAX
        // toate celelalte linii se vor modifica astfel incat sa se obtina suma SMAX. 
        // pe fiecare linie va creste cel mai mic element
        int SMAX = 0;
        for(int i = 1 ; i <= n ; ++i)
            if(a[i][0] > SMAX)
                SMAX = a[i][0];
        for(int i = 1 ; i <= n ; ++i)
            if(a[i][0] != SMAX)
            {
                int jmin = 1;
                for(int j = 2 ; j <= m ; ++j)
                    if(a[i][j] < a[i][jmin])
                        jmin = j;
                ++p; L[p] = i, C[p] = jmin, X[p] = a[i][jmin]+(SMAX - a[i][0]);
            }
    }
    else
    {
        // trebuie sa existe cel putin n-k linii cu aceeasi suma a elementelor
        //determinam suma care apare de cel putin n-k ori. fie aceasta S
        // pentru celelalte linii vom modifica cate un element
        //daca suma este mai mica decat S, marim cel mai mic element, daca suma este mai mare decat S micsoram cel mai mare element. Daca nu ajunge, continuam cu micsorarea
        int S = -1;
        for(int i = 1 ; i <= n && S == -1 ; i ++)
        {
            int cnt = 1;
            for(int j = 1 ; j <= n ; j ++)
                if(a[i][0] == a[j][0])
                    cnt ++;
            if(cnt >= n - k)
                S = a[i][0];
        }
        for(int i = 1 ; i <= n ; ++i)
            if(a[i][0] < S) 
            {
                // vom mari un element
                int jmin = 1;
                for(int j = 2 ; j <= m ; ++j)
                    if(a[i][j] < a[i][jmin])
                        jmin = j;
                int plus = S - a[i][0];
                a[i][jmin] += plus;
                ++p; L[p] = i, C[p] = jmin, X[p] = a[i][jmin];
            }
            else
                while(a[i][0] > S)
                {
                    //vom micsora un element
                    int jmax = 1;
                    for(int j = 2 ; j <= m ; ++j)
                        if(a[i][j] > a[i][jmax])
                            jmax = j;
                    int dif;
                    if(a[i][0] - S <= a[i][jmax])
                        dif = a[i][0] - S;
                    else
                        dif = a[i][jmax];
                    a[i][jmax] -= dif;
                    a[i][0] -= dif;
                    ++p; L[p] = i, C[p] = jmax, X[p] = a[i][jmax];
                }
    }
    cout << p << endl;
    for(int i =1 ; i <= p ; i ++)
        cout <<L[i] << " " << C[i] << " " << X[i] << endl;
    return 0;
}