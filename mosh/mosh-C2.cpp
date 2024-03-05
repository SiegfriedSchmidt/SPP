//
// 05.03.2024

#include <iostream>
#include <vector>

using namespace std;

#define int long long
const int MAXV = 1e6;
int dp_neg[MAXV];
int dp_pos[MAXV];

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
        vector<pair<int, int>> diff_neg;
        vector<pair<int, int>> diff_pos;

        fill(dp_neg, dp_neg + MAXV, 0);
        fill(dp_pos, dp_pos + MAXV, 0);

        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
        }

        for (int i = 0; i < n; ++i) {
            cin >> a[i].second;
            if (a[i].first - a[i].second >= 0) {
                diff_pos.emplace_back(a[i].first - a[i].second, a[i].first + a[i].second);
            } else {
                diff_neg.emplace_back(abs(a[i].first - a[i].second), a[i].first + a[i].second);
            }
        }

        for (int j = 0; j < diff_pos.size(); ++j) {
            for (int i = MAXV - 1; i >= 0; --i) {
                if (i - diff_pos[j].first >= 0) {
                    if (dp_pos[i - diff_pos[j].first] > 0 || i - diff_pos[j].first == 0) {
                        dp_pos[i] = max(dp_pos[i], dp_pos[i - diff_pos[j].first] + diff_pos[j].second);
                    }
                }
            }
        }

        for (int j = 0; j < diff_neg.size(); ++j) {
            for (int i = MAXV - 1; i >= 0; --i) {
                if (i - diff_neg[j].first >= 0) {
                    if (dp_neg[i - diff_neg[j].first] > 0 || i - diff_neg[j].first == 0) {
                        dp_neg[i] = max(dp_neg[i], dp_neg[i - diff_neg[j].first] + diff_neg[j].second);
                    }
                }
            }
        }

        int mx = -1;
        for (int i = 0; i < MAXV; ++i) {
            if (dp_pos[i] > 0 && dp_neg[i] > 0) {
                mx = max(mx, dp_pos[i] + dp_neg[i]);
            }
        }

        cout << mx << '\n';
    }


    return 0;
}