#include <iostream>
using namespace std;
int n,m,istart,jstart;
int a[15][15];
int gasit = 0;
const int di[]={-2,-2,-1,-1,+1,+1,+2,+2},
		  dj[]={-1,+1,-2,+2,-2,+2,-1,+1};
void afis(int n,int m){
	gasit = 1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
void back(int i, int j, int pas){
	if(!gasit)
		if(i>0 && j>0 && i<=n && j<=m && a[i][j]==0)
		{
			a[i][j] = pas;
			if(pas == n*m)
				afis(n,m);
			else
				for(int k=0 ; k<8 ; ++k)
					back(i+di[k],j+dj[k],pas+1);
			a[i][j] = 0;
		}
}
int main(){
	cin >> n >> m >> istart >> jstart;
	back(istart,jstart,1);
	return 0;
}