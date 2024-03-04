//  
// 03.03.2024

#include <iostream>

using namespace std;

#define int long long

bool A(int x, int y, int z) {
    return ((x && y) <= z) == (!x <= (y && z));
}

bool B(int x, int y, int z) {
    return ((y && z) <= x) == (!y <= (x && z));
}

bool C(int x, int y, int z) {
    return ((x && z) <= y) == (!z <= (x && y));
}

bool f(int x, int y, int z) {
    return x && (z <= y) || z && (x <= y);
}

bool f_m(int a, int b, int c) {
    return c || a && !b;
}


signed main() {

    for (int x = 0; x < 2; ++x) {
        for (int y = 0; y < 2; ++y) {
            for (int z = 0; z < 2; ++z) {
                cout << A(x, y, z) << B(x, y, z) << C(x, y, z) << f(x, y, z) << f_m(A(x, y, z), B(x, y, z), C(x, y, z))
                     << '\n';
            }
        }
    }

    return 0;
}

