// https://codeforces.com/problemset/problem/1612/C
// 18.02.2024

#include <iostream>

using namespace std;

#define int long long

int square(int x, int k) {
    int sq = (1 + min(k, x)) * min(k, x) / 2;
    if (x > k) {
        sq += (k - 1 + k - (x - k)) * (x - k) / 2;
    }
    return sq;
}

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--) {
        int k, x;
        cin >> k >> x;

        int l = 0, r = k * 2;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (square(mid, k) > x) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << min(k * 2 - 1, (x == square(l, k) ? l : r)) << '\n';
    }

    return 0;
}
