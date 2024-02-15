//
// 15.02.2024

#include <iostream>
#include <vector>
#include <map>
#include <numeric>

using namespace std;

#define int long long

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int k, x, a;
        cin >> k >> x >> a;

        int lost = 0;
            int s = 0;
            bool win = true;
            for (int i = 0; i < x; ++i) {

                int l = 0, r = 1e9;
                while (l + 1 < r) {
                    int mid = (l + r) / 2;
                    if (mid * (k - 1) <= lost) {
                        l = mid;
                    } else {
                        r = mid;
                    }
                }
                if (r * (k - 1) <= lost) {
                    win = false;
                    break;
                }
                s = r;

                lost += s;
//                cout << s << ' ' << lost << '\n';
            }
            if (win) {
//                cout << (a - lost) * k << '\n';
                if ((a - lost) * k > a) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }

            } else {
                cout << "NO\n";
            }

//        if (k <= x) {
//
//        } else {
//            if (a <= x) {
//                cout << "NO\n";
//            } else {
//                cout << "YES\n";
//            }
//        }
    }

    return 0;
}

/*
1
25 69 231
 */
