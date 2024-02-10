// https://codeforces.com/gym/104174/problem/D
// 07.02.2024

#include <iostream>
#include <vector>

using namespace std;

#define int long long

const int MAXN = 200001;
const int MOD = 1e9 + 7;

vector<vector<int>> g(MAXN);
int dp[MAXN][2];
int n, k;

void dfs(int v) {
    if (g[v].size() == 0) {
        dp[v][0] = 1;
        dp[v][1] = 0;
        return;
    }

    dp[v][0] = 1;
    dp[v][1] = 1;

    for (auto u: g[v]) {
        dfs(u);
        dp[v][0] = dp[v][0] * (dp[u][0] + dp[u][1]) % MOD;
    }

    if (k == 3) {
        for (int i = 0; i < g[v].size(); ++i) {
            for (int j = i + 1; j < g[v].size(); ++j) {
                int u1 = g[v][i];
                int u2 = g[v][j];
                cout << u1 << ' ' << u2 << '\n';

                int cur_dp = 1;
                for (auto u: g[v]) {
                    if (u == u1 || u == u2) {
                        cur_dp = cur_dp * dp[u][0] % MOD;
                    } else {
                        cur_dp = cur_dp * (dp[u][0] + dp[u][1]) % MOD;
                    }
                }
                dp[v][1] = dp[v][1] * cur_dp % MOD;
            }
        }
    }
}

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;

    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        g[p].emplace_back(i);
    }

    dfs(0);
    cout << dp[0][0] + dp[0][1];

    return 0;
}
