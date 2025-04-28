#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
ifstream fin("changecase.in");
ofstream fout("changecase.out");
int n, cantitate[505];
char denumire[505][21];
bool litera_mica(char X) { 	return X >= 'a' && X <= 'z'; }
bool litera_mare(char X) {  return X >= 'A' && X <= 'Z'; }
char to_upper(char X)
{
	if(litera_mica(X))
		return X - ('a' - 'A');
	return X;
}
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
void uppercase(char * s)
{
	for(int i = 0 ; s[i] ; i ++)
		s[i] = to_upper(s[i]);
}
void titlecase(char * s)
{
	for(int i = 0 ; s[i] ; i ++)
		if(i == 0)
			s[i] = to_upper(s[i]);
		else
			if(strchr(".,; ", s[i-1]))
				s[i] = to_upper(s[i]);
			else
				s[i] = to_lower(s[i]);
}
void invertcase(char * s)
{
	for(int i = 0 ; s[i] ; i ++)
		if(i == 0)
			s[i] = to_lower(s[i]);
		else
			if(strchr(".,; ", s[i-1]))
				s[i] = to_lower(s[i]);
			else
				s[i] = to_upper(s[i]);
}
void sentencecase(char * s)
{
	lowercase(s);
	bool inside = false;
	for(int i = 0 ; s[i] ; i ++)
		if(litera_mica(s[i]))
		{
			if(!inside)
				s[i] = to_upper(s[i]), inside = true;
		}
		else
			if(s[i] == '.')
				inside = false;
}
int main()
{
	char tr[100], prop[256];
	fin.getline(tr , 100);
	fin.getline(prop , 256);
	if(strcmp(tr, "lowercase") == 0)
		lowercase(prop);
	if(strcmp(tr, "UPPERCASE") == 0)
		uppercase(prop);
	if(strcmp(tr, "TitleCase") == 0)
		titlecase(prop);
	if(strcmp(tr, "iNVERTcASE") == 0)
		invertcase(prop);
	if(strcmp(tr, "Sentencecase") == 0)
		sentencecase(prop);	
	fout << prop;
	return 0;
}