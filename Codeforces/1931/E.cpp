//
// 13.02.2024

#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

#define int long long

const int MAXN = 2 * 1e5 + 1;

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        int cnt[n];
        fill(cnt, cnt + n, 0);
        int all_cnt = 0;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            int c = 0;
            int j = s.size() - 1;
            while (j >= 0 && s[j] == '0') {
                ++c;
                --j;
            }

            cnt[i] = c;
            all_cnt += s.size();
        }

        sort(cnt, cnt + n);
        reverse(cnt, cnt + n);

        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                all_cnt -= cnt[i];
            }
        }


        cout << ((all_cnt >= (m + 1)) ? "Sasha" : "Anna") << '\n';


    }

    return 0;
}

