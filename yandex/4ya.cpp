//  
// 15.04.2024

#include <bits/stdc++.h>

using namespace std;

#define int long long

pair<int, int> dirs[] = {
        {-1, 0},
        {-1, -1},
        {0, -1},
        {1, -1},
        {1, 0},
        {1, 1},
        {0, 1},
        {-1, 1}
};
signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    int cost[n];
    int ans[n];
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
        ans[i] = 0;
    }

    int min_cost = 0;
    set<pair<int, int>> set1;
    for (int i = 0; i < n; ++i) {
        set1.insert({cost[i], i});
        if (i >= k) {
            set1.erase({cost[i - k], i - k});
        }
        min_cost += set1.begin()->first;
        ++ans[set1.begin()->second];
    }

    cout << min_cost << '\n';
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }

    return 0;
}
