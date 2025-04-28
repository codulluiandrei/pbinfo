//Varianta medie
#include "fstream"
std::ifstream cin("hugecontrol.in");
std::ofstream cout("hugecontrol.out");
int main()
{
    long long S=0;
    char N;
    while(cin >> N)
    {
        S+= N - '0';
    }
    while(S >= 10)
    {
		int S1 = 0;
		while(S!=0)
		{
			S1+=S%10, S/=10;
        }
		S = S1;
	}
	cout<<S;
}