#include<iostream>
#include<iomanip>
#include<stack>
using namespace std;
const int N=1000002;
int n;
int a[N];
int p[N];
int d[N];
int main()
{
  cin >> n;
  for(int i=0;i<n;i++) cin >> a[i];
// O(n)
  stack<int> s;
  for(int i=1;i<n;i++)
  {
    s.push(i-1);
    while(!s.empty())
    {
      int j=s.top();
      if(a[j]>=a[i]) break;
      if(a[j]<a[i]) {p[j]=i; s.pop();}
    }
  }
// chains
   d[n-1]=0;
   for(int i=n-2;i>=0;i--)
   {
     if(p[i]==0) d[i]=0;
     else d[i]=1+d[p[i]];
   }
    cout << d[0];
    for(int i=1; i<n; i++) cout << " " << d[i];
    cout << endl;
}