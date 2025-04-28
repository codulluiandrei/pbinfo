/*
    Eugen Nodea
    Implementare stive
    Mediana - quickselect()
    Complexitate O(n)
*/
# include <fstream>
# include <cstring>
# include <algorithm>
# define nmax 100002
# define swap(a,b) temp=(a);(a)=(b);(b)=temp;
using namespace std;
ifstream f("expresie7.in");
ofstream g("expresie7.out");
char ex[nmax];
int L,i,k,x,j,kd,kr,y,rst[nmax/2],dst[nmax/2];
int st[nmax],sm,Max,nr=0,S,sol;
//determinare mediana - alg. asemanator quicksort
int quickselect(int *a, int st, int dr, int k)
{
  int i,ir,j,l,mid;
  int p,temp;
  l=st; ir=dr;
  for(;;)
  {
    if (ir <= l+1)
    {
          if (ir == l+1 && a[ir] < a[l]) { swap(a[l],a[ir]); }
          return a[k];
    }
    else {
          mid=(l+ir) >> 1;
          swap(a[mid],a[l+1]);
          if (a[l] > a[ir])   { swap(a[l],a[ir]);   }
          if (a[l+1] > a[ir]) { swap(a[l+1],a[ir]); }
          if (a[l] > a[l+1])  { swap(a[l],a[l+1]);  }
          i=l+1; j=ir;
          p=a[l+1];
          for (;;)
          {
            do i++; while (a[i] < p);
            do j--; while (a[j] > p);
            if (j < i) break;
            swap(a[i],a[j]);
          }
          a[l+1]=a[j]; a[j]=p;
          if (j >= k) ir=j-1;
          if (j <= k) l=i;
        }
  }
}
int main()
{
	f.getline(ex,nmax);
	L=strlen(ex);
	i=k=kd=kr=0;
	while (i < L)
	{
		if (ex[i] == '(')
		{
			++i; rst[++kr]=k+1;
		}
		if (ex[i] == '[')
		{
			++i; dst[++kd]=k+1;
		}
		if ('0' <= ex[i] && ex[i] <= '9' || ex[i] == '-')
		{
                        if (ex[i] == '-') sm=-1, ++i;
                                     else sm=1;
			x=0;
			while ('0' <= ex[i] && ex[i] <= '9' && i < L)
			{
				x=x*10+ex[i]-'0';
				++i;
			}
			st[++k]=sm*x;
			if (ex[i] == ',') ++i,++nr;
		}
		if (ex[i] == ')')
		{    	//determinam subsecventa de suma maxima
			x=rst[kr];
			S=st[x]; Max=S;
			for (j=x+1; j<=k; ++j)
                            {
                                if (S+st[j] < st[j]) S = st[j];
                                                else S += st[j];
                                if (S > Max) Max=S;
                            }
			k=x; --kr; st[k]=Max;
			++i;
		}
		if (ex[i] == ']')
		{ 	//determinam mediana
                        x=dst[kd];
                        y=quickselect(st,x,k,(k+x)/2);
                        k=x; --kd; st[k]=y;
                        ++i;
                }
		if (ex[i] == ',') ++i,++nr;
	}
	for (i=1, sol=0; i<=k; ++i)
	{
		sol += st[i];
	}
	g<< nr+1 <<'\n'<< sol <<'\n';
	return 0;
}