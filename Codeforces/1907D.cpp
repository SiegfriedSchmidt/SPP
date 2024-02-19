// https://codeforces.com/problemset/problem/1907/D
// 17.02.2024

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
        pair<int, int> line[n];
        for (int i = 0; i < n; ++i) {
            cin >> line[i].first >> line[i].second;
        }

        int l = -1, r = 1e9;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            int k = mid;
            int l1 = -k, r1 = k;
            bool flag = true;
            for (int i = 0; i < n; ++i) {
                l1 = max(l1, line[i].first);
                r1 = min(r1, line[i].second);
                if (r1 - l1 < 0) {
                    flag = false;
                }
                l1 -= k;
                r1 += k;
            }
            if (flag) {
                r = mid;
            } else {
                l = mid;
            }
        }

        cout << r << '\n';

    }

    return 0;
}
