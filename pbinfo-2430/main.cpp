//
//  main.cpp
//  zebras
//
//  Created by Radu Costache on 09.03.2018.
//  Copyright © 2018 Radu Costache. All rights reserved.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int i,j,nr0,nr1;
queue<int>p1;
queue<int>p0;
char v[200005];
int nrsol,nr;
vector <int> s[200005];
int main(int argc, const char * argv[]) {
    // insert code here...
    while(cin >> v[++i]){
        v[i] -= '0';
        if(v[i] == 1 && nr0 == 0){cout << -1 << '\n';return 0;}
        else if(v[i] == 0 && nr1 == 0)
            ++nrsol,s[nrsol].push_back(i),nr0++,p0.push(nrsol);
        else if(v[i] == 0){
            s[p1.front()].push_back(i);
            nr0++;nr1--;p0.push(p1.front());p1.pop();
        }
        else if(v[i] == 1){
            s[p0.front()].push_back(i);
            nr1++;nr0--;p1.push(p0.front());p0.pop();
        }
        /*else for(j = 1 ; j <= nrsol ; ++j){
            if(v[s[j][s[j].size() - 1]] != v[i]){
                if(v[i] == 1){nr1++;nr0--;p1 = j;if(p0 == j)p0 = -1;}
                else {nr0++;nr1--;p0 = j;if(p1 == j)p1 = -1;}
                ok = 1;
                s[j].push_back(i);
                break;
            }
        }*/
    }
    if(nr1 == 0){
        cout << nrsol << '\n';
        for(i = 1 ; i <= nrsol ; ++i){
            cout << s[i].size() << ' ';
            for(j = 0 ; j < s[i].size() ; ++j)
                cout << s[i][j] << ' ';
            cout << '\n';
        }
    }
    else cout << -1 << '\n';
    return 0;
}