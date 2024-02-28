// https://codeforces.com/problemset/problem/1733/C
// 27.02.2024

#include <iostream>
#include <vector>
using namespace std;
#define int long long

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t = 0;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int a[n + 1];
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        if (n == 1) {
            cout << "0\n";
            continue;
        }

        vector<pair<int, int>> ans;

        ans.emplace_back(1, n);
        for (int i = 1; i < n; ++i) {
            if ((a[i] + a[1]) % 2 == 1) {
                ans.emplace_back(1, i);
            } else {
                ans.emplace_back(i, n);
            }
        }

        cout << ans.size() << '\n';
        for (auto [x, y] : ans) {
            cout << x << ' ' << y << '\n';
        }

    }

    return 0;
}