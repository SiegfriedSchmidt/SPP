// https://codeforces.com/gym/104174/problem/C
// 03.02.2024

#include <iostream>
#include <vector>

using namespace std;

#define int long long
string ans;
vector<int> positions[26];

void func(int l, int r) {
    if (l >= r) {
        return;
    }

    for (int idx = 0; idx < 26; ++idx) {
        vector<int> &pos = positions[idx];

        if (pos.empty()) {
            continue;
        }

        int l2 = 0, r2 = pos.size();

        while (l2 + 1 < r2) {
            int mid = (l2 + r2) / 2;
            if (pos[mid] < r) {
                l2 = mid;
            } else {
                r2 = mid;
            }
        }
        if (pos[l2] >= l && pos[l2] < r) {
            ans += ('a' + idx);
            func(l, pos[l2]);
            func(pos[l2] + 1, r);
            break;
        }
    }
}

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); ++i) {
        positions[s[i] - 'a'].emplace_back(i);
    }

    func(0, s.size());
    cout << ans;

    return 0;
}
