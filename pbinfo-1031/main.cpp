// prof. Carmen Popescu - Col. Nat. Gh. Lazar Sibiu
#include <fstream>
using namespace std;
ifstream f("culori2.in");
ofstream g("culori2.out");
int n;
string s;
void s_la_p(int p)
{
	string::iterator it;
	string::reverse_iterator rit;
	int i,t,c;
	for (i=1;i<=p;i++)
	{
		t=0;
		for ( it=s.begin() ; it<s.end(); it++)
		{	
			c=(*it)-'0';
			c=c*3+t;
			t=c/10;
			c=c%10;
			(*it)=c+'0';
		}
		if (t>0)
			s += t+'0';
	}
	for ( rit=s.rbegin(); rit<s.rend(); rit++)
		g<<(*rit);
	g<<"\n";
}
int main()
{
	int k;
	f>>n;
	if (n==1)
		g<<"5\n";
	else
		if (n==2)
			g<<"8\n";
		else
			if (n==3)
				g<<"14\n";
			else
			{
				if (n%2==0)
					s="8";
				else
					s="41";
				k=n/2;
				s_la_p(k-1);
			}
}