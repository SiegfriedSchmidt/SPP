// https://codeforces.com/problemset/problem/1883/B
// 22.02.2024

#include <iostream>
#include <bitset>
#include <cmath>
#include <map>

using namespace std;

#define int long long


signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        map<char, int> map1;
        for (int i = 0; i < n; ++i) {
            map1[s[i]]++;
        }

        int x = 0;
        for (auto [a, b] : map1) {
            if (b % 2 == 1) {
                x += 1;
            }
        }

        if (x <= k + 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
