# include <iostream>
using namespace std;

int n, x[1005], m, y[1005];

void quick(int st, int dr, int v[])
{
    if(st < dr)
    {
        int i = st, j = dr, d = 0;
        while(i < j)
        {
            if(v[i] > v[j])
            {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                d = 1-d;
            }
            if(d == 0)
                j--;
            else
                i++;
        }
        int k = i;
        quick(st, k-1, v);
        quick(k+1, dr, v);
    }
}

int caut(int st, int dr, int v[], int x)
{
    if(st > dr)
            return 0;
    else
    {
        int m = (st + dr)/2;
        if(v[m] == x)
            return m;
        if(v[m] > x)
            return caut(1, m-1, v, x);
        if(v[m] < x)
            return caut(m+1, dr, v, x);
        return 0;
    }
}

void citire(int &n, int v[])
{
    cin>>n;
    for(int i = 1; i <= n ; i++)
        cin>>v[i];
}


int main()
{
    citire(n, x);
    citire(m, y);
    quick(1, n, x);
    for(int i=1; i<=m; i++)
           if((caut(1, n, x, y[i])))
              cout<<1<<" ";
            else
                cout<<0<<" ";


    return 0;
}

