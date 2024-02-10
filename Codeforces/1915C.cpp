// https://codeforces.com/contest/1915/problem/C
// 04.02.2024

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

        int s = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            s += a;
        }

        int l = 0, r = 1e9;
        while (l + 1 < r) {
            int mid = (l + r) / 2;

            if (s < mid * mid) {
                r = mid;
            } else {
                l = mid;
            }
        }

        cout << (l * l == s ? "YES" : "NO") << '\n';
    }

    return 0;
}