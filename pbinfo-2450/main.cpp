#include <bits/stdc++.h>
using namespace std;
const int MAXX = 1e3;
class Event {
    public:
    int type;
    int time;
    pair<int, int> who;
    Event(int _type, int _time, pair<int, int> _who = pair<int, int> ()):
        type(_type),
        time(_time),
        who(_who) 
        {}
    bool operator<(Event other) const  {
        if(time == other.time) 
            return type > other.type;
        return time < other.time;
    }
};
vector<int64_t> solveFast(vector<int> t, vector<int> p, int T) {
    int n = t.size();
    vector<Event> events;
    for(int i = 0; i < n; ++i) {
        events.push_back(Event(0, t[i] + T));
        events.push_back(Event(1, t[i] - p[i], {p[i], i}));
    }
    sort(events.begin(), events.end());
    set<pair<int, int>> waiting;
    vector<int64_t> sol(n, 0);
    for(const auto& event : events) {
        if(event.type == 0) {
            auto client = *(waiting.begin());
            sol[client.second] = event.time + client.first;
            waiting.erase(waiting.begin());
        } else {
            waiting.insert(event.who);
        }
    }
    return sol;
}
int main() {
    ifstream cin("ramen.in");
    ofstream cout("ramen.out");
    int n, T; cin >> n >> T;
    vector<int> t(n, 0), p(n, 0);    
    set<int> times;
    for(int i = 0; i < n; ++i) {
        cin >> t[i] >> p[i];
        times.insert(t[i]);
    }
    assert(int(times.size()) == n);
    vector<int64_t> sol = solveFast(t, p, T);
    for(int i = 0; i < n; ++i) {
        cout << sol[i] << "\n";
    }
    return 0;
} 