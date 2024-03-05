//
// 05.03.2024

#include <iostream>
#include <vector>

using namespace std;

#define int long long
const int MAXV = 1e6;
const int MAXN = 100;
int dp_neg[MAXV];
int dp_pos[MAXV];
int pr_neg[MAXV][100];
int pr_pos[MAXV][100];

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

        for (int i = 0; i < MAXV; ++i) {
            dp_neg[i] = 0;
            dp_pos[i] = 0;
            for (int j = 0; j < MAXN; ++j) {
                pr_neg[i][j] = -1;
                pr_pos[i][j] = -1;
            }
        }

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
                            pr_pos[i][j] = i - diff_pos[j].second.first;
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
                            pr_neg[i][j] = i - diff_neg[j].second.first;
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
        for (int j = MAXN - 1; j >= 0; --j) {
            if (pr_pos[pr][j] != -1) {
                ans.emplace_back(diff_pos[j].first);
                pr = pr_pos[pr][j];
            }
        }

        pr = mx_idx;
        for (int j = MAXN - 1; j >= 0; --j) {
            if (pr_neg[pr][j] != -1) {
                ans.emplace_back(diff_neg[j].first);
                pr = pr_neg[pr][j];
            }
        }

        for (auto eq: equals) {
            ans.emplace_back(eq);
        }

        sort(ans.begin(), ans.end());

        cout << ans.size() << '\n';

        for (auto val: ans) {
            cout << val + 1 << ' ';
        }

        int ans_sum = 0;
        for (auto val: ans) {
            ans_sum += a[val].first + a[val].second;
        }

        for (auto eq: equals) {
            mx += a[eq].first + a[eq].second;
        }

        cout << '\n' << ans_sum << ' ' << mx << '\n';
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