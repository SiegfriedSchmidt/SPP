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

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        g[p].emplace_back(i);
    }

    return 0;
}
