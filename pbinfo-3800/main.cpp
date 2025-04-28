int DistinctLetters(string s, int L, int U)
{
    int answer = 0;
    int cnt, j, i, n;
    int fr[26] = {0};
    n = s.length();
    // numaram cate secvente au cel mult U litere distincte
    cnt = j = 0;
    for (i = 0; i < n; i++)
    {
        fr[s[i] - 'a']++;
        if (fr[s[i] - 'a'] == 1) cnt++;
        while (cnt > U)
        {
            fr[s[j] - 'a']--;
            if (fr[s[j] - 'a'] == 0) cnt--;
            j++;
        }
        answer += (i - j + 1);
    }
    // scadem secventele care au cel mult L - 1 litere distincte
    for (i = 0; i < 26; i++)
        fr[i] = 0;
    cnt = j = 0;
    for (i = 0; i < n; i++)
    {
        fr[s[i] - 'a']++;
        if (fr[s[i] - 'a'] == 1) cnt++;
        while (cnt > L - 1)
        {
            fr[s[j] - 'a']--;
            if (fr[s[j] - 'a'] == 0) cnt--;
            j++;
        }
        answer -= (i - j + 1);
    }
    return answer;
}