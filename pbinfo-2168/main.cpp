#include <bits/stdc++.h>
using namespace std;
char s[1605], st[1002][35], f[102][260];
int n;
int main()
{
	int top, k, i, j;
	char folder[35];
	char fisier[35];
	char cale[260];
    ifstream fin("dir.in");
	ofstream fout("dir.out");
	fin >> s;
	top = 0;
	for (i = 0; s[i] != 0; )
	{
		if ('A'<= s[i] && s[i] <= 'Z')
		{
			k = 0;
			while (s[i] != 0 && s[i] != ')' && s[i] != '(' && s[i] != ',')
			{
				folder[k++] = s[i];
				i++;
            }
            folder[k] = 0;
            top++;
            strcpy(st[top],folder);
        }
       else if ('a'<= s[i] && s[i] <= 'z')
        {
            k = 0;
            while (s[i] != 0 && s[i] != ')' && s[i] != '(' && s[i] != ',')
            {
                fisier[k++] = s[i];
                i++;
            }
			fisier[k] = 0;
			//st=F1, F2, F3
			strcpy(cale,st[1]);
			strcat(cale,"\\");
			for (j = 2;j<=top; j++)
			{
				strcat(cale,st[j]);
				strcat(cale,"\\");
            }
        strcat(cale,fisier);
        n++;
        strcpy(f[n],cale);
        }
        else if (s[i] == '(') i++;
        else if (s[i] == ',') i++;
        else if (s[i] == ')')
        {
        i++;
        top--;
        }
    }
    /// sortare
    for (i = 1; i < n; ++i)
        for (j = i + 1; j <= n; j++)
            if (strcmp(f[i], f[j]) > 0)
            {
                strcpy(cale, f[i]);
                strcpy(f[i], f[j]);
                strcpy(f[j], cale);
            }
    fout << n << "\n";
    for (i = 1; i <= n; i++)
        fout << f[i] << "\n";
    fout.close();
    return 0;
}