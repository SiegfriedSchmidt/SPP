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
int pref[MAXN][6];
int n, k;

void dfs(int v) {
    dp[v][0] = 1;
    dp[v][1] = 0;

    if (g[v].empty()) {
        return;
    }

    for (auto u: g[v]) {
        dfs(u);
        dp[v][0] = (dp[v][0] * ((dp[u][0] + dp[u][1]) % MOD)) % MOD;
    }

    for (int j = 0; j < k; ++j) {
        pref[0][j] = 0;
    }

    pref[0][0] = (dp[g[v][0]][0] + dp[g[v][0]][1]) % MOD;
    pref[0][1] = dp[g[v][0]][0];
    for (int i = 1; i < g[v].size(); ++i) {
        for (int j = 0; j < k; ++j) {
            pref[i][j] = (pref[i - 1][j] * ((dp[g[v][i]][0] + dp[g[v][i]][1]) % MOD)) % MOD;
            if (j - 1 >= 0) {
                pref[i][j] = (pref[i][j] + (pref[i - 1][j - 1] * dp[g[v][i]][0]) % MOD) % MOD;
            }
        }
    }

    for (int i = 2; i < k; ++i) {
        dp[v][1] = (dp[v][1] + pref[g[v].size() - 1][i]) % MOD;
    }

//    for (int i = 0; i < g[v].size(); ++i) {
//        for (int j = i + 1; j < g[v].size(); ++j) {
//            int u1 = g[v][i];
//            int u2 = g[v][j];
//
//            int cur_dp = 1;
//            for (auto u: g[v]) {
//                if (u == u1 || u == u2) {
//                    cur_dp = cur_dp * dp[u][0] % MOD;
//                } else {
//                    cur_dp = (cur_dp * ((dp[u][0] + dp[u][1]) % MOD)) % MOD;
//                }
//            }
//            dp[v][1] = (dp[v][1] + cur_dp) % MOD;
//        }
//    }
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
