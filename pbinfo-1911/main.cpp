#include <iostream>

using namespace std;

int main()
{
    int n, i, V[101], A[101], R[205];
    cin>>n;
    for(i=1 ; i<=n ; i++)
        cin>>V[i];
    for(i=1 ; i<=n ; i++)
        A[i]=i;
    int p = n;
    bool sortat = false;
    while(!sortat)
    {
        sortat = true;
        for(i=1 ; i < p ; i++)
            if(V[i] > V[i+1])
            {
                swap(V[i],V[i+1]);
                swap(A[i],A[i+1]);
                sortat = false;
            }
            p=i;
    }
    int N = 2 * n;
    for(int i=1, j=1 ; i<=N , j<=n ; i+=2, j++)
        R[i]=V[j];
    for(int i=2, j=1 ; i< N , j<=n ; i+=2, j++)
        R[i]=A[j];

    for(int i=1 ; i<=N ; i++)
        cout<<R[i]<<" ";


}
