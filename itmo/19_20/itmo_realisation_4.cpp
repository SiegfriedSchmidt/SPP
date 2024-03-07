// 
// 07.03.2024

#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define int long long

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, dt;
    cin >> n >> dt;

    map<string, pair<int, int>> people;
    set<string> ans;
    for (int i = 0; i < n; ++i) {
        string str_time, name, type;
        cin >> str_time >> name >> type;
        int time = stoll(str_time.substr(0, 2)) * 60 + stoll(str_time.substr(3, 2));
        int cycle = people[name].first;
        if (type == "in") {
            if (cycle == 2) {
                if (time - people[name].second < dt) {
                    ans.insert(name);
                }
            }
            people[name] = {1, time};
        } else {
            if (cycle == 1) {
                people[name].first = 2;
            }
        }
    }

    cout << ans.size() << '\n';
    for (const auto &a1: ans) {
        cout << a1 << '\n';
    }

    return 0;
}

/*
6 10
01:23 Petrov in
01:24 Ivanov out
01:25 Petrov out
01:27 Ivanov in
01:32 Petrov in
01:33 Ivanov out

 */