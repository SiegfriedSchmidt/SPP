//
// 05.03.2024

#include <iostream>
#include <vector>

using namespace std;

#define int long long
const int MAXV = 1e6;
int dp_neg[MAXV];
int dp_pos[MAXV];
pair<int, int> pr_neg[MAXV];
pair<int, int> pr_pos[MAXV];

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    freopen("/mnt/d/Users/Matvei/Developer/Projects/SPP/mosh/tests/c0.txt", "r", stdin);
    freopen("/mnt/d/Users/Matvei/Developer/Projects/SPP/mosh/output.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        vector<pair<int, pair<int, int>>> diff_neg;
        vector<pair<int, pair<int, int>>> diff_pos;

        fill(dp_neg, dp_neg + MAXV, 0);
        fill(dp_pos, dp_pos + MAXV, 0);
        fill(pr_neg, pr_neg + MAXV, make_pair(-1, -1));
        fill(pr_pos, pr_pos + MAXV, make_pair(-1, -1));

        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
        }

        vector<int> equals;
        for (int i = 0; i < n; ++i) {
            cin >> a[i].second;
            if (a[i].first - a[i].second == 0) {
                equals.emplace_back(i);
            } else if (a[i].first - a[i].second > 0) {
                diff_pos.emplace_back(i, make_pair(a[i].first - a[i].second, a[i].first + a[i].second));
            } else {
                diff_neg.emplace_back(i, make_pair(abs(a[i].first - a[i].second), a[i].first + a[i].second));
            }
        }

        for (int j = 0; j < diff_pos.size(); ++j) {
            for (int i = MAXV - 1; i >= 0; --i) {
                if (i - diff_pos[j].second.first >= 0) {
                    if (dp_pos[i - diff_pos[j].second.first] > 0 || i - diff_pos[j].second.first == 0) {
                        int v = dp_pos[i - diff_pos[j].second.first] + diff_pos[j].second.second;
                        if (v > dp_pos[i]) {
                            dp_pos[i] = v;
                            pr_pos[i] = {i - diff_pos[j].second.first, diff_pos[j].first};
                        }
                    }
                }
            }
        }

        for (int j = 0; j < diff_neg.size(); ++j) {
            for (int i = MAXV - 1; i >= 0; --i) {
                if (i - diff_neg[j].second.first >= 0) {
                    if (dp_neg[i - diff_neg[j].second.first] > 0 || i - diff_neg[j].second.first == 0) {
                        int v = dp_neg[i - diff_neg[j].second.first] + diff_neg[j].second.second;
                        if (v > dp_neg[i]) {
                            dp_neg[i] = v;
                            pr_neg[i] = {i - diff_neg[j].second.first, diff_neg[j].first};
                        }
                    }
                }
            }
        }

        int mx = -1;
        int mx_idx = -1;
        for (int i = 0; i < MAXV; ++i) {
            if (dp_pos[i] > 0 && dp_neg[i] > 0) {
                int v = dp_pos[i] + dp_neg[i];
                if (v > mx) {
                    mx = v;
                    mx_idx = i;
                }
            }
        }

        vector<int> ans;

        int pr = mx_idx;
        cout << pr << '\n';
        while (pr != -1) {
            if (pr_pos[pr].first != -1) {
                cout << pr_pos[pr].first << ' ' << pr_pos[pr].second << '\n';
                ans.emplace_back(pr_pos[pr].second);
            }
            pr = pr_pos[pr].first;
        }

        pr = mx_idx;
        while (pr != -1) {
            if (pr_neg[pr].first != -1) {
                 ans.emplace_back(pr_neg[pr].second);
            }
            pr = pr_neg[pr].first;
        }

        for (auto eq: equals) {
            ans.emplace_back(eq);
        }

        for (auto val : ans) {
            cout << val + 1 << ' ';
        }

        for (auto eq: equals) {
            mx += a[eq].first + a[eq].second;
        }



//        cout << mx << '\n';
    }


    return 0;
}

/*
7610808
8092606
7712310
7720888
7973486
7661866
7006172
 */

/*
4
3 3
2 3
0 1
 */