//
// 13.02.2024

#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

#define int long long

const int MAXN = 2 * 1e5 + 1;

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;

        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int ans = 0;
        int INF = y * 100'000'000;
        map<pair<int, int>, int> mapx;
        for (int i = n - 1; i >= 0; --i) {
            ans += mapx[make_pair(a[i] % x, a[i] % y)];
            mapx[make_pair((x - a[i] % x) % x, (y - (-a[i] + INF) % y) % y)]++;
        }

        cout << ans << '\n';


    }

    return 0;
}

