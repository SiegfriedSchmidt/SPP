//
// 15.02.2024

#include <iostream>
#include <vector>
#include <map>
#include <numeric>

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

        sort(a, a + n);

        int ans = 0;
        for (int i = 1; i < n; ++i) {
            ans += a[i] - a[i - 1];
        }

        cout << ans << '\n';

    }

    return 0;
}
