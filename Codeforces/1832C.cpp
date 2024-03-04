// https://codeforces.com/problemset/problem/1832/C
// 04.03.2024

#include <iostream>
#include <vector>

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

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        n = unique(a.begin(), a.end()) - a.begin();
        int cnt = n;
        for (int i = 0; i + 2 < n; ++i) {
            cnt -= (a[i] < a[i + 1] && a[i + 1] < a[i + 2]);
            cnt -= (a[i] > a[i + 1] && a[i + 1] > a[i + 2]);
        }
        cout << cnt << '\n';
    }
}
