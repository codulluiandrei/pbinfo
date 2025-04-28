#include <iostream>
#include <cstring>
using namespace std;
int main(){
	char s[101];
	cin.getline(s , 101);
	bool gasit = false;
	for(int i = 0 ; i < strlen(s) ; i ++)
		if(s[i] != ' ')
		{
			int j = i;
			while(s[j + 1] >= 'a' && s[j + 1] <= 'z')
				j ++;
			if((j - i + 1) % 2 == 1 && j - i + 1 >= 3)
			{
				gasit = true;
				i += (j - i) / 2;
				while(s[i])
					s[i] = s[i+1] , i ++;
			}
			i = j;
		}
	if(!gasit)
		strcpy(s, "nu exista");
	cout << s ;
	return 0;
}