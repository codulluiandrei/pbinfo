#include<bits/stdc++.h>
using namespace std;
struct order
{
    string nume,prenume;
    double medie1,medie2,medie3,medieg;
};
int comp(order i,order j)
{
    if(i.medieg>j.medieg)
        return 1;
    if(i.medieg==j.medieg && i.nume<j.nume)
        return 1;
    if(i.medieg==j.medieg && i.nume==j.nume && i.prenume<j.prenume)
        return 1;
    return 0;
}
int main()
{
    order w[101];
    string s;
    int n,p;
    double g=0;
    cin>>n>>p;
    cin.get();
    for(int i=0;i<n;i++)
    {
        vector<string> v;
        getline(cin,s);
        istringstream buffer(s);
        for(string word;buffer>>word;)
            v.push_back(word);
        for(int j=0;j<v.size();j++)
            switch(j)
            {
                case 0: w[i].nume=v[j]; break;
                case 1: w[i].prenume=v[j]; break;
                case 2: w[i].medie1=stoi(v[j]); break;
                case 3: w[i].medie2=stoi(v[j]); break;
                case 4: w[i].medie3=stoi(v[j]); break;
            }
        w[i].medieg=(w[i].medie1+w[i].medie2+w[i].medie3)/3;
        g+=w[i].medieg;
    }
    g/=n;
    if(p==1)
    {
        int ap=0;
        for(int i=0;i<n;i++)
            if(w[i].medieg>=g)
                ap++;
        cout<<ap;
    }
    else
    if(p==2)
    {
        cout<<fixed<<setprecision(2)<<g<<'\n';
        sort(w,w+n,comp);
        for(int i=0;i<n;i++)
            cout<<w[i].nume<<" "<<w[i].prenume<<" "<<fixed<<setprecision(2)<<w[i].medieg<<'\n';
    }
}