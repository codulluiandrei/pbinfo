#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
char S[256], T [256], A[100][256], B[100][256];
int n , m;
bool litera_mica(char X) { 	return X >= 'a' && X <= 'z'; }
bool litera_mare(char X) {  return X >= 'A' && X <= 'Z'; }
char to_lower(char X)
{
	if(litera_mare(X))
		return X + ('a' - 'A');
	return X;
}
void lowercase(char * s)
{
	for(int i = 0 ; s[i] ; i ++)
		s[i] = to_lower(s[i]);
}
void extract(char *S , int &n , char A[][256])
{
	char * p = strtok(S, " ");	
	while(p)
	{
		bool gasit = false;
		for(int i = 1 ; i <= n && !gasit ; i ++)
			if(strcmp(p , A[i]) == 0)
				gasit = true;
		if(!gasit)
		{
			++n;
			strcpy(A[n] , p);
		}
		p = strtok(NULL , " ");
	}
}
void sortare(int &n , char A[][256])
{
	char x[256];
	for(int i = 1 ; i < n ; i ++)
		for(int j = i + 1 ; j <= n ; j ++)
			if(strcmp(A[i] , A[j]) > 0)
			{
				strcpy(x , A[i]);
				strcpy(A[i] , A[j]);
				strcpy(A[j] , x);
			}
}
void afisare()
{
	for(int i = 1 ; i <= n ; i ++)
	{
		bool gasit = false;
		for(int j = 1 ; j <= n && !gasit ; j ++)
			if(strcmp(B[j] , A[i]) == 0)
				gasit = true;
		if(gasit)
			cout << A[i] <<"\n";
	}
}
int main()
{
	cin.getline(S , 256);
	cin.getline(T , 256);
	lowercase(S);
	lowercase(T);
	extract(S, n, A);
	sortare(n , A);
	extract(T, m, B);
	afisare();
	return 0;
}