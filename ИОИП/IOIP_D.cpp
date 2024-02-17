//  
// 17.02.2024

#include <iostream>
#include <vector>
#include <map>
#include <numeric>

using namespace std;

#define int long long
const int MOD = 1e9 + 7;

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, k, m;
    cin >> n >> k >> m;

    int c = (n + 1) / 2;

    int ans = 1;

    int dp[c - 1];
    dp[0] = k - 1;
    for (int i = 1; i < c - 1; ++i) {
        if (i > (c - (c - 1) / 2)) {
            dp[i] = dp[i - 1] * (k - 1) % MOD;
        } else {
            dp[i] = dp[i - (c - i) * 2] * (k - 1) % MOD;
        }
    }

    cout << (dp[c] * 2) % MOD;

    return 0;
}
