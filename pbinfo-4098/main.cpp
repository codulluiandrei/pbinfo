/// Andrei Cotor - Universitatea Babes Bolyai Cluj Napoca
#include <fstream>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct PULSAR
{
    int x,y,r,t;
};
struct QSTATE
{
    int cost,x,y,st;
    bool operator<(const QSTATE &other) const
    {
        return (this->cost)>(other.cost);
    }
};
int getLCM(int x, int y)
{
    return (x*y)/__gcd(x,y);
}
int manhattanDist(int x, int y, int xx, int yy)
{
    return abs(x-xx)+abs(y-yy);
}
PULSAR PS[15005];
bool state[65][505][505];
const int dx[]={-1, 0, 1, 0, 0};
const int dy[]={0, 1, 0, -1, 0};
void fillDist(int x, int y, int xs, int ys, int dist, int st, int N)
{
    state[st][x][y]=1;
    if(manhattanDist(x, y, xs, ys)<dist)
    {
        for(int d=0; d<4; d++)
        {
            if(x+dx[d]>0 && x+dx[d]<=N && y+dy[d]>0 && y+dy[d]<=N && manhattanDist(x+dx[d], y+dy[d], xs, ys)>manhattanDist(x, y, xs, ys))
            {
                fillDist(x+dx[d], y+dy[d], xs, ys, dist, st, N);
            }
        }
    }
}
int Cost[65][505][505];
int main()
{
    ifstream fi("pulsar.in");
    int C,N,P;
    fi>>C>>N>>P;
    int lcm=1;
    for(int i=0; i<P; i++)
    {
        int x,y,r,t;
        fi>>x>>y>>r>>t;
        lcm=getLCM(r,lcm);
        PS[i]={x,y,r,t};
    }
    int xs,ys,xd,yd;
    fi>>xs>>ys>>xd>>yd;
    fi.close();
    for(int i=0; i<lcm; i++)
    {
        for(int j=0; j<P; j++)
        {
            fillDist(PS[j].x, PS[j].y, PS[j].x, PS[j].y, PS[j].t, i, N);
            PS[j].t=(PS[j].t+1)%PS[j].r;
        }
    }
    if(C==1)
    {
        int rez1=0;
        for(int i=0; i<lcm; i++)
        {
            int nr=0;
            for(int j=1; j<=N; j++)
            {
                for(int k=1; k<=N; k++)
                {
                    nr+=state[i][j][k];
                }
            }
            rez1=max(rez1, nr);
        }
        ofstream fo("pulsar.out");
        fo<<rez1<<"\n";
        fo.close();
        return 0;
    }
    for(int i=0; i<lcm; i++)
    {
        for(int j=1; j<=N; j++)
        {
            for(int k=1; k<=N; k++)
            {
                Cost[i][j][k]=1000000000;
            }
        }
    }
    priority_queue<QSTATE> Q;
    Q.push({0, xs, ys, 0});
    Cost[0][xs][ys]=0;
    while(!Q.empty())
    {
        QSTATE cr=Q.top();
        Q.pop();
        if(Cost[cr.st][cr.x][cr.y]<cr.cost)
            continue;
        for(int d=0; d<5; d++)
        {
            QSTATE nxt;
            nxt={cr.cost+1, cr.x+dx[d], cr.y+dy[d], (cr.st+1)%lcm};
            if(nxt.x>0 && nxt.x<=N && nxt.y>0 && nxt.y<=N && !state[nxt.st][nxt.x][nxt.y])
            {
                if(Cost[nxt.st][nxt.x][nxt.y]>nxt.cost)
                {
                    Cost[nxt.st][nxt.x][nxt.y]=nxt.cost;
                    Q.push(nxt);
                }
            }
        }
    }
    int rez=1000000000;
    for(int i=0; i<lcm; i++)
    {
        rez=min(rez, Cost[i][xd][yd]);
    }
    ofstream fo("pulsar.out");
    fo<<rez<<"\n";
    fo.close();
    return 0;
}