#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
using namespace std;
bool is_unique(vector<int> V) {
    sort(V.begin(), V.end());
    for (int i = 1; i < int(V.size()); ++i)
        if (V[i] == V[i - 1])
            return false;
    return true;
}
int main() {
    ifstream cin("turnuri.in");
    ofstream cout("turnuri.out");
    int N; assert(cin >> N);
    assert(1 <= N && N <= 100 * 1000);
    vector<int> V(N);
    for (int i = 0; i < N; ++i) {
        assert(cin >> V[i]);
        assert(1 <= V[i] && V[i] <= 1000 * 1000 * 1000);
    }
    assert(is_unique(V));
    vector<int> left1(N, -1), left2(N, -1), right1(N, N), right2(N, N);
    vector<int> stack1;
    vector<int> stack2;
    for (int i = 0; i < N; ++i) {
        int from_erase = stack1.size();
        while (from_erase > 0 && V[stack1[from_erase - 1]] < V[i]) {
            --from_erase;
        }
        // We have to erase from stack1 positions from_erase, from_erase + 1, ...
        // first lets set right2
        while (!stack2.empty() && V[stack2.back()] < V[i]) {
            right2[stack2.back()] = i;
            stack2.pop_back();
        }
        // and left2, this could be one of two things
        // either its the top element of stack2 
        //   - a position P that doesnt have right2 set
        // or stack1[from_erase - 2]
        //  - since its also bigger
        // take whichever is closest
        if (!stack2.empty()) {
            left2[i] = stack2.back();
        }
        if (from_erase > 1 && stack1[from_erase - 2] > left2[i]) {
            left2[i] = stack1[from_erase - 2];
        }
        // now we can add the elements from stack1 positions from_erase, from_erase + 1, ...
        // because they are waiting for their right2 to be set
        // all elements in stack2 are bigger than V[i] so bigger than these elemente
        // its still a nondecreasing sequence
        for (int j = from_erase; j < int(stack1.size()); ++j) {
            right1[stack1[j]] = i;
            stack2.push_back(stack1[j]);
        }
        stack1.resize(from_erase);
        if (!stack1.empty()) {
            left1[i] = stack1.back();
        }
        stack1.push_back(i);
    }
    int64_t total = 0;
    for (int i = 0; i < N; ++i)
        total += right1[i] - left1[i] - 1;
    vector<int64_t> answer(N, total);
    for (int i = 0; i < N; ++i) {
        answer[i] -= right1[i] - left1[i] - 2;
        if (right1[i] != N)
            answer[right1[i]] += right2[i] - right1[i];
        if (left1[i] != -1)
            answer[left1[i]] += left1[i] - left2[i];
    }
    for (int i = 0; i < N; ++i)
        cout << answer[i] << "\n";
} 