/*
    Stelian Ciurea
    lungimea maxima in k^2
    Complexitate: O(n*n)
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <cstdlib>
#include <algorithm>
#define kmax 1000000
#define nmax 1000
using namespace std;
struct obstacol { int x,y;};
struct nod {
	int x,y,nrpasi;};
obstacol obs[kmax];
int a[nmax+2][nmax+2], opt[nmax+2][nmax+2];
nod poz1[nmax+2], poz2[nmax+2];
int n, xl1, xl2, yl1, yl2, xt, yt, xr1, xr2, yr1, yr2, x, y;
int i,j,k,t,nrpoz1,nrpoz2,lmax,lc,kt;
ifstream fin("ai.in");
ofstream fout("ai.out");
int min11, min12, min21, min22;
int depx[4]={0,1,0,-1};
int depy[4]={1,0,-1,0};
int compx(obstacol a, obstacol b)
{
	if (a.x > b.x)
		return 0;
	if (a.x == b.x && a.y > b.y)
		return 0;
	return 1;
}
int compy(obstacol a, obstacol b)
{
	if (a.y > b.y)
		return 0;
	if (a.y == b.y && a.x > b.x)
		return 0;
	return 1;
}
void Lee(int xst, int yst)
{
	queue <int> qx,qy;
	int xu, yu, i, xc, yc;
	qx.push(xst); qy.push(yst);
	opt[xst][yst] = 0;
	while (!qx.empty())
	{
		xc = qx.front(); yc=qy.front();
		qx.pop(); qy.pop();
		for (i=0;i<4;i++)
		{
			xu = xc + depx[i];
			yu = yc + depy[i];
			if (a[xu][yu] == 0)
				if (opt[xu][yu] > opt[xc][yc] + 1)
				{
					opt[xu][yu] = opt[xc][yc] + 1;
					qx.push(xu);
					qy.push(yu);
				}
		}
	}
}
int ggt(int a, int b)
{
	while (a!=b)
		if (a>b) a-=b; else b-=a;
	return a;
}
void calcpoz(int xl1, int yl1, nod poz1[], int &nrpoz)
{
	int i,d,dx,dy,t=0;
	dx = xt - xl1; dy = yt - yl1;
	if (dx == 0)  //sunt in linie
			if (yt < yl1)
				for (i= yt+1; i<=yl1; i++)
					poz1[t].x = xt, poz1[t].y=i, t++;
			else
				for (i= yl1; i<yt; i++)
					poz1[t].x = xt, poz1[t].y=i, t++;
	else
		if (dy == 0)  //sunt in coloana
			if (xt < xl1)
				for (i= xt+1; i<=xl1; i++)
					poz1[t].x = i, poz1[t].y=yt, t++;
			else
				for (i= xl1; i<xt; i++)
					poz1[t].x = i, poz1[t].y=yt, t++;
		else
		{
			d = ggt(abs(dx),abs(dy));
			dx = abs(dx)/d, dy=abs(dy)/d;
			if (xl1 < xt && yl1 < yt)
				for (t=0,x=xl1,y=yl1;x+dx*t<xt;t++)
					poz1[t].x=x+dx*t, poz1[t].y=y+dy*t;
			if (xl1 > xt && yl1 > yt)
				for (t=0,x=xl1,y=yl1;x-dx*t>xt;t++)
					poz1[t].x=x-dx*t, poz1[t].y=y-dy*t;
			if (xl1 < xt && yl1 > yt)
				for (t=0,x=xl1,y=yl1;x+dx*t<xt;t++)
					poz1[t].x=x+dx*t, poz1[t].y=y-dy*t;
			if (xl1 > xt && yl1 < yt)
				for (t=0,x=xl1,y=yl1;x-dx*t>xt;t++)
					poz1[t].x=x-dx*t, poz1[t].y=y+dy*t;
		}
	nrpoz=t;
}
int main()
{
	fin >> n;
	fin >> xt >> yt >> xl1 >> yl1 >> xl2 >> yl2 >> xr1 >> yr1 >> xr2 >> yr2;
	fin >> k;
	for (i=1;i<=k;i++)
	{
		fin >> x >> y;
		obs[i].x=x; obs[i].y=y;
		a[x][y]=1;
		kt++;
	}
//	cout << kt << endl;
	lmax = 0;
	sort(obs+1,obs+k+1,compx);
	for (i=1;i<=k;i++)
	{
		//cout << obs[i].x<<" "<<obs[i].y<<"     ";
		if (obs[i].x == obs[i-1].x && obs[i].y == obs[i-1].y+1)
			lc++;
		else
			lc=0;
		if (lc > lmax)
			lmax = lc;
	}
	sort(obs+1,obs+k+1,compy);
	for (i=1;i<=k;i++)
	{
		//cout << obs[i].x<<" "<<obs[i].y<<"     ";
		if (obs[i].y == obs[i-1].y && obs[i].x == obs[i-1].x+1)
			lc++;
		else
			lc=0;
		if (lc > lmax)
			lmax = lc;
	}
	if (lmax>=1)
		fout << lmax+1 << '\n';
	else
		fout << "0\n";
	calcpoz(xl1,yl1,poz1,nrpoz1);
//	for (i=0;i<nrpoz1;i++)
//		cout << poz1[i].x<<" "<<poz1[i].y<<endl;
	calcpoz(xl2,yl2,poz2,nrpoz2);
//	for (i=0;i<nrpoz2;i++)
//		cout << poz2[i].x<<" "<<poz2[i].y<<endl;
	for (i=0;i<=n+1;i++)
		a[i][0] = a[0][i] = a[n+1][i] = a[i][n+1] = 1;
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			opt[i][j] = n*n+1;
	a[xt][yt] = 1;
	Lee(xr1, yr1);
	min11 = min12 = n*n + 2;
	for (i=0;i<nrpoz1;i++)
	{
		x = poz1[i].x; y = poz1[i].y;
		if (min11 > opt[x][y])
			min11 = opt[x][y];
	}
	for (i=0;i<nrpoz2;i++)
	{
		x = poz2[i].x; y = poz2[i].y;
		if (min12 > opt[x][y])
			min12 = opt[x][y];
	}
	cout << min11<<" " << min12 << endl;
	/*
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			cout.width(4);
			cout << opt[i][j];
		}
		cout << endl;
	}
	*/
	Lee(xr2, yr2);
	min21 = min22 = n*n + 2;
	for (i=0;i<nrpoz1;i++)
	{
		x = poz1[i].x; y = poz1[i].y;
		if (min21 > opt[x][y])
			min21 = opt[x][y];
	}
	for (i=0;i<nrpoz2;i++)
	{
		x = poz2[i].x; y = poz2[i].y;
		if (min22 > opt[x][y])
			min22 = opt[x][y];
	}
	cout << min21<<" " << min22 << endl;
	/*
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			cout.width(4);
			cout << opt[i][j];
		}
		cout << endl;
	}
	*/
	if (max(min11,min22) < max(min12,min21))
		fout << max(min11, min22) << endl;
	else
		fout << max(min12, min21) << endl;
    fin.close();
    fout.close();
	return 0;
}