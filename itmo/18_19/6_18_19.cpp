// 
// 08.03.2024

#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define int long long

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int r[5][7] = {
            {0, 0, 0, 0, 0, 0, 0},
            {1, 0, 0, 0, 0, 0, 1},
            {0, 1, 0, 0, 0, 1, 0},
            {0, 0, 1, 0, 1, 0, 0},
            {0, 0, 0, 1, 0, 0, 0}
    };

    int mas[5][7];
    for (int H_start = 1; H_start < 10000; ++H_start) {

        for (int x = 0; x < 5; ++x) {
            for (int y = 0; y < 7; ++y) {
                mas[x][y] = 0;
            }
        }

        int N = 5, k = 0, H = H_start * H_start;
        while (k < 7 && H > 0) {
            mas[H % N][k] = 1;
            H = H / N;
            k = k + 1;
        }

        bool flag = true;
        for (int x = 0; x < 5; ++x) {
            for (int y = 0; y < 7; ++y) {
                if (mas[x][y] != r[x][y]) {
                    flag = false;
                    break;
                }
            }
        }

        if (flag) {
            cout << H_start << '\n';
        }
    }

    return 0;
}
