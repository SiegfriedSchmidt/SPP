// https://codeforces.com/contest/1905/problem/C
// 20.02.2024

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
        int n;
        cin >> n;

        char a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        bool flag1 = true;
        for (int i = 0; i + 1 < n; ++i) {
            if (a[i] > a[i + 1]) {
                flag1 = false;
                break;
            }
        }
        if (flag1) {
            cout << "0\n";
            continue;
        }

        pair<char, int> pref_mx[n];
        pref_mx[n - 1] = {a[n - 1], n - 1};
        for (int i = n - 1; i - 1 >= 0; --i) {
            if (a[i - 1] >= pref_mx[i].first) {
                pref_mx[i - 1] = {a[i - 1], i - 1};
            } else {
                pref_mx[i - 1] = pref_mx[i];
            }
        }

        int idx = pref_mx[0].second;

        vector<int> seq;
        while (idx < n) {
            seq.emplace_back(idx);
            if (idx + 1 >= n) {
                break;
            }
            idx = pref_mx[idx + 1].second;
        }

        int m = seq.size();
        int ans = 0;
        int cnt = 0;
        idx = 0;
        while (idx < m && a[seq[0]] == a[seq[idx]]) {
            ++cnt;
            ++idx;
        }
        ans = m - cnt;


        for (int i = 0; i < m / 2; ++i) {
            swap(a[seq[i]], a[seq[m - i - 1]]);
        }

        bool flag = true;
        for (int i = 0; i + 1 < n; ++i) {
            if (a[i] > a[i + 1]) {
                flag = false;
                break;
            }
        }

        if (!flag) {
            ans = -1;
        }
        cout << ans << '\n';
    }
    return 0;
}

/*
1
6
aacdcc


 */