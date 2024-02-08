// https://codeforces.com/contest/1927/problem/A
// 07.02.2024

#include <iostream>
#include <vector>

using namespace std;

#define int long long

const int MAXN = 200001;

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int l = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'B') {
                l = i;
                break;
            }
        }

        int r = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == 'B') {
                r = i;
                break;
            }
        }

        if (l == -1) {
            cout << "0\n";
        } else {
            cout << (r - l + 1) << '\n';
        }
    }

    return 0;
}

