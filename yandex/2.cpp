//  
// 15.04.2024

#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string answer, seq;
    cin >> answer >> seq;

    string text;
    int cursor = 0;
    int start_cmd = -1;
    for (int i = 0; i < seq.size(); ++i) {
        if (seq[i] == '<') {
            start_cmd = i;
        } else if (seq[i] == '>') {
            string cmd = seq.substr(start_cmd + 1, i - start_cmd - 1);
            start_cmd = -1;
            if (cmd == "delete") {
                if (cursor < text.size()) {
                    text.erase(cursor, 1);
                }
            } else if (cmd == "bspace") {
                if (cursor > 0 && cursor - 1 < text.size()) {
                    --cursor;
                    text.erase(cursor, 1);
                }
            } else if (cmd == "left") {
                if (cursor > 0) {
                    --cursor;
                }
            } else if (cmd == "right") {
                if (cursor < text.size()) {
                    ++cursor;
                }
            }
        } else {
            if (start_cmd == -1) {
                text.insert(cursor, 1, seq[i]);
                ++cursor;
            }
        }
    }

    cout << (text == answer ? "YES" : "NO") << '\n';

    return 0;
}
