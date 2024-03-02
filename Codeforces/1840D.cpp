// https://codeforces.com/problemset/problem/1840/D
// 02.03.2024

#include <iostream>

using namespace std;

#define int long long
constexpr int MAXN = 200001;
int a[MAXN];
int n;

bool func(int t) {
    int l = n - 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] - a[0] > t * 2) {
            l = i;
            break;
        }
    }

    int r = 0;
    for (int i = n - 2; i >= 0; --i) {
        if (a[n - 1] - a[i] > t * 2) {
            r = i;
            break;
        }
    }

    return a[r] - a[l] <= t * 2;
}


signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--) {
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n);

        int l = -1, r = 1e9;
        while (l + 1 < r) {
            int mid = (l + r) / 2;

            if (func(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }

        cout << r << '\n';

    }

    return 0;
}
