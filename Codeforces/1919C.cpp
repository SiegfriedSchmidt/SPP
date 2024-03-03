// https://codeforces.com/problemset/problem/1919/C
// 27.02.2024

#include <iostream>
#include <array>

using namespace std;

#define int long long

const int MAXN = 1e5 + 1;
int a[MAXN];
array<pair<int, int>, MAXN * 4> tree;

void build(int v, int tl, int tr) {
    if (tr - tl == 1) {
        tree[tl] = {a[tl], tl};
        return;
    }

    int mid = (tl + tr) / 2;
    build(v * 2 + 1, tl, mid);
    build(v * 2 + 2, mid, tr);
    if (tree[v * 2 + 1].first == tree[v * 2 + 2].first) {
        tree[v] = tree[v * 2 + 2];
    } else {
        tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);
    }
}

pair<int, int> ans(int v, int tl, int tr, int l, int r, int val) {
    if (tl >= r || tr <= l) {
        return {-1, -1};
    }

    if (tr - tl == 1) {
        return tree[tl];
    }

    int mid = (tl + tr) / 2;
    int a1 = ans(v * 2 + 1, tl, mid, l, r, val);
    int a2 = ans(v * 2 + 2, mid, tr, l, r, val);
    if (a1 != -1) {
        return a1;
    }


    return -1;
}

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        build(0, 0, n);

        int dp[n];
        dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            int min_l = ans(0, 0, n, 0, i, a[i]);
            if (min_l == -1) {
                dp[i] = 1;
            } else {
                dp[i] = dp[min_l] + 1;
            }
        }

        cout << 1 << '\n';

    }

    return 0;
}

// 8 2 3 1 1 7 4 3
//
