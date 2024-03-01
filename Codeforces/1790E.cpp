// https://codeforces.com/problemset/problem/1790/E
// 01.03.2024

#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

#define int long long

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int x;
        cin >> x;
        int a = x;
        int b = 0;
        for (int i = 32; i >= 0; --i) {
            if (x & (1ll << 32)) {
                continue;
            }

            if (a + (1ll << i) + b + (1ll << i) <= x * 2) {
                a += (1ll << i);
                b += (1ll << i);
            }
        }

        if (a + b == 2 * x && ((a ^ b) == x)) {
            cout << a << ' ' << b << '\n';
        } else {
            cout << "-1\n";
        }
    }


    return 0;
}
