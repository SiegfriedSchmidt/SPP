//
// 13.02.2024

#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

#define int long long

const int MAXN = 2 * 1e5 + 1;
vector<set<int>> g(MAXN);
bool used[MAXN];

bool dfs(int v) {
    used[v] = true;
    bool flag = false;

    for (auto u: g[v]) {
        if (!used[u]) {
            flag |= dfs(u);
        }
    }
    return flag;
}

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        for (int i = 0; i < n; ++i) {
            g[i].clear();
        }
        fill(used, used + n, false);

        for (int i = 0; i < k; ++i) {
            int p = -1;
            for (int j = 0; j < n; ++j) {
                int x;
                cin >> x;
                --x;
                if (j != 0) {
                    if (p != -1) {
                        g[p].insert(x);
                    }

                    p = x;
                }
            }
        }

        int cycle = false;
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                cycle |= dfs(i);
            }
        }

        if (cycle) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }


    }

    return 0;
}

