//
// 05.03.2024

#include <iostream>
#include <vector>

using namespace std;

#define int long long

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    freopen("/mnt/d/Users/Matvei/Developer/Projects/SPP/mosh/tests/e2.txt", "r", stdin);
    freopen("/mnt/d/Users/Matvei/Developer/Projects/SPP/mosh/output.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;

        char mx = 'a';
        for (auto c: s1) {
            mx = max(mx, c);
        }

        cout << mx << ' ' << mx - 'a' << '\n';
        cout << "len1: " << s1.size() << '\n';
        cout << "len2: " << s2.size() << '\n';
    }

    return 0;
}
