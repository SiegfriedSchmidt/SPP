// https://cups.online/ru/tasks/1873
// 04.02.2024

#include <iostream>
#include <vector>

using namespace std;

#define int long long

const int MAXN = 1e5 + 1;
const int MOD = 1e9 + 7;

vector<vector<int>> g(MAXN);
int p2[1000];
int ans = 0;

int dfs(int v, int p = -1) {
    int s = 1;
    for (auto u: g[v]) {
        if (u != p) {
            int tmp = dfs(u, v);
            s += tmp;
            ans = (ans + MOD - p2[tmp] * (v + 1)) % MOD;
        }
    }
//    cout << v + 1 << ' ' << s << '\n';
    ans = (ans + (p2[s] - 1) * (v + 1)) % MOD;
    return s;
}

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    p2[0] = 1;
    for (int i = 1; i < 1000; ++i) {
        p2[i] = p2[i - 1] * 2 % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
//        cout << '\n';
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            g[i].clear();
        }

        int root = -1;
        for (int i = 0; i < n; ++i) {
            int p;
            cin >> p;
            --p;
            if (p == i) {
                root = i;
            } else {
                g[p].emplace_back(i);
            }
        }
        ans = 0;
        dfs(root);
        cout << ans << '\n';
    }

    return 0;
}
