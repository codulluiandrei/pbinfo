#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("textcuv.in");
ofstream fout("textcuv.out");
char a[1003];
char cuv[502][52];
int n, T;
int main()
{
    int i;
    char *p, sep[] = " .,!?:;-";
    fin >> T;
    fin.get();
    fin.getline(a, 1001);
    p = strtok(a, sep);
    while (p != NULL)
    {
        strcpy(cuv[n], p);
        n++;
        p = strtok(NULL, sep);
    }
    if (T == 1)
    {
        fout << n << "\n";
        for (i = 0; i < n; i++)
            fout << cuv[i] << "\n";
    }
    else if (T == 2)
    {
        char cuvMin[52];
        strcpy(cuvMin, cuv[0]);
        for (i = 1; i < n; i++)
            if (strcmp(cuvMin, cuv[i]) > 0)
                strcpy(cuvMin, cuv[i]);
        fout << cuvMin << "\n";
    }
    else if (T == 3)
    {
        int nrCuv = 0;
        for (i = 0; i < n; i++)
            if (strstr(cuv[i], "ini") != 0)
                nrCuv++;
        fout << nrCuv << "\n";
    }
    else if (T == 4)
    {
        for (i = 0; i < n; i++)
        {
            for (int j = strlen(cuv[i]) - 1; j >= 0; j--)
                fout << cuv[i][j];
            fout << "\n";
        }
    }
    else if (T == 5)
    {
        int nrCuv = 0;
        for (i = 0; i < n; i++)
        {
            int k = strlen(cuv[i]);
            if (cuv[i][k - 1] == 'a') nrCuv++;
        }
        fout << nrCuv << "\n";
    }
    else /// T == 6
    {
        int minLen = 100, maxLen = 0;
        for (i = 0; i < n; i++)
        {
            int k = strlen(cuv[i]);
            if (minLen > k) minLen = k;
            if (maxLen < k) maxLen = k;
        }
        fout << minLen << " " << maxLen << "\n";
    }
    return 0;
}