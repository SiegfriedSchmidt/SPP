//  
// 15.04.2024

#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string name;
    cin >> name;

    bool digit = false, upper = false, lower = false;

    for (char c: name) {
        if (c >= 'a' && c <= 'z') {
            lower = true;
        } else if (c >= 'A' && c <= 'Z') {
            upper = true;
        } else if (c >= '0' && c <= '9') {
            digit = true;
        }
    }

    cout << ((name.size() >= 8 && lower && upper && digit) ? "YES" : "NO") << '\n';

    return 0;
}
