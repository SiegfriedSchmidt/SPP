//
// 05.03.2024

#include <iostream>
#include <vector>

using namespace std;

#define int long long

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    freopen("/mnt/d/Users/Matvei/Developer/Projects/SPP/mosh/tests/c1.txt", "r", stdin);
    freopen("/mnt/d/Users/Matvei/Developer/Projects/SPP/mosh/output.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
        }

        for (int i = 0; i < n; ++i) {
            cin >> a[i].second;
        }


        int ans_max = -1;
        vector<int> ans;
        for (int i = 0; i < (1ll << n); ++i) {
            int s1 = 0, s2 = 0;
            for (int j = 0; j < n; ++j) {
                if ((1ll << j) & i) {
                    s1 += a[j].first;
                    s2 += a[j].second;
                }
            }
            if (s1 == s2) {
                if (s1 > ans_max) {
                    ans_max = s1;
                    ans.clear();
                    for (int j = 0; j < n; ++j) {
                        if ((1ll << j) & i) {
                             ans.emplace_back(j);
                        }
                    }
                }
            }
        }

//        cout << ans.size() << '\n';
        int sm = 0;
        for (auto val : ans) {
//            cout << val + 1 << ' ';
            sm += a[val].first + a[val].second;
        }
        cout << sm;
        cout << '\n';
    }


    return 0;
}