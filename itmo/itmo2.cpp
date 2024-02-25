// 
// 24.02.2024

#include <iostream>
#include <cmath>

using namespace std;

#define int long long

int func2(int x0, int x1, int x2, int x3) {
    return (x0 || x1 && x2) && (x1 || x2 && x3) && (x2 || x3 && x0);
}

bitset<16> func(int N) {
    bitset<64> b(N);
    bitset<16> b2;
    for (int i = 0; i < 64; i += 4) {
        b2[i / 4] = func2(b[i], b[i + 1], b[i + 2], b[i + 3]);
    }

    return b2;
}

signed main() {
    cout << func(18364758544493064720).to_string();

    return 0;
}
