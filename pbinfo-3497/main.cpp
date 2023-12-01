#include <bits/stdc++.h>

#define NMAX 1000005
#define Huge int
using namespace std;

Huge a[NMAX], b[NMAX], c[NMAX], rez[NMAX], r[NMAX], ax[NMAX], x[NMAX];

void Shl(Huge H[NMAX], int Count)
{
  memmove(&H[Count+1],&H[1],sizeof(int)*H[0]);
  memset(&H[1],0,sizeof(int)*Count);
  H[0]+=Count;
}

void Subtract(Huge A[NMAX], Huge B[NMAX])
{ int i, T=0;

  for (i=B[0]+1;i<=A[0];) B[i++]=0;
  for (i=1;i<=A[0];i++)
    A[i]+= (T=(A[i]-=B[i]+T)<0) ? 10 : 0;
  while (!A[A[0]]&&A[0]>1) A[0]--;
}

int Sgn(Huge H1[NMAX], Huge H2[NMAX]) {
  while (H1[0] && !H1[H1[0]]) H1[0]--;
  while (H2[0] && !H2[H2[0]]) H2[0]--;

  if (H1[0] < H2[0]) {
    return -1;
  } else if (H1[0] > H2[0]) {
    return +1;
  }

  for (int i = H1[0]; i > 0; --i) {
    if (H1[i] < H2[i]) {
      return -1;
    } else if (H1[i] > H2[i]) {
      return +1;
    }
  }
  return 0;
}

void DivideHuge(Huge A[NMAX], Huge B[NMAX], Huge C[NMAX], Huge R[NMAX])
{ int i;

  R[0]=0;C[0]=A[0];
  for (i=A[0];i;i--)
    { Shl(R,1);R[1]=A[i];
      C[i]=0;
      while (Sgn(B,R)!=1)
        { C[i]++;
          Subtract(R,B);
        }
    }
  while (!C[C[0]] && C[0]>1) C[0]--;
}

void MultHuge(Huge A[NMAX], Huge B[NMAX], Huge C[NMAX])
{ int i,j,T=0;

  C[0]=A[0]+B[0]-1;
  for (i=1;i<=A[0]+B[0];) C[i++]=0;
  for (i=1;i<=A[0];i++)
    for (j=1;j<=B[0];j++)
      C[i+j-1]+=A[i]*B[j];
  for (i=1;i<=C[0];i++)
    { T=(C[i]+=T)/10;
      C[i]%=10;
    }
  if (T) C[++C[0]]=T;
}

int main()
{
    string xx, aa, bb;
    int n;
    cin >> xx >> aa >> bb >> n;

    for(int i = xx.size() - 1; i >= 0; --i)
        x[++x[0]] = xx[i] - '0';
    for(int i = aa.size() - 1; i >= 0; --i)
        a[++a[0]] = aa[i] - '0';
    for(int i = bb.size() - 1; i >= 0; --i)
        b[++b[0]] = bb[i] - '0';

    DivideHuge(a, b, rez, r);

    for(int i = 2; i <= n; ++i){
        MultHuge(x, rez, ax);
        for(int j = 1; j <= ax[0]; ++j)
            x[j] = ax[j];
        x[0] = ax[0];
    }

    for(int i = x[0]; i >= 1; --i)
        cout << x[i];
    return 0;
}
