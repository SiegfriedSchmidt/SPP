// https://codeforces.com/contest/1927/problem/F
// 08.02.2024

#include <iostream>
#include <vector>

using namespace std;

#define int long long


signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> g(n);

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            --u;
            --v;
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }

    }

    return 0;
}
