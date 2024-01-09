#include <iostream>
using namespace std;

int n;//cardinalul multimii
int X[20];//vectorul solutie
int P[20];//vector caracteristic pt pus/nepus

void afisare()
{ //afiseaza cate o solutie pe un rand
    for(int i=1;i<=n;i++)
        cout<<X[i]<<" ";
    cout<<"\n";
}

void back(int k)//k e pozitia curenta
{
    for(int i=1;i<=n;i++)
        if(!P[i])//daca i nu e pus
    { //parcurg multimea de baza (cond. externe)
        X[k]=i;//plasez element in X la poz. curenta
        P[i]=1;//i s-a pus!!!
        if(X[k]%2==1 || X[k]==k) //sa fie impar sau punct fix
        {
            if(k==n) //cond. de solutie
                afisare(); //afisare
            else back(k+1);//merg la pozitia urmatoare
        }
        P[i]=0;//i se scoate la revenire
    }
}

int main()
{
    cin>>n;
    back(1);
    return 0;
}
