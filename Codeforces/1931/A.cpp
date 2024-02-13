//
// 13.02.2024

#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define int long long

const int MAXA = 1e6 + 1;

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string ans = "zzz";
        for (char i = 'a'; i <= 'z'; ++i) {
            for (char j = 'a'; j <= 'z'; ++j) {
                for (char k = 'a'; k <= 'z'; ++k) {
                    if (i - 'a' + j - 'a' + k - 'a' + 3 == n) {
                        string s;
                        s += i;
                        s += j;
                        s += k;
                        ans = min(ans, s);
                    }
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}

