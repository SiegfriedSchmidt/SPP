// https://codeforces.com/contest/1927/problem/D
// 08.02.2024

#include <iostream>
#include <vector>

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
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<pair<int, int>> l_r;
        for (int i = 0; i < n; ++i) {
            int l = i;
            while (i + 1 < n && a[i] == a[i + 1]) {
                ++i;
            }
            l_r.emplace_back(l, i);
        }

        sort(l_r.begin(), l_r.end());

        int q;
        cin >> q;
        for (int i = 0; i < q; ++i) {
            int ql, qr;
            cin >> ql >> qr;
            --ql;
            --qr;
//            cout << ql << ' ' << qr << '\n';

            int l = 0, r = l_r.size();
            while (l + 1 < r) {
                int mid = (l + r) / 2;
                if (l_r[mid].first <= ql) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
//            cout << l_r[l].first << ' ' << l_r[l].second << '\n';
            if (l_r[l].second < qr) {
                cout << ql + 1 << ' ' << l_r[l + 1].first + 1 << '\n';
            } else {
                cout << "-1 -1\n";
            }
//            cout << '\n';
        }

        cout << '\n';
    }

    return 0;
}