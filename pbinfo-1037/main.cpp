#include<fstream>
using namespace std;
#define MOD 20011
int n,k,v[100010],i,sol,x,t,r[50010],s;
unsigned long long sol1;
ifstream f("calcule.in");
ofstream g("calcule.out");
int bs(int a){
	int s=0,d,m;
	for(d=sol;s<d;){
		m=(s+d)/2;
		if(v[m]>=a)
			s=m+1;
		else
			d=m;
	}
	return s;
}
int main(){
	f>>n>>k;
	for(i=1;i<=n;++i){
		f>>x;
		s=(s+x)%k;
		r[s]++;
		t=bs(x);
		v[t]=x;
		if(t==sol)
			++sol;
	}
	sol1=((r[0]%MOD)*((r[0]%MOD)+1)/2)%MOD;
	for(i=1;i<k;++i)
		sol1=(sol1+((r[i]%MOD)*((r[i]%MOD)-1)/2)%MOD)%MOD;
	g<<sol<<'\n'<<sol1<<'\n';
	g.close();
	return 0;
}