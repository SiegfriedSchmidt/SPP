// https://codeforces.com/problemset/problem/1838/C
// 29.02.2024

#include <iostream>

using namespace std;

#define int long long

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;


        if (n % 2 == 1) {
            for (int i = 0; i < n; i += 2) {
                for (int j = 0; j < m; ++j) {
                    cout << (i * m + 1) + j << ' ';
                }
                cout << '\n';
            }
            for (int i = 1; i < n; i += 2) {
                for (int j = 0; j < m; ++j) {
                    cout << (i * m + 1) + j << ' ';
                }
                cout << '\n';
            }
        } else {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << j * n + 1 + i << ' ';
                }
                 cout << '\n';
            }
        }

        cout << '\n';
    }

    return 0;
}

/*
1 2 3 4
9 10 11 12
5 6 7 8
13 14 15 16

1 2 3 4 5
1 3 5 2 4


 */