#include<bits/stdc++.h>
using namespace std;
struct data
{
    string prenume,nume,functie,email,numar;
    unsigned long long salariu,varsta;
};
data d[1001];
int p;
char c;
bool comp(data i,data j)
{
    if(c=='-')
    {
            if(p==1)
                if(i.prenume>j.prenume)
                    return 1;
            if(p==2)
                if(i.nume>j.nume)
                    return 1;
            if(p==3)
                if(i.salariu>j.salariu)
                    return 1;
            if(p==4)
                if(i.varsta>j.varsta)
                    return 1;
            if(p==5)
                if(i.functie>j.functie)
                    return 1;
            if(p==6)
                if(i.numar>j.numar)
                    return 1;
            if(p==7)
                if(i.email>j.email)
                    return 1;
    }
    else
    {
            if(p==1)
                if(i.prenume<j.prenume)
                    return 1;
            if(p==2)
                if(i.nume<j.nume)
                    return 1;
            if(p==3)
                if(i.salariu<j.salariu)
                    return 1;
            if(p==4)
                if(i.varsta<j.varsta)
                    return 1;
            if(p==5)
                if(i.functie<j.functie)
                    return 1;
            if(p==6)
                if(i.numar<j.numar)
                    return 1;
            if(p==7)
                if(i.email<j.email)
                    return 1;
    }
    return 0;
}
int main()
{
    string s;
    int n,k=0;
    cin>>n;
    cin.get();
    for(int i=1;i<=n;i++)
    {
        getline(cin,s);
        vector<string> v;
        istringstream buffer(s);
        for(string w;buffer>>w;)
            v.push_back(w);
        for(int j=0;j<v.size();j++)
            switch(j)
            {
                case 0: d[k].prenume=v[j]; break;
                case 1: d[k].nume=v[j]; break;
                case 2: d[k].salariu=stoull(v[j]); break;
                case 3: d[k].varsta=stoull(v[j]); break;
                case 4: d[k].functie=v[j]; break;
                case 5: d[k].numar=v[j]; break;
                case 6: d[k].email=v[j]; break;
            }
        k++;
    }
    cin>>p>>c;
    stable_sort(d,d+k,comp);
    for(int i=0;i<k;i++)
        cout<<d[i].prenume<<" "<<d[i].nume<<" "<<d[i].salariu<<" "<<d[i].varsta<<" "<<d[i].functie<<" "<<d[i].numar<<" "<<d[i].email<<'\n';
    return 0;
}