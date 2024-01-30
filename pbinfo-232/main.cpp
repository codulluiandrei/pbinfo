#include <iostream>
#include <cstring>

using namespace std;


int main(){
	char s[105];
	cin.getline(s , 105);
	for(int i = 0 ; i < strlen(s) ; ++ i)
		if(strchr("0123456789" , s[i]))
    	{
			int j = i + 1 , punct = 0;
			while(s[j] && strchr("0123456789." , s[j])){
				if(s[j] == '.')
					punct = 1;
				j ++;
			}
			if(punct){
                char X[105];
                strcpy(X , s + j);
				strcpy(s + i , X);
				i --;
			}
		}
	cout << s;
	return 0;
}
