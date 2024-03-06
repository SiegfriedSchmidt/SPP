// https://codeforces.com/problemset/problem/1907/B
// 06.03.2024

#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

#define int long long

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        stack<int> lower;
        stack<int> upper;
        set<int> deleted;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == 'b') {
                deleted.insert(i);
                if (!lower.empty()) {
                    deleted.insert(lower.top());
                    lower.pop();
                }
            } else if (c == 'B') {
                deleted.insert(i);
                if (!upper.empty()) {
                    deleted.insert(upper.top());
                    upper.pop();
                }
            } else {
                if (c >= 'a' && c <= 'z') {
                    lower.push(i);
                } else {
                    upper.push(i);
                }
            }
        }

        for (int i = 0; i < s.size(); ++i) {
            if (!deleted.contains(i)) {
                cout << s[i];
            }
        }

        cout << '\n';

    }

    return 0;
}