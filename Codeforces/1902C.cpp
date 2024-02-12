// https://codeforces.com/problemset/problem/1902/C
// 11.02.2024

#include <iostream>
#include <numeric>
#include <set>

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
        set<int> set1;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            set1.insert(a[i]);
        }

        int mx = *set1.rbegin();
        int gcd_all = 0;
        for (int i = 0; i < n; ++i) {
            gcd_all = gcd(gcd_all, mx - a[i]);
        }

        if (gcd_all == 0) {
            cout << "1\n";
            continue;
        }

        int p = 0;
        for (auto i = set1.rbegin(); i != set1.rend(); ++i) {
           if (!set1.contains((*i) - gcd_all)) {
               p = (*i) - gcd_all;
               break;
           }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (mx - a[i]) / gcd_all;
        }
        ans += (mx - p) / gcd_all;

        mx += gcd_all;
        int ans2 = 0;
        for (int i = 0; i < n; ++i) {
            ans2 += (mx - a[i]) / gcd_all;
        }

        cout << min(ans, ans2) << '\n';
    }
    return 0;
}

/*
1
16
9 -10 -7 4 -8 10 -5 -1 -9 8 3 -2 2 5 0 -6


 */
