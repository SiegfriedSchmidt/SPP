//
// 05.03.2024

#include <iostream>
#include <vector>

using namespace std;

#define int long long

const int INF = 1e9;

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;

    int a[n];
    vector<bool> used(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    while (m--) {
        int cnt;
        cin >> cnt;

        int l = INF;
        int l2 = INF;
        for (int i = 0; i < k; ++i) {
            if (!used[i] && a[i] == cnt) {
                l2 = i;
            } else if (!used[i] && a[i] > cnt) {
                l = i;
            }
        }

        int r = INF;
        int r2 = INF;
        for (int i = n - 1; i >= k; --i) {
            if (!used[i] && a[i] == cnt) {
                r2 = i;
            } else if (!used[i] && a[i] > cnt) {
                r = i;
            }
        }

        if (l2 != INF || r2 != INF) {
            if (abs(k - l2) <= abs(k - r2)) {
                used[l2] = true;
                cout << l2 + 1 << ' ';
            } else {
                used[r2] = true;
                cout << r2 + 1 << ' ';
            }
            continue;
        }

        if (l == INF && r == INF) {
            cout << -1 << ' ';
        } else {
            if (abs(k - l) <= abs(k - r)) {
                used[l] = true;
                cout << l + 1 << ' ';
            } else {
                used[r] = true;
                cout << r + 1 << ' ';
            }
        }
    }


    return 0;
}
