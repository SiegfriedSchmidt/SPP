//
// 15.02.2024

#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <cmath>

using namespace std;

#define int long long

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int ans = 0;
        if (k == 4 * n - 2) {
            ans = k / 2 + 1;
        } else {
            ans = ceil(double(k) / 2);
        }
        cout << ans << '\n';
    }

    return 0;
}
