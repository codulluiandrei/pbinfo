#include <iostream>

using namespace std;
long long a[100001];
long long seg[400001];
void arbore(int i, int left, int right)
{
    if(left==right)
    {
        seg[i]=a[left];
    }
    else
    {
        int mij=(left+right)/2;
        arbore(i*2,left,mij);
        arbore(i*2+1,mij+1,right);
        seg[i]=seg[2*i]+seg[2*i+1];
    }
}
long long suma(int i, int left, int right, int ls, int rd)
{
    if(ls<=left && rd>=right)
        return seg[i];
    else
        if (ls>right || rd<left) return 0;
    else
    {
       int mij=(left+right)/2;
        long long l=suma(2*i,left,mij,ls,rd);
        long long r=suma(2*i+1,mij+1,right,ls,rd);
        return l+r;
    }
}
void modifica(int i, int left, int right, int ls)
{
    if(left==right)seg[i]=a[left];
    else
    {
        int mij=(left+right)/2;
        if(ls<=mij) modifica(2*i,left,mij,ls);
        else modifica(2*i+1,mij+1,right,ls);
        seg[i]=seg[2*i]+seg[2*i+1];
    }
}
int main()
{ int n,i,m,ls,rd,op;
  cin>>n>>m;
  for(i=1;i<=n;i++)
    cin>>a[i];
  arbore(1,1,n);
  //for(i=1;i<=2*n-1;i++)
   // cout<<seg[i]<<" ";cout<<endl;

  for(i=1;i<=m;i++)
  {
      cin>>op>>ls>>rd;
      if(op==2)
      cout<<suma(1,1,n,ls,rd)<<'\n';
      else
      {
          a[ls]=rd;
          modifica(1,1,n,ls);
      }
  }

    return 0;
}
