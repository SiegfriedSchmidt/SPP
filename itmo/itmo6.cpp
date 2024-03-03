#include <bitset>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long


signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    for (int x = 285197364; x <= 285197364; ++x) {
        int N = x;
        int R = 0, k = 0, L = 10;
        while (k < 9) {
            int m = 0, s = 0;
            int t = 0;
            while (s < 9) {
                int z = N / (int)(pow(10, s)) % 10;
                if (z > m && z < L) {
                    m = z;
                    t = s;
                }
                ++s;
            }
            if (m > 0) {
                R = R * 10 + t;
                ++k;
                L = m;
            } else {
                break;
            }
        }

        if (R == 473160285) {
            cout << x << '\n';
            break;
        }
    }

    return 0;
}
