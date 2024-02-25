//  
// 24.02.2024

#include <iostream>

using namespace std;

#define int long long

signed main() {
    for (int X = 1; X < 2000; ++X) {
        for (int Y = 1; Y < 2000; ++Y) {
            int T[4] = {7, X, Y, 23023};
            int R = T[0];
            int i = 1;
            while (i < 4) {
                if (T[i] % R == 0) {
                    R = T[i];
                } else {
                    goto label;
                }
                i = i + 1;
            }
            label:
            if (R == 23023) {
                cout << X << ' ' << Y << '\n';
            }
        }
    }
    return 0;
}