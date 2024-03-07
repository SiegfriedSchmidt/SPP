// https://codeforces.com/problemset/problem/1928/B
// 07.03.2024

#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
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


        set<int> set1;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            set1.insert(tmp);
        }

        vector<int> a;
        a.reserve(set1.size());
        for (auto s: set1) {
            a.emplace_back(s);
        }

        int old_n = n;
        n = a.size();
        int ans = 0;
        int r = 0;
        for (int l = 0; l < n; ++l) {
            while (r < n && a[r] - a[l] <= old_n - 1) {
                ++r;
            }
            ans = max(ans, r - l);
        }
        cout << ans << '\n';
    }

    return 0;
}
