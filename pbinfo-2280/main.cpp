//
//  main.cpp
//  memory0008
//
//  Created by Radu Costache on 10/11/2017.
//  Copyright © 2017 Radu Costache. All rights reserved.
//

#include <fstream>

using namespace std;
unsigned long long n,i,ans,x;

ifstream cin("memory008.in");
ofstream cout("memory008.out");
int main(int argc, const char * argv[]) {
    // insert code here...
    cin >> n;
    for(i = 1 ; i <= n ; ++i){
        cin >> x;
        ans ^= x;
    }
    cout << ans << '\n';
    return 0;
}
