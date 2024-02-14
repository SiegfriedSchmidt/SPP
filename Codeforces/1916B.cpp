// https://codeforces.com/problemset/problem/1916/B
// 14.02.2024

#include <iostream>
#include <numeric>

using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        int ans = 0;
        if (b % a == 0) {
            ans = b * (b / a);
        } else {
            ans = lcm(a, b);
        }

        cout << ans << '\n';
    }
}


