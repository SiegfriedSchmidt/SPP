// https://codeforces.com/problemset/problem/1883/C
// 05.03.2024
#include <iostream>
#include <random>
#include <map>
#include <unordered_set>
#include <chrono>
#include <set>

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

        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int mn = 11;
        for (int i = 0; i < n; ++i) {
            if (a[i] % k == 0) {
                mn = 0;
            }
            mn = min(mn, k - a[i] % k);
        }

        if (k == 2 || k == 3 || k == 5) {

        } else {
            multiset<int> set1;
            int mn2 = 11;
            for (int i = 0; i < n; ++i) {
                if (a[i] % 2 == 0) {
                    mn2 = 0;
                } else {
                    mn2 = 2 - a[i] % 2;
                }
                set1.insert(mn2);
            }

            mn = min(mn, *set1.begin() + *(++set1.begin()));

        }

        cout << mn << '\n';

    }

}
