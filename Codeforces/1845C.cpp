// https://codeforces.com/problemset/problem/1845/C
// 23.02.2024

#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define int long long

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int m;
        string s;
        cin >> s >> m;
        int l[m];
        int r[m];

        for (int i = 0; i < m; ++i) {
            char c;
            cin >> c;
            l[i] = c - '0';
        }

        for (int i = 0; i < m; ++i) {
            char c;
            cin >> c;
            r[i] = c - '0';
        }

        int n = s.size();

        int idx = 0;
        bool flag = false;
        for (int j = 0; j < m; ++j) {
            int first_v = -1;
            for (int v = l[j]; v <= r[j]; ++v) {
                int idx2 = -1;
                for (int i = idx; i < n; ++i) {
                    if ((s[i] - '0') == v) {
                        idx2 = i;
                        break;
                    }
                }
                if (idx2 == -1) {
                    flag = true;
                    break;
                } else {
                    first_v = max(first_v, idx2);
                }
            }
            if (flag && first_v == -1) {
                flag = true;
                break;
            } else {
                idx = first_v + 1;
            }

        }

        cout << (flag ? "YES" : "NO") << '\n';
    }

    return 0;
}
