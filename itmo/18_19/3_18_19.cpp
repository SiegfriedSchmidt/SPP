// 
// 08.03.2024

#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define int long long

// 𝐹1 =((𝑋0 𝑥𝑜𝑟 𝑋1)→𝑋2) ⋁ ((𝑋3 𝑥𝑜𝑟 𝑋4)→𝑋5) ⋁ ((𝑋6 𝑥𝑜𝑟 𝑋7)→𝑋2)
bool func1(const vector<bool> &x) {
    return ((x[0] ^ x[1]) <= x[2]) || ((x[3] ^ x[4]) <= !x[5]) || ((x[6] ^ x[7]) <= x[2]);
}

// 𝐹2 =((𝑋0 𝑥𝑜𝑟 𝑋5)→𝑋7) ⋁ ((𝑋1 𝑥𝑜𝑟 𝑋4)→𝑋6) ⋁ ((𝑋3 𝑥𝑜𝑟 𝑋4)→𝑋2)
bool func2(const vector<bool> &x) {
    return ((x[0] ^ x[5]) <= !x[7]) || ((x[1] ^ x[4]) <= x[6]) || ((x[3] ^ x[4]) <= x[2]);
}

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    for (int N = 0; N < (1ll << 8); ++N) {
        vector<bool> x;
        for (int i = 0; i < 8; ++i) {
            x.emplace_back(N & (1ll << i));
        }

        if (!func1(x) && !func2(x)) {
            cout << N << '\n';
        }
    }

    return 0;
}
