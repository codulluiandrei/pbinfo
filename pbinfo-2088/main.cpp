#include<bits/stdc++.h>
using namespace std;
stack <int> numar;
stack <char> subsir;
string S;
string decodif(string S){
    string aux = "", sol = "";
    for (int i = 0; i < (int) S.length(); ++i){
        int nr = 0;
        if (S[i] >= '0' && S[i] <='9'){
            while (S[i] >= '0' && S[i] <= '9'){
                nr = nr * 10 + (S[i] - '0');
                i++;
            }
            i--;
            numar.push(nr);
        }
        else if (S[i] == ']') {
            aux = "";
            nr = 0;
            if (! numar.empty()) {
                nr = numar.top();
                numar.pop();
            }
            while (! subsir.empty() && subsir.top()!='[' ) {
                aux = subsir.top() + aux;
                subsir.pop();
            }
            if (! subsir.empty() && subsir.top() == '[') subsir.pop();
            for (int j = 0; j < nr; j++)
                sol = sol + aux;
            for (int j = 0; j < (int) sol.length(); j++)
                subsir.push(sol[j]);
            sol = "";
        }
        else if (S[i] == '[') {
            if (S[i-1] >= '0' && S[i-1] <= '9')
                subsir.push(S[i]);
            else {
                subsir.push(S[i]);
                numar.push(1);
            }
        }
        else
            subsir.push(S[i]);
    }
    while (! subsir.empty()) {
        sol = subsir.top() + sol;
        subsir.pop();
    }
    return sol;
}
int main()
{
    cin >> S;
    cout << decodif(S) << '\n';
    return 0;
}