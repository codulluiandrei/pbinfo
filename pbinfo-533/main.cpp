#include <iostream>
using namespace std;
int sex[105], elevi[105], inaltime[105], n;
int main(){
	cin  >> n;
	char s;	
	for(int i = 1 ; i <= n ; ++i)
	{
		elevi[i] = i;
		cin >> s >> inaltime[i];
		if(s == 'B')
			sex[i] = 1;
		else
			sex[i] = 0;
	}
	for(int i = 1 ; i < n ; ++i)
		for(int j = i + 1 ; j <= n ; ++j)
			if(sex[i] < sex[j])
			{
				int aux;
				aux = sex[i]; sex[i] = sex[j]; sex[j] = aux;
				aux = inaltime[i]; inaltime[i] = inaltime[j]; inaltime[j] = aux;
				aux = elevi[i]; elevi[i] = elevi[j] ; elevi[j] = aux;
			}
			else
				if(sex[i] == sex[j])
					if(inaltime[i] < inaltime[j])
					{
						int aux;
						aux = inaltime[i]; inaltime[i] = inaltime[j]; inaltime[j] = aux;
						aux = elevi[i]; elevi[i] = elevi[j] ; elevi[j] = aux;
					}
					else
						if(inaltime[i] == inaltime[j])
							if(elevi[i] > elevi[j])
							{
								int aux;
								aux = elevi[i]; elevi[i] = elevi[j] ; elevi[j] = aux;
							}
	for(int i = 1; i <= n ; ++i)
		cout << elevi[i] << " ";
	return 0;
}