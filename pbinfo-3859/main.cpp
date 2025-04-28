#include<bits/stdc++.h>
using namespace std;
ifstream fin("window.in");
ofstream fout("window.out");
int main(){
    long long n;
    cin>>n;
    cout<<((n-4)*(n-4)*(n*n-9)+4*(n-4)*(n*n-7)+4*(n-3)*(n*n-5)+8*(n*n-4)+4*(n*n-3))/2;
    return 0;
}