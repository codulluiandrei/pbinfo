/*
    solutie oficiala:
        Autor: Iacob Tudor
        complexitate: O(nlogn) timp, O(n) memorie.
        punctaj: 100p
    Aceasta problema a fost gandita ca cea mai simpla
    problema din concursul infoleague etapa 1 dar a
    fost inlocuita.
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("window.in");
ofstream fout("window.out");
int dp[100005],n,nr,H[400005],mxi[100005];
unordered_map<int,int>nrm;
struct op{
    int nr;
    char rs;
}v[100005];
int v2[100005];
// schimba valoarea optimului care incepe cu X in val.
void update(int ind,int st,int dr,int x,int val){
    if(st==dr){
        H[ind]=val;
        mxi[x]=val;
        return;
    }
    if(x<=(st+dr)/2)update(2*ind,st,(st+dr)/2,x,val);
    else update(2*ind+1,(st+dr)/2+1,dr,x,val);
    H[ind]=max(H[2*ind],H[2*ind+1]);
}
//returneaza cea mai mare valoare care incepe cu elemente >= stw si <=drw.
int querry(int ind,int st,int dr,int stw,int drw){
    if(dr<stw||st>drw)return 0;
    if(st>=stw&&dr<=drw)return H[ind];
    return max(querry(2*ind,st,(st+dr)/2,stw,drw),querry(2*ind+1,(st+dr)/2+1,dr,stw,drw));
}
int main(){
        //se citeste inputul.
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i].nr>>v[i].rs;
        v2[i]=v[i].nr;
    }
        //se normalizeaza vectorul.
    sort(v2+1,v2+n+1);
    v2[0]=v2[1]-1;
    for(int i=1;i<=n;i++){
        if(v2[i]!=v2[i-1]){
            nrm[v2[i]]=++nr;
        }
    }
    for(int i=1;i<=n;i++)v[i].nr=nrm[v[i].nr];
        //se calculeaza dinamica dp[i] - cel mai lung subsir care contine ca prima operatie elementul i.
    dp[n]=1;
    update(1,1,n,v[n].nr,1);
    for(int i=n-1;i>=1;i--){
        if(v[i].rs=='>'){
            dp[i]=1+querry(1,1,n,v[i].nr+1,nr);
        }
        else{
            dp[i]=1+querry(1,1,n,1,v[i].nr-1);
        }
        if(dp[i]>mxi[v[i].nr])update(1,1,n,v[i].nr,dp[i]);
    }
        //se calculeaza lungimea celui mai lung subsir.
    int mx(0);
    for(int i=1;i<=n;i++)mx=max(mx,dp[i]);
    cout<<mx;
    return 0;
}