// https://codeforces.com/contest/1927/problem/C
// 08.02.2024

#include <iostream>
#include <set>

using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        bool flag = true;
        set<int> set1;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            if (a <= k) {
                set1.insert(a);
            }
        }
        if (set1.size() < k / 2) {
            flag = false;
        }

        set<int> set2;
        for (int i = 0; i < m; ++i) {
            int a;
            cin >> a;
            if (a <= k) {
                set2.insert(a);
                set1.insert(a);
            }
        }

        if (set2.size() < k / 2) {
            flag = false;
        }

        if (set1.size() != k) {
            flag = false;
        }

        cout << (flag ? "YES" : "NO") << '\n';
    }
    return 0;
}