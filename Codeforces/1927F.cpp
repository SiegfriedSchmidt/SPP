// https://codeforces.com/contest/1927/problem/F
// 08.02.2024

#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define int long long
const int MAXN = 200001;

vector<vector<int>> g(MAXN);
vector<int> cycle;
set<pair<int, int>> bridges;
bool find_cycle = false;
bool used[MAXN];
bool cycle_used[MAXN];
int tin[MAXN];
int fup[MAXN];
int timer;

void dfs(int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    for (auto to: g[v]) {
        if (to == p) {
            continue;
        }
        if (used[to]) {
            fup[v] = min(fup[v], tin[to]);
        } else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] > tin[v]) {
                bridges.insert({min(to, v), max(to, v)});
            }
        }
    }
}

void cycle_dfs(int v, pair<int, int> target_edge, int p = -1) {
    cycle_used[v] = true;
    for (auto to: g[v]) {
        if (to == p) {
            continue;
        }
        if (!cycle_used[to]) {
            cycle.emplace_back(v);
            if (to == target_edge.first) {
                cycle.emplace_back(to);
                find_cycle = true;
                break;
            }
            cycle_dfs(to, target_edge, v);
            if (find_cycle) {
                break;
            }

            cycle.pop_back();
        }
    }
}

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; ++i) {
            g[i].clear();
            used[i] = false;
            cycle_used[i] = false;
            tin[i] = 0;
            fup[i] = 0;
        }
        cycle.clear();
        bridges.clear();
        find_cycle = false;
        timer = 0;

        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            --u;
            --v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
            edges.emplace_back(w, make_pair(min(u, v), max(u, v)));
        }

        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                dfs(i);
            }
        }

        pair<int, pair<int, int>> min_edge;
        sort(edges.begin(), edges.end());
        for (auto edge: edges) {
            if (!bridges.contains(edge.second)) {
                min_edge = edge;
                break;
            }
        }

        cycle_dfs(min_edge.second.second, min_edge.second, min_edge.second.first);
        cout << min_edge.first << ' ' << cycle.size() << '\n';
        for (auto v: cycle) {
            cout << v + 1 << ' ';
        }
        cout << "\n";
    }

    return 0;
}
