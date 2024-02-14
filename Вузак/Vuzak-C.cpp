//  
// 14.02.2024

#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

#define int long long
#define mp make_pair

const int MAXN = 2 * 1e5 + 1;
const int INF = 1e9 + 7;

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> l_r;
    for (int i = 0; i < q; ++i) {
        int x, d;
        cin >> x >> d;
        l_r.emplace_back(max(1ll, x - d), -1);
        l_r.emplace_back(min(n, x + d), 1);
    }

    sort(l_r.begin(), l_r.end());
    int ans = 0;
    int inter = 0;
    int p = 0;
    for (auto [x, t]: l_r) {
        if (t == -1) {
            if (inter == 0) {
                ans += x - p - 1;
            }
            inter += 1;
        } else {
            inter -= 1;
            p = x;
        }
    }

    cout << ans + n - p;

    return 0;
}

