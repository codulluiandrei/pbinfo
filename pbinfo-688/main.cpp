#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
ifstream f("pixy.in");
ofstream g("pixy.out");
int dx[4]={-1, 0,0,1};
int dy[4]={ 0,-1,1,0};
struct pct{
	int cost,dist,dir;
	char cul;
};
pct T[510][510];
int n,m;
queue< pair<int,int> > q;
int nr;
char C;
void citire()
{
	char s[510];
	f>>m>>n; f.get();
	for (int i=0;i<m;i++)
	{
		f.getline(s,510);
		for (int j=0;j<n;j++)
			T[i][j].cul=s[j];
	}
	f.close();
}
int main()
{
	int x,y,x1,y1,c1,d1,i;
	citire();
	T[0][0].cost=1; T[0][0].dist=1;
	q.push(make_pair(0,0));
	while (!q.empty())
	{
		x=q.front().first; y=q.front().second;
		q.pop();
		for (i=0;i<4;i++)
		{
			x1=x+dx[i];
			y1=y+dy[i];
			if ( x1>=0 && x1<m && y1>=0 && y1<n)
			{
				d1=T[x][y].dist+1;
				c1=T[x][y].cost;
				if (T[x][y].cul != T[x1][y1].cul)
					c1++;
				if (T[x1][y1].cost==0 || c1<T[x1][y1].cost || (c1==T[x1][y1].cost && d1<T[x1][y1].dist))
				{
					T[x1][y1].cost=c1;
					T[x1][y1].dist=d1;
					T[x1][y1].dir=i;
					q.push(make_pair(x1,y1));
				}
			}
		}
	}
	g<<T[m-1][n-1].cost-1<<"\n";
	g<<T[m-1][n-1].dist-1<<"\n";
	g.close();
}