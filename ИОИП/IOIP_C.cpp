//  
// 17.02.2024

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <numeric>

using namespace std;

#define int long long

const int MAXN = 2 * 1e5 + 1;
vector<vector<pair<int, int>>> g(MAXN);
int p[MAXN];
int sz[MAXN];

int get(int x) {
    if (p[x] == x) {
        return x;
    }
    return p[x] = get(p[x]);
}

void unionn(int x, int y) {
    int a = get(x);
    int b = get(y);
    if (a == b) {
        return;
    }
    if (sz[b] > sz[a]) {
        swap(a, b);
    }

    p[b] = a;
    sz[a] += sz[b];
}

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    pair<int, pair<int, int>> edges[m];
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
        edges[i] = {w, {u, v}};
    }

    if (m == n - 1 || m == n) {
        for (int v = 0; v < n; ++v) {
            int maxc = 0;
            int mini = 1e10;
            for (auto [u, cost]: g[v]) {
                if (cost > maxc) {
                    maxc = cost;
                    mini = u;
                } else if (cost == maxc) {
                    mini = min(mini, u);
                }
            }
            cout << mini + 1 << ' ';
        }
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        g[i].clear();
    }

    sort(edges, edges + m);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            p[j] = j;
            sz[j] = 1;
        }

        unionn(edges[i].second.first, edges[i].second.second);
        int cost = 0;
        for (int j = 0; j < m; ++j) {
            if (get(edges[j].second.first) != get(edges[j].second.second)) {
                cost += edges[j].first;
                unionn(edges[j].second.first, edges[j].second.second);
            }
        }
        g[edges[i].second.first].emplace_back(edges[i].second.second, cost);
        g[edges[i].second.second].emplace_back(edges[i].second.first, cost);
    }

    for (int v = 0; v < n; ++v) {
        int minc = g[v][0].second;
        int mini = g[v][0].first;
        for (auto [u, cost]: g[v]) {
            if (cost < minc) {
                minc = cost;
                mini = u;
            } else if (cost == minc) {
                mini = min(mini, u);
            }
        }
        cout << mini + 1 << ' ';
    }


    return 0;
}

/*
3 3
1 2 1
2 3 2
1 3 3

 */