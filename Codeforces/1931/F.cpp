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
int color[MAXN];

bool dfs(int v) {
    color[v] = 1;

    for (auto u: g[v]) {
        if (color[u] == 0) {
           if (dfs(u)) {
               return true;
           }
        } else if (color[u] == 1) {
            return true;
        }
    }

    color[v] = 2;

    return false;
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
        fill(color, color + n, 0);

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
            if (color[i] == 0) {
                if (dfs(i)) {
                    cycle = true;
                    break;
                }
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

