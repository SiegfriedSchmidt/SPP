// https://codeforces.com/gym/104174/problem/C
// 03.02.2024

#include <iostream>

using namespace std;

//#define int long long
const int MAXN = 200001;

string s;
string answer;
int n;

pair<char, int> tree[MAXN * 4];

void build(int ver, int tl, int tr) {
    if (tr - tl == 1) {
        tree[ver].first = s[tl];
        tree[ver].second = tl;
        return;
    }

    int mid = (tl + tr) / 2;
    build(ver * 2 + 1, tl, mid);
    build(ver * 2 + 2, mid, tr);
    tree[ver].first = min(tree[ver * 2 + 1].first, tree[ver * 2 + 2].first);
    if (tree[ver * 2 + 1].first == tree[ver * 2 + 2].first) {
        tree[ver].second = max(tree[ver * 2 + 1].second, tree[ver * 2 + 2].second);
    } else {
        if (tree[ver * 2 + 1].first == tree[ver].first) {
            tree[ver].second = tree[ver * 2 + 1].second;
        } else {
            tree[ver].second = tree[ver * 2 + 2].second;
        }
    }
}

pair<char, int> ans(int ver, int tl, int tr, int l, int r) {
    if (tl >= r || tr <= l) {
        return {100, 100};
    }

    if (tl >= l && tr <= r) {
        return tree[ver];
    }

    int mid = (tl + tr) / 2;
    pair<int, int> ans1;
    pair<int, int> ansl = ans(ver * 2 + 1, tl, mid, l, r);
    pair<int, int> ansr = ans(ver * 2 + 2, mid, tr, l, r);
    ans1.first = min(ansl.first, ansr.first);
    if (ansl.first == ansr.first) {
        ans1.second = max(ansl.second, ansr.second);
    } else {
        if (ansl.first == ans1.first) {
            ans1.second = ansl.second;
        } else {
            ans1.second = ansr.second;
        }
    }
    return ans1;
}

void func(int l, int r) {
    if (l >= r) {
        return;
    }
    pair<char, int> ans1 = ans(0, 0, n, l, r);
    answer += ans1.first;
    func(l, ans1.second);
    func(ans1.second + 1, r);
}

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> s;

    n = s.size();
    build(0, 0, n);
    func(0, n);
    cout << answer;

    return 0;
}
