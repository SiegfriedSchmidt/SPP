// https://codeforces.com/contest/1915/problem/F
// 04.02.2024

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <array>

using namespace std;

const int MAXN = 2 * 1e5 + 1;
array<int, MAXN * 4> tree;

void update(int v, int tl, int tr, int l, int r, int val) {
    if (tl >= r || tr <= l) {
        return;
    }

    if (tl >= l && tr <= r) {
        tree[v] = val;
        return;
    }

    int mid = (tl + tr) / 2;
    update(v * 2 + 1, tl, mid, l, r, val);
    update(v * 2 + 2, mid, tr, l, r, val);
    tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
}

int ans(int v, int tl, int tr, int l, int r) {
    if (tl >= r || tr <= l) {
        return 0;
    }

    if (tl >= l && tr <= r) {
        return tree[v];
    }

    int mid = (tl + tr) / 2;
    return ans(v * 2 + 1, tl, mid, l, r) + ans(v * 2 + 2, mid, tr, l, r);
}

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> people;
        vector<int> coords;
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            coords.emplace_back(a);
            coords.emplace_back(b);
            people.emplace_back(a, b);
        }
        int tn = coords.size();

        sort(coords.begin(), coords.end());
        map<int, int> comp;
        for (int i = 0; i < tn; ++i) {
            comp[coords[i]] = i;
        }

        for (auto &pos: people) {
            pos.first = comp[pos.first];
            pos.second = comp[pos.second];
        }

        sort(people.begin(), people.end(), [](pair<int, int> &lhs, pair<int, int> &rhs) {
            return (lhs.second - lhs.first) < (rhs.second - rhs.first);
        });

        fill(tree.begin(), tree.begin() + tn * 4, 0);

        int answer = 0;
        for (auto &pos: people) {
            answer += ans(0, 0, tn, pos.first, pos.second + 1);
            update(0, 0, tn, pos.second, pos.second + 1, 1);
        }

        cout << answer << '\n';
    }

    return 0;
}