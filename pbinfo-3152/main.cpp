#include <iostream>
using namespace std;

int n;///cardinalul multimii
int m;///cate se iau
int X[21];///solutia

void afisare()
{///afisarea solutiei
    for(int i=1;i<=m;i++)
        cout<<X[i]<<" ";
    cout<<"\n";
}

void back(int k)
{
    for(int i=X[k-1]+1;i<=n;i++)
    { ///incep de la elementul anterior +1
        X[k]=i;///il pun in solutie
        if(k==1 || X[k]%2+X[k-1]%2!=0) ///sa nu fie 2 pare alaturate
        {
            if(k==m)///am pus m => solutie
                afisare();
            else back(k+1);///trec la pasul urmator
        }
    }

}

int main()
{
    cin>>n>>m;
    back(1);
    return 0;
}
