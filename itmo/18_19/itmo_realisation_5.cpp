// 
// 08.03.2024

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
    int n;
    cin >> n;

    vector<set<int>> obj(n);
    map<int, vector<int>> prop_to_obj;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int prop;
            cin >> prop;
            obj[i].insert(prop);
            prop_to_obj[prop].emplace_back(i);
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        char t;
        int idx;
        cin >> t >> idx;
        if (t == '-') {
            for (auto obj_idx : prop_to_obj[idx]) {
                obj[obj_idx].erase(idx);
            }
            prop_to_obj[idx].clear();
        } else {
            --idx;
            cout << obj[idx].size() << '\n';
        }
    }

    return 0;
}

/*
2
3 1 2 4
3 2 3 5
12
- 1
? 1
? 2
- 2
? 1
? 2
- 5
? 1
? 2
- 6
? 1
? 2

 */