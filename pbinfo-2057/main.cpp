#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin("admitere.in");
    ofstream cout("admitere.out");

    int tip, n, m; cin >> tip >> n >> m;

    vector<vector<int>> fixedGrades(2, vector<int> (m, 0));
    vector<vector<int>> currGrades(n, vector<int> (2, 0));

    for(int i = 0; i < 2; ++i)
       for(int j = 0; j < m; ++j)
           cin >> fixedGrades[i][j];

    for(int i = 0; i < n; ++i)
       cin >> currGrades[i][0] >> currGrades[i][1];
    
    vector<vector<int>> frontAlready(2, vector<int> (n, 0));
	vector<vector<int>> p(2, vector<int> (n, 0));

    for(int c = 0; c < 2; ++c) {
        for(int i = 0; i < n; ++i) 
            p[c][i] = i;
        sort(p[c].begin(), p[c].end(), [&] (int a, int b) {
            return currGrades[a][c] < currGrades[b][c];
        });
    }
    
    for(int c = 0; c < 2; ++c) 
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(fixedGrades[c][j] > currGrades[i][c])
                    frontAlready[c][i]++;
    
    int bestAns = 0;
    string bestConfig(n, 'X');
    string label = "RU";
    
    auto realityCheck = [&] (string config) -> string {
        for(int c = 0; c < 2; ++c) {
            int greaterFriends = 0;
            for(int i = n - 1; i >= 0; --i) {
                if(config[p[c][i]] != label[c])
                    continue;
                if(greaterFriends + frontAlready[c][p[c][i]] >= m)
                    config[p[c][i]] = 'X';
                greaterFriends++;
            }
        }
        return config;
    };

    for(int c = 0; c < 2; ++c) {
        string config(n, label[c]);
        config = realityCheck(config);

        int temp = 0;
        for(int i = 0; i < n; ++i)
            if(config[i] != 'X')
                ++temp;

        if(temp > bestAns) {
            bestAns = temp;
            bestConfig = config;
        }
    }

    if(tip == 1) {
        cout << bestAns << "\n";
        cout << bestConfig << "\n";
        return 0;
    }
    
    const int REAL = 0, UMAN = 1;

    for(int minFirst = 0; minFirst < n; ++minFirst) {
        string config(n, 'X');
        config[minFirst] = label[REAL];
        
        int space = m - 1;
        for(int i = 0; i < m; ++i)
            if(fixedGrades[REAL][i] > currGrades[minFirst][REAL])
                space--;
        
        for(int i = 0; i < n; ++i) {
            if(p[UMAN][i] == minFirst)
                continue;
            if(currGrades[p[UMAN][i]][REAL] > currGrades[minFirst][REAL] && space > 0) { 
                config[p[UMAN][i]] = label[REAL];
                space--;
            } else {
                config[p[UMAN][i]] = label[UMAN];
            }
        }
        
        config = realityCheck(config);
        int temp = 0;
        for(int i = 0; i < n; ++i)
            if(config[i] != 'X')
                temp++;
        
        if(temp > bestAns) {
            bestAns = temp;
            bestConfig = config;
        }
    }
        
    cout << bestAns << "\n";
    cout << bestConfig << "\n";
} 