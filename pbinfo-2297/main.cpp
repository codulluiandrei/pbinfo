#include <fstream>
#include <vector>
using namespace std;
ifstream cin("gogosi.in");
ofstream cout("gogosi.out");
vector<int> v;
int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i ++){
        int a; cin >> a;
        int l = 0, r = v.size() - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(v[mid] <= a)  r = mid - 1;
            else            l = mid + 1;
        }
        if(l == v.size())   v.push_back(a);
        else                v[l] = a;
    }
    cout << v.size();
    return 0;
}