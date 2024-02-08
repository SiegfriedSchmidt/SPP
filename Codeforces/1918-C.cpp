// https://codeforces.com/problemset/problem/1918/C
// 05.02.2024

#include <iostream>

using namespace std;

#define int long long

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int a, b, r;
        cin >> a >> b >> r;

        bool flag = true;
        int r2 = 0;
        for (int i = 60; i >= 0; --i) {
            int mask = (1ll << i);
            if ((a & mask) != (b & mask)) {
                if (flag) {
                    flag = false;
                    continue;
                }
                if (abs((a ^ r2) - (b ^ r2)) > abs((a ^ (r2 + mask)) - (b ^ (r2 + mask)))) {
                    if (r2 + mask <= r) {
                        r2 += mask;
                    }
                }
            }
        }

        cout << abs((a ^ r2) - (b ^ r2)) << '\n';
    }


    return 0;
}
