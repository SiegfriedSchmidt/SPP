//
// 13.02.2024

#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define int long long

const int MAXN = 2 * 1e5 + 1;
int cnt[MAXN];

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

        int l = 0;
        while (l < n && a[l] == a[0]) {
            ++l;
        }

        int r = 0;
        while (n - r - 1 >= 0 && a[n - r - 1] == a[n - 1]) {
            ++r;
        }

        if (a[0] == a[n - 1]) {
            cout << max(n - l - r, 0ll) << '\n';
        } else {
            cout << max(n - max(l, r), 0ll) << '\n';
        }

    }

    return 0;
}

