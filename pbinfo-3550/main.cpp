#include <bits/stdc++.h>
using namespace std;
ifstream fin ("liceu.in");
ofstream fout ("liceu.out");
int xd[4]={1,-1,0,0};
int yd[4]={0,0,1,-1};
int n,z,s,tmagazin=-1,tclasa,tmax;
pair<int,int> magazin;
int liceu[405][405],t1[405][405],t2[405][405];
vector<pair<int,int> > shortcut;
void backtrack(pair<int,int> s, pair<int,int> f, int t[405][405] ,vector<pair<int,int> >& traseu)
{
    int x=f.first;
    int y=f.second;
    int d=t[x][y];
    bool ok;
    while (x!=s.first||y!=s.second)
    {
        traseu.push_back(make_pair(x,y));
        ok=false;
        for (int i=0;i<4;i++)
        {
            if (t[x+xd[i]][y+yd[i]]==d-1)
            {
                x+=xd[i];
                y+=yd[i];
                ok=true;
                break;
            }
        }
        if (ok==false)
        {
            pair<int,int> p=shortcut[liceu[x][y]];
            x= p.first;
            y= p.second;
        }
        d--;
    }
}
int main()
{
    fin >>n>>z>>s>>tmax;
    shortcut.reserve(s*2+1);
    shortcut.emplace_back(0,0);
    /// input & bordare
    {
        int x,y,x2,y2;
        for (int i=1;i<=z;i++)
        {
            fin>>x>>y;
            liceu[x][y]=-1;
        }
        for (int i=1;i<=s;i++)
        {
            fin>>x>>y>>x2>>y2;
            shortcut.emplace_back(x,y);
            shortcut.emplace_back(x2,y2);
            liceu[x][y] = i*2;
            liceu[x2][y2] = i*2-1;
        }
        fin>> magazin.first>> magazin.second;
        for (int i=1;i<=n;i++)
        {
            t1[0][i]=t1[n+1][i]=t1[i][0]=t1[i][n+1]=-1;
            t2[0][i]=t2[n+1][i]=t2[i][0]=t2[i][n+1]=-1;
        }
    }
    /// lee 1 (start -> magazin && clasa)
    {
        bool classFound=false,magFound=false;
        queue<pair<int,int> > q;
        q.push(make_pair(1,1));
        t1[1][1]=1;
        while(!q.empty()&&!(classFound&&magFound) )
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x==n&&y==n)
            {
                classFound=true;
                tclasa=t1[x][y];
            }
            if (x==magazin.first&&y==magazin.second)
            {
                t2[x][y]=t1[x][y];
                magFound=true;
            }
            ///verificima in sus,jos,stanga,dreapta
            for (int i=0;i<4;i++)
            {
                if (liceu[x+xd[i]][y+yd[i]]!=-1&&t1[x+xd[i]][y+yd[i]]==0)
                {
                    t1[x+xd[i]][y+yd[i]]=t1[x][y]+1;
                    q.push(make_pair(x+xd[i],y+yd[i]));
                }
            }
            ///verificam daca sunt pe o scurtatura
            if (liceu[x][y]!=0)
            {
                pair<int,int> p = shortcut[liceu[x][y]];
                if (t1[p.first][p.second]==0)
                {
                    t1[p.first][p.second]=1+t1[x][y];
                    q.push(make_pair(p.first,p.second));
                }
            }
        }
        if (!classFound)///pt generatorul de teste
        {
            fout<<"nopath";
            fin.close();
            fout.close();
            return 69;
        }
    }
    /// lee 2 (magazin -> clasa)
    {
        queue<pair<int,int> > q;
        q.push(make_pair(magazin.first,magazin.second));
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x==n&&y==n)
            {
                tmagazin=t2[x][y];
                break;
            }
            ///verificima in sus,jos,stanga,dreapta
            for (int i=0;i<4;i++)
            {
                if (liceu[x+xd[i]][y+yd[i]]!=-1&&t2[x+xd[i]][y+yd[i]]==0)
                {
                    t2[x+xd[i]][y+yd[i]]=t2[x][y]+1;
                    q.push(make_pair(x+xd[i],y+yd[i]));
                }
            }
            ///verificam daca sunt pe o scurtatura
            if (liceu[x][y]!=0)
            {
                pair<int,int> p = shortcut[liceu[x][y]];
                if (t2[p.first][p.second]==0)
                {
                    t2[p.first][p.second]=1+t2[x][y];
                    q.push(make_pair(p.first,p.second));
                }
            }
        }
    }
    ///
    vector<pair<int,int> > traseu;
    if (tmagazin!=-1&&tmagazin<=tmax)
    {
        traseu.reserve(tmagazin-1);
        fout<<tmagazin<<'\n';
        ///facem traseul start -> magazin -> clasa
        backtrack(magazin,make_pair(n,n),t2,traseu);
        backtrack(make_pair(1,1),magazin,t1,traseu);
        traseu.push_back(make_pair(1,1));
    }
    else
    {
        traseu.reserve(tclasa);
        fout<<tclasa<<'\n';
        ///facem traseul start -> clasa
        backtrack(make_pair(1,1),make_pair(n,n),t1,traseu);
        traseu.push_back(make_pair(1,1));
    }
    for (int i=traseu.size()-1;i>=0;i--)
    {
        fout<<traseu[i].first<<" "<<traseu[i].second<<'\n';
    }
    fin.close();
    fout.close();
    return 0;
}