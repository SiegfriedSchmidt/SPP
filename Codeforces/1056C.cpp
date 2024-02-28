// https://codeforces.com/problemset/problem/1056/C
// 28.02.2024

#include <bitset>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long


signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> p(n * 2);
    set<pair<int, int>, greater<>> set1;
    for (int i = 0; i < n * 2; ++i) {
        cin >> p[i];
        set1.insert({p[i], i});
    }

    vector<pair<int, int>> pairs(m);
    map<int, int> map1;
    for (int i = 0; i < m; ++i) {
        cin >> pairs[i].first >> pairs[i].second;
        --pairs[i].first;
        --pairs[i].second;
        map1[pairs[i].first] = pairs[i].second;
        map1[pairs[i].second] = pairs[i].first;
    }

    int t;
    cin >> t;

    while (!set1.empty()) {
        if (t == 1) {
            if (map1.empty()) {
                auto el = *set1.begin();
                set1.erase(set1.begin());
                cout << el.second + 1 << endl;

                if (set1.empty()) {
                    break;
                }

                int move;
                cin >> move;
                --move;
                set1.erase({p[move], move});
            } else {
                auto p1 = *map1.begin();
                int a = p1.first;
                int b = p1.second;
                map1.erase(a);
                map1.erase(b);
                set1.erase({p[a], a});
                set1.erase({p[b], b});
                if (p[a] < p[b]) {
                    swap(a, b);
                }
                cout << a + 1 << endl;
                int tmp;
                cin >> tmp;
            }
        } else {
            int move;
            cin >> move;
            --move;

            if (map1.contains(move)) {
                int a = move;
                int b = map1[move];
                set1.erase({p[a], a});
                set1.erase({p[b], b});
                map1.erase(b);
                map1.erase(a);
                cout << b + 1 << endl;
            } else {
                set1.erase({p[move], move});
                t = 1;
            }
        }
    }


    return 0;
}
