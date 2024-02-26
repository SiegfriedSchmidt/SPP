// https://codeforces.com/problemset/problem/1769/C2
// 26.02.2024

#include <iostream>

using namespace std;

#define int long long

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int a[n];
        int dp[n][2];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            for (int j = 0; j < 2; ++j) {
                dp[i][j] = 1;
            }
        }

        int mx = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    int d = (a[i] + j) - (a[i - 1] + k);
                    if (d >= 0 && d <= 1) {
                        dp[i][j] = max(dp[i][j], dp[i - 1][k] + d);
                    }
                    mx = max(mx, dp[i][j]);
                }
            }
        }

        cout << mx << '\n';
    }

    return 0;
}
