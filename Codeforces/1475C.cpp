// https://codeforces.com/problemset/problem/1475/C
// 19.02.2024

#include <iostream>
#include <vector>

using namespace std;

#define int long long

const int MAXN = 2 * 1e5 + 1;

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--) {
        int a, b, k;
        cin >> a >> b >> k;

        vector<pair<int, int>> edge;
        int v[k];
        int start[a];
        int end[b];

        fill(start, start + a, 0);
        fill(end, end + b, 0);

        for (int i = 0; i < k; ++i) {
            int x;
            cin >> x;
            --x;
            v[i] = x;
            ++start[x];
        }

        for (int i = 0; i < k; ++i) {
            int x;
            cin >> x;
            --x;
            edge.emplace_back(v[i], x);
            ++end[x];
        }

        int ans = 0;
        for (int i = 0; i < k; ++i) {
            int from = edge[i].first, to = edge[i].second;
            ans += k - start[from] - end[to] + 1;
        }
        cout << ans / 2 << '\n';
    }

    return 0;
}

