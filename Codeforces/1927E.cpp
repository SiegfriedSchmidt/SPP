// https://codeforces.com/contest/1927/problem/E
// 08.02.2024

#include <iostream>
#include <vector>

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

//        vector<int> a = {1, 10, 2, 9, 3, 8, 4, 7, 5, 6};
//        vector<int> a = {1, 8, 4, 10, 2, 7, 5, 9, 3, 6};
//        vector<int> a = {1, 10, 4, 7, 2, 9, 5, 6, 3, 8};
        vector<int> a(n);
        int l = 1, r = n;
        bool flag = true;
        for (int i = 0; i < k; ++i) {
            if (flag) {
                for (int j = 0; i + j < n; j += k) {
                    a[i + j] = l++;
                }
            } else {
                for (int j = 0; i + j < n; j += k) {
                    a[i + j] = r--;
                }
            }
            flag = !flag;
        }
        for (auto a1 : a) {
            cout << a1 << ' ';
        }
        cout << '\n';
//        cout << '\n';
//        for (int i = 0; i + k <= n; ++i) {
//            int s = 0;
//            for (int j = 0; j < k; ++j) {
//                s += a[i + j];
//            }
//            cout << s << ' ';
//        }
//
//        cout << "\n\n";
    }


    return 0;
}
