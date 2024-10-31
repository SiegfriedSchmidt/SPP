//  
// 15.04.2024

#include <bits/stdc++.h>

using namespace std;

#define int long long

int divs(int x) {
    int cnt = 0;
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            if (i % 2 != 0) {
                ++cnt;
            }
            if (i != x / i and (x / i) % 2 != 0) {
                ++cnt;
            }
        }
    }
    return cnt;
}


signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t = chrono::steady_clock::now().time_since_epoch().count();
    for (int i = 45'000'000; i <= 50'000'000; ++i) {
        if (divs(i) == 5) {
            cout << i << endl;
        }
    }
    cout << chrono::steady_clock::now().time_since_epoch().count() - t;

    return 0;
}
