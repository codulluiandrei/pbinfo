#include <fstream>
using namespace std;
char a[50][50], b[50][50];
int main()
{
	int n , m , i , j , s , v , x = 1;
	long t , k;
	ifstream f("culori1.in");
	ofstream g("culori1.out");
	f >> n >> m  >> t;
	for(i = 1 ; i <= n ; i++)
		for(j = 1 ; j <= m ; j++)
			f >> a[i][j];
	for(k = 1; k<=t && x ; k++)
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
			{
				s=0;v=0; b[i][j]=a[i][j];
				if(j>1)
					if (a[i][j-1]=='a')
						s++;
					else 
						v++;
				if(j<m)
					if (a[i][j+1]=='a')
						s++;
					else
						v++;
				if(i>1)
					if (a[i-1][j]=='a')
						s++;
					else
						v++;
				if(i<n)
					if (a[i+1][j]=='a')
						s++;
					else
						v++;
				if(i>1 && j>1)
					if (a[i-1][j-1]=='a')
						s++;
					else
						v++;
				if(i>1 && j<m)
					if (a[i-1][j+1]=='a')
						s++;
					else
						v++;
				if(i<n && j>1)
					if (a[i+1][j-1]=='a')
						s++;
					else
						v++;
				if(i<n && j<m)
					if (a[i+1][j+1]=='a')
						s++;
					else
						v++;
				if (s<v)
					b[i][j]='r';
				else
					if(s>v)
						b[i][j]='a';
			}
		x=0;
		for(i = 1 ; i <=n && !x ; i++)
			for(j = 1 ; j <= m ; j++)
				if(a[i][j] != b[i][j]) 
				{
					x=1;
					break;
				}
		if(x)
			for(i=1;i<=n;i++)
				for(j=1;j<=m;j++)
					a[i][j]=b[i][j];
		else 
			break;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			g<<a[i][j];
		g<<endl;   
	}
	f.close();
	g.close();
	return 0;
  }