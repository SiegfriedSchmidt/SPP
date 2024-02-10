// https://codeforces.com/contest/1862/problem/A
// 09.02.2024

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        char a[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }

        int it = 0;
        string s = "vika";
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[j][i] == s[it]) {
                    ++it;
                    if (it == s.size()) {
                        goto label;
                    }
                    break;
                }
            }
        }
        label:
        cout << (it == s.size() ? "YES" : "NO") << '\n';
    }
    return 0;
}
