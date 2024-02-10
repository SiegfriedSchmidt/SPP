// https://codeforces.com/gym/104964/problem/A
// 08.02.2024.

#include <iostream>

using namespace std;

signed main() {
    int t;
    int ar[3];
    cin >> t >> ar[0] >> ar[1] >> ar[2];
    sort(ar, ar + 3);
    reverse(ar, ar + 3);
    if ((ar[0] + ar[1] + ar[2]) % 3 != 0) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    int tar = (ar[0] + ar[1] + ar[2]) / 3;
    cout << max(abs(ar[0] - tar), abs(ar[2] - tar)) << '\n';

    if (t == 1) {
        for (int i = 0; i < min(abs(ar[0] - tar), abs(ar[2] - tar)); ++i) {
            cout << ar[2] + i << ' ' << ar[0] - i << '\n';
        }

        if (ar[0] - min(abs(ar[0] - tar), abs(ar[2] - tar)) == tar) {
            for (int i = 0;
                 i < max(abs(ar[0] - tar), abs(ar[2] - tar)) - min(abs(ar[0] - tar), abs(ar[2] - tar)); ++i) {
                cout << ar[2] + min(abs(ar[0] - tar), abs(ar[2] - tar)) + i << ' ' << ar[1] - i << '\n';
            }
        } else {
            for (int i = 0;
                 i < max(abs(ar[0] - tar), abs(ar[2] - tar)) - min(abs(ar[0] - tar), abs(ar[2] - tar)); ++i) {
                cout << ar[1] + i << ' ' << ar[0] - min(abs(ar[0] - tar), abs(ar[2] - tar)) - i << '\n';
            }
        }
    }
    return 0;
}