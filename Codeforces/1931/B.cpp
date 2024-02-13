//
// 13.02.2024

#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define int long long

const int MAXA = 1e6 + 1;

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int a[n];
        int s = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            s += a[i];
        }

        int tar = s / n;
        int free = 0;
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] < tar) {
                free -= (tar - a[i]);
                if (free < 0) {
                    flag = false;
                    break;
                }
            } else {
                free += (a[i] - tar);
            }
        }

        cout << ((flag && free == 0) ? "YES" : "NO") << '\n';



    }

    return 0;
}

