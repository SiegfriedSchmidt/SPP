// https://codeforces.com/problemset/problem/1733/D1
// 21.02.2024

#include <iostream>

using namespace std;

#define int long long

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;

        string a, b;
        cin >> a >> b;

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                cnt++;
            }
        }

        int seq = 0;
        for (int i = 0; i < n; ++i) {
            int l = i;
            while (i < n && a[i] != b[i]) {
                ++i;
            }
            if (i - l > 1) {
                seq = i - l;
            }
        }

        if (cnt % 2 == 0) {
            if (seq == 2 && cnt == 2) {
                cout << min(x, 2 * y) + (cnt - seq) / 2 * y;
            } else {
                cout << cnt / 2 * y;
            }
        } else {
            cout << "-1";
        }
        cout << '\n';
    }
    return 0;
}

/*
1
6 4 3
001100
100001

 */
