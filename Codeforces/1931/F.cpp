//
// 13.02.2024

#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

#define int long long

const int MAXN = 2 * 1e5 + 1;

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        bool flag = true;
        set<int> pos[n + 1];
        int tmp = -1;
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < n; ++j) {
                int x;
                cin >> x;
                if (j == 0) {
                    if (i == 0) {
                        tmp = x;
                    }

                    continue;
                }

                if (i == 0 || (i == 1 && x == tmp)) {
                    pos[x].insert(j - 1);
                    pos[x].insert(j);
                    pos[x].insert(j + 1);
                    continue;
                }

                if (!pos[x].contains(j)) {
                    flag = false;
                } else {
                    pos[x].erase(j - 2);
                    pos[x].erase(j + 2);
                }
            }
        }


        if (flag && k != 1) {
            set<int> set2;
            for (int i = 1; i <= n; ++i) {
                for (auto p: pos[i]) {
                    set2.insert(p);
                }
            }

            for (int i = 0; i < n; ++i) {
                if (!set2.contains(i)) {
                    flag = false;
                    break;
                }
            }

        }


        cout << ((flag || k == 1) ? "YES" : "NO") << '\n';

    }

    return 0;
}

/*
1
4 4
1 2 3 4
2 3 1 4
3 2 1 4
4 2 3 1

 1
 1 1
 1

 */
