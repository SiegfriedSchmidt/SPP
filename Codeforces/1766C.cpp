// https://codeforces.com/problemset/problem/1766/C
// 25.02.2024

#include <iostream>

using namespace std;

#define int long long

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int m;
        cin >> m;

        int a[2][m];
        int dp[2][m][2];
        int c = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < m; ++j) {
                char tmp;
                cin >> tmp;
                a[i][j] = tmp == 'B';
                c += a[i][j];
                dp[i][j][0] = 0;
                dp[i][j][1] = 0;
            }
        }
        dp[0][0][0] = a[0][0];
        dp[1][0][0] = a[1][0];


        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < 2; ++i) {
                if (a[i][j]) {
                    if (j - 1 >= 0) {
                        dp[i][j][0] = max(dp[i][j - 1][0], dp[i][j - 1][1]) + 1;
                    }
                }
            }
            for (int i = 0; i < 2; ++i) {
                if (a[i][j]) {
                    if (i == 0) {
                        dp[i][j][1] = dp[1][j][0] + 1;
                    } else {
                        dp[i][j][1] = dp[0][j][0] + 1;
                    }
                }
            }
        }

        cout << ((max(max(dp[0][m - 1][0], dp[0][m - 1][1]), max(dp[1][m - 1][0], dp[1][m - 1][1]))) == c ? "YES"
                                                                                                          : "NO")
             << '\n';
    }
}

// 2 4
// 2 4