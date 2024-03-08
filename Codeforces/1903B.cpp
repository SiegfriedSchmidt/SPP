// https://codeforces.com/problemset/problem/1903/B
// 08.03.2024

#include <iostream>
#include <vector>

#define int long long

using namespace std;

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> M(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> M[i][j];
            }
        }

        vector<int> a(n, (1ll << 30) - 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    a[i] &= M[i][j];
                    a[j] &= M[i][j];
                }
            }
        }

        bool flag = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    if ((a[i] | a[j]) != M[i][j]) {
                        flag = false;
                    }
                }
            }
        }
        cout << (flag ? "YES" : "NO") << '\n';
        if (flag) {
            for (auto a1 : a) {
                cout << a1 << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
