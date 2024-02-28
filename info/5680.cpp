// compege 5680
// 27.02.2024

#include <iostream>

using namespace std;

#define int long long

const int MAXN = 20'000'001;
int a[MAXN];
pair<int, int> pref[MAXN];

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    freopen("/Users/matvei/Developer/Projects/SPP/info/tests/27B_5680.txt", "r", stdin);

    int n, m, l;
    cin >> n >> m >> l;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = n; i < n * 2; ++i) {
        a[i] = a[i - n];
    }

    pref[0].first = a[0];
    pref[0].second = a[0];
    // префикс first сумма значений умноженных на позицию относительно начала
    // префикс second сумма значений
    for (int i = 1; i < n * 2; ++i) {
        pref[i].first = pref[i - 1].first + a[i] * (i + 1);
        pref[i].second = pref[i - 1].second + a[i];
    }

    int ans = 1e18;
    for (int i = 0; i < n; ++i) {
        int cost1 = pref[i + l].first - pref[i + m - 1].first;
        int cost2 = pref[i + l].second - pref[i + m - 1].second;
        int cost = cost1 - cost2 * (i + 1);
        ans = min(ans, cost);
    }

    cout << ans;

    return 0;
}